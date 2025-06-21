#include "VideoWidget.h"
#include <QVBoxLayout>
#include <QImage>

VideoWidget::VideoWidget(QWidget* parent): QWidget(parent), cap(0){
    if (!cap.isOpened()){
        throw std::runtime_error("Failed to open webcam");
    }
    
    // Sets up non-editable contents
    label = new QLabel("Starting camera ...", this);
    label->setFixedSize(1040, 720);

    // Sets the vertical layout of the widget(the app window in this case)
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    this->setLayout(layout);

    // Timer object for periodic updates of the application
    timer = new QTimer(this);
    this->connect(timer, &QTimer::timeout, this, &VideoWidget::updateFrame);
    timer->start(30);
};
void VideoWidget::updateFrame(){
    cv::Mat frame;
    cap >> frame;
 
    if (frame.empty())
        return ;

    // Flipping the image horizontally
    cv::flip(frame, frame, 1);

    // Setting up color type of the input stream
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    // Creating a QT readable image from OpenCV captured image.
    QImage image(
        frame.data,
        frame.cols,
        frame.rows,
        frame.step,
        QImage::Format_RGB888
    );
    
    // Converting to QPixmap since QLabel only accepts QPixmap object for presentation.
    QPixmap scaledPixmap = QPixmap::fromImage(image).scaled(
        label->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    );
    label->setPixmap(scaledPixmap);
};

#include <QVBoxLayout>
#include <QImage>
#include "VideoWidget.h"

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

    if (is_start_stream){
        cap >> frame;

        if (frame.empty())
            return ;

        // Flipping the image horizontally
        cv::flip(frame, frame, 1);

        if (is_apply_blur)
            cv::GaussianBlur(frame, frame, cv::Size(21, 21), 0);

        if (is_apply_background_blur)
            applyBackgroundBlur(frame);

        // Setting up color type of the input stream
        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    }
    else{
        // Create a single black frame to avoid unnecessary CV processing when the stream is disabled.
        frame = cv::Mat(label->height(), label->width(), CV_8UC3, cv::Scalar(0, 0, 0));
    }

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

void VideoWidget::toggleBlur(){
    is_apply_blur = !is_apply_blur;
};

void VideoWidget::toggleBackgroundBlur(){
    is_apply_background_blur = !is_apply_background_blur;
};

void VideoWidget::toggleVideoStream(){
    is_start_stream = !is_start_stream;  
};

void VideoWidget::applyBackgroundBlur(cv::Mat& frame){
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("assets/haarcascade_frontalface_default.xml"))
    {
        throw std::runtime_error("Error laoding Haar cascade file!");
        return;
    }

    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(frame, faces, 1.1, 4);

    cv::Mat mask = cv::Mat::zeros(frame.size(), CV_8UC1);
    for (const auto& face : faces) {
        cv::Point center(face.x + face.width / 2, face.y + face.height / 2);
        cv::Size axes(face.width / 2, face.height / 2);
        cv::ellipse(mask, center, axes, 0, 0, 360, cv::Scalar(255), cv::FILLED);
    }

    cv::Mat blurred;
    cv::GaussianBlur(frame, blurred, cv::Size(51, 51), 0);

    // Invert mask to blur background (i.e., NOT the face)
    cv::Mat background_mask;
    cv::bitwise_not(mask, background_mask);

    // Apply blurred background to the frame in-place
    blurred.copyTo(frame, background_mask);
};
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "StreamingPage.h"

StreamingPage::StreamingPage(QWidget* parent): QWidget(parent){
    // Adding video stream
    video_widget = new VideoWidget;

    // Adding buttons
    QPushButton* button_toggle_video_stream = new QPushButton("Start/Stop Video");
    QPushButton* button_all_blur = new QPushButton("Blur");
    QPushButton* button_background_blur = new QPushButton("Background Blur");

    // Adding widgets to the layout
    QVBoxLayout* v_layout = new QVBoxLayout;
    v_layout->addWidget(video_widget);

    QHBoxLayout* h_layout = new QHBoxLayout;
    h_layout->addWidget(button_all_blur);
    h_layout->addWidget(button_background_blur);
    h_layout->addWidget(button_toggle_video_stream);

    v_layout->addLayout(h_layout);

    setLayout(v_layout);

    // connect button clicks to signals and slots.
    connect(button_all_blur, &QPushButton::clicked, video_widget, &VideoWidget::toggleBlur);
    connect(button_background_blur, &QPushButton::clicked, video_widget, &VideoWidget::toggleBackgroundBlur);
    connect(button_toggle_video_stream, &QPushButton::clicked, video_widget, &VideoWidget::toggleVideoStream);
};
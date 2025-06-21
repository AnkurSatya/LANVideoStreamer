#include <QApplication>
#include <QStackedWidget>
#include "Landing.h"
#include "VideoWidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Stack to keep a track of the pages in the application
    QStackedWidget* widget_stack = new QStackedWidget;
    // Creating all the pages
    LandingPage* landing = new LandingPage(widget_stack);
    VideoWidget* video_widget = new VideoWidget();
    //Add all the app pages to the stack
    widget_stack->addWidget(landing);
    widget_stack->addWidget(video_widget);

    // Connect the signals from LandingPage to change the widget
    QObject::connect(landing, &LandingPage::goToStreamingWindow, [=](){
        widget_stack->setCurrentWidget(video_widget);
    });
    QObject::connect(landing, &LandingPage::exitApplication, [=](){
        QApplication::quit();
    });

    widget_stack->setCurrentWidget(landing);
    widget_stack->setWindowTitle("Video Streamer");
    widget_stack->setFixedSize(1040, 720);
    widget_stack->show();

    return app.exec();
}
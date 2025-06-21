#include <QApplication>
#include <QStackedWidget>
#include "LandingPage.h"
#include "StreamingPage.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Stack to keep a track of the pages in the application
    QStackedWidget* page_stack = new QStackedWidget;
    // Creating all the pages
    LandingPage* landing = new LandingPage;
    StreamingPage* streamer = new StreamingPage;
    //Add all the app pages to the stack
    page_stack->addWidget(landing);
    page_stack->addWidget(streamer);

    // Connect the signals from LandingPage to change the widget
    QObject::connect(landing, &LandingPage::goToStreamingWindow, [=](){
        page_stack->setCurrentWidget(streamer);
    });
    QObject::connect(landing, &LandingPage::exitApplication, [=](){
        QApplication::quit();
    });

    page_stack->setCurrentWidget(landing);
    page_stack->setWindowTitle("Video Streamer");
    page_stack->setFixedSize(1040, 720);
    page_stack->show();

    return app.exec();
}
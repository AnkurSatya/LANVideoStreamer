#include <QVBoxLayout>
#include "LandingPage.h"

LandingPage::LandingPage(QWidget* parent): QWidget(parent){
    // Adding buttons
    QPushButton* button_start_stream = new QPushButton("Join");
    QPushButton* button_exit_app = new QPushButton("Exit");

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(button_start_stream);
    layout->addWidget(button_exit_app);
    
    setLayout(layout);

    // connect button clicks to signals and slots. These signals would then be listened to by the Application manager.
    connect(button_start_stream, &QPushButton::clicked, this, &LandingPage::goToStreamingWindow);
    connect(button_exit_app, &QPushButton::clicked, this, &LandingPage::exitApplication);
};
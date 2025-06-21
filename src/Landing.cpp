#include <QVBoxLayout>
#include <iostream>
#include "Landing.h"

LandingPage::LandingPage(QStackedWidget* widget_stack, QWidget* parent): 
    QWidget(parent),
    widget_stack{widget_stack}
{
    // Adding buttons
    QPushButton* button_start_stream = new QPushButton("Join");
    QPushButton* button_exit_app = new QPushButton("Exit");

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(button_start_stream);
    layout->addWidget(button_exit_app);
    
    setLayout(layout);

    // connect button clicks to signals. These signals would then be listened to by the Application manager.
    connect(button_start_stream, &QPushButton::clicked, this, &LandingPage::goToStreamingWindow);
    connect(button_exit_app, &QPushButton::clicked, this, &LandingPage::exitApplication);
};
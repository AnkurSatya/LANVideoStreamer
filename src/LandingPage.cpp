#include <QVBoxLayout>
#include <iostream>
#include "LandingPage.h"
#include "server.h"
#include "client.h"
#include <sys/socket.h>


LandingPage::LandingPage(QWidget* parent): QWidget(parent){
    // Setting the layout
    QPushButton* button_start_stream = new QPushButton("Start a meeting");
    QPushButton* button_join_stream = new QPushButton("Join a meeting");
    QPushButton* button_exit_app = new QPushButton("Exit");

    QHBoxLayout* h_layout = new QHBoxLayout;
    h_layout->addWidget(button_start_stream);
    h_layout->addWidget(button_join_stream);

    QVBoxLayout* v_layout = new QVBoxLayout;
    v_layout->addLayout(h_layout);
    v_layout->addWidget(button_exit_app);
    
    setLayout(v_layout);

    // connect button clicks to signals and slots. These signals would then be listened to by the Application manager.
    connect(button_start_stream, &QPushButton::clicked, this, &LandingPage::startStream);
    connect(button_join_stream, &QPushButton::clicked, this, &LandingPage::joinStream);
    connect(button_exit_app, &QPushButton::clicked, this, &LandingPage::exitApplication);
};

void LandingPage::startStream(){
    VideoStreamServer* server = new VideoStreamServer;
    server->startServer();
    // std::cout<<"Stream started" <<std::endl;
    // int client_socket = accept(server->getServerSocket(), nullptr, nullptr);
    // char buffer[1024] = {0};
    // recv(client_socket, buffer, sizeof(buffer), 0);
    // std::cout << "Message from client: " << buffer << std::endl;
    // emit goToStreamingWindow();
};

void LandingPage::joinStream(){
    VideoStreamClient* client = new VideoStreamClient;
    client->connectToServer();
    // client->sendToServer();
};
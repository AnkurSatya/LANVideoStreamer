#include "client.h"

VideoStreamClient::VideoStreamClient(QObject* parent, QString hostAddress, quint16 port)
    : QObject(parent) ,
    hostAddress{hostAddress},
    port{port}
{
    // Initialise the socket
    socket = new QTcpSocket(this);

    // Connect socket signals to the slots
    connect(socket, &QTcpSocket::connected, this, &VideoStreamClient::onConnection);
    connect(socket, &QTcpSocket::disconnected, this, &VideoStreamClient::onDisconnection);


};

VideoStreamClient::~VideoStreamClient(){
    // close(client_socket);
};

void VideoStreamClient::connectToServer(){
    socket->connectToHost(hostAddress, port);
};

void VideoStreamClient::onConnection(){
    qDebug() << "Connected to server";
};

void VideoStreamClient::onDisconnection(){
    qDebug() << "Disconnect from the server";
};

void VideoStreamClient::sendToServer(){
    // const char* message = "Hello, server!";
    // std::cout<<"Sending message now ..."<<std::endl;
    // send(client_socket, message, strlen(message), 0);
};
#include "client.h"
#include <QCoreApplication>
#include <QImage>
#include <opencv2/opencv.hpp>

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
    connect(socket, &QTcpSocket::errorOccurred, this, &VideoStreamClient::onError);
};

VideoStreamClient::~VideoStreamClient(){
    // close(client_socket);
};

void VideoStreamClient::connectToServer(){
    socket->connectToHost(hostAddress, port);
};

void VideoStreamClient::onConnection(){
    qDebug() << "Connected to server";
    sendToServer();
};

void VideoStreamClient::onDisconnection(){
    qDebug() << "You are disconnected";
};

void VideoStreamClient::onError(QAbstractSocket::SocketError socketError){
    qDebug() << "Connection error: "<< socket->errorString();
};

void VideoStreamClient::sendToServer(){
    QString image_path = QCoreApplication::applicationDirPath() + "/data/client_placeholder.jpeg";
    cv::Mat img = cv::imread(image_path.toStdString(), cv::COLOR_BGR2RGB);
    
    // ToDo: Encode image, send the size and then the image bytes to the server over QTcpSocket.
};
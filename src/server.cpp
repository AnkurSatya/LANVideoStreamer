#include "server.h"
#include <QDebug>

VideoStreamServer::VideoStreamServer(QObject * parent, quint16 port) 
    : QObject{parent}, 
    port{port},
    server{new QTcpServer(this)}
{
    // Setting up slots and signals. QTcpServer uses QTcpServer::newConnection slot to notify
    // that a new Connection has been established.
    connect(server, &QTcpServer::newConnection, this, &VideoStreamServer::onNewConnection);
};

VideoStreamServer::~VideoStreamServer(){
    // close(server_socket);
};

bool VideoStreamServer::startServer(){
    if (!server->listen(QHostAddress::Any, port)){
        qCritical() << "Failed to start the server" << server->errorString();
        return false;
    }

    qDebug() << "Server started on the port "<< port;
    return true;
};

void VideoStreamServer::onNewConnection(){
    qDebug()<<"New connection request received";
    while (server->hasPendingConnections()){
        QTcpSocket* client_socket = server->nextPendingConnection();
        clients.append(client_socket);

        connect(client_socket, &QTcpSocket::disconnected, this, &VideoStreamServer::onClientDisconnected);
        qDebug() << "New client connected from " << client_socket->peerAddress().toString();

        emit clientConnected(client_socket);
    }
};

void VideoStreamServer::onClientDisconnected(){
};
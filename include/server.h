#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class VideoStreamServer : public QObject{
    Q_OBJECT
    public:
        VideoStreamServer(QObject * parent = nullptr, quint16 port=8080);
        ~VideoStreamServer();
        bool startServer();
    
    signals:
        void clientConnected(QTcpSocket* socket);

    private slots:
        void onNewConnection();
        void onClientDisconnected();
    private:
        QTcpServer* server;
        quint16 port;
        QList<QTcpSocket*> clients;
};
#include <QTcpSocket>
#include <QString>

class VideoStreamClient : public QObject{
    Q_OBJECT
    public:
        VideoStreamClient(QObject* parent = nullptr, QString hostAddress="127.0.0.1", quint16 port=8080);
        ~VideoStreamClient();
        void connectToServer();
        void sendToServer();
        void onConnection();
        void onDisconnection();
        void onError(QAbstractSocket::SocketError socketError);

    private:
        QTcpSocket* socket;
        QString hostAddress;
        quint16 port;
};
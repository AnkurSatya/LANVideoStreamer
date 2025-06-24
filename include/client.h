#include <QTcpSocket>
#include <QString>

class VideoStreamClient : public QObject{
    Q_OBJECT
    public:
        VideoStreamClient(QObject* parent = nullptr, const QString& hostAddress="127.0.0.1", quint16 port=8080);
        ~VideoStreamClient();
        void connectToServer();
        void sendToServer();
        void onConnection();
        void onDisconnection();

    private:
        QTcpSocket* socket;
        const QString& hostAddress;
        quint16 port;
};
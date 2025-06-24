#include <QWidget>
#include <QPushButton>

class LandingPage : public QWidget{
    Q_OBJECT

    public:
        LandingPage(QWidget* parent = nullptr);
        void startStream();
        void joinStream();

    signals:
        void goToStreamingWindow();
        void exitApplication();
};
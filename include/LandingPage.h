#include <QWidget>
#include <QPushButton>

class LandingPage : public QWidget{
    Q_OBJECT

    public:
        LandingPage(QWidget* parent = nullptr);

    signals:
        void goToStreamingWindow();
        void exitApplication();
};
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

class LandingPage : public QWidget{
    Q_OBJECT

    public:
        LandingPage(QStackedWidget* widget_stack, QWidget* parent = nullptr);

    signals:
        void goToStreamingWindow();
        void exitApplication();

    private:
        QStackedWidget* widget_stack;
};
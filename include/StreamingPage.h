#include <QPushButton>
#include "VideoWidget.h"

class StreamingPage : public QWidget{
    Q_OBJECT

    public:
        StreamingPage(QWidget* parent = nullptr);

    private slots:
        void toggleBlur();
        void toggleBackgroundBlur();

    private:
        VideoWidget* video_widget;       
};
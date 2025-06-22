#include <QPushButton>
#include "VideoWidget.h"

class StreamingPage : public QWidget{
    Q_OBJECT

    public:
        StreamingPage(QWidget* parent = nullptr);

    private:
        VideoWidget* video_widget;
};
#include <QApplication>
#include "VideoWidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    VideoWidget widget;
    widget.setWindowTitle("Qt + OpenCV Video Stream");
    widget.show();

    return app.exec();
}
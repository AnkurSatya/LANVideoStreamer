#pragma once

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <opencv2/opencv.hpp>


class VideoWidget : public QWidget{
    Q_OBJECT
    public:
        VideoWidget(QWidget* parent = nullptr);
        void toggleBlur();
        void toggleBackgroundBlur();

    private slots:
        void updateFrame();

    private:
        cv::VideoCapture cap;
        QLabel* label;
        QTimer* timer;

        // Video Stream modifications
        bool apply_blur;
        bool apply_background_blur;
};
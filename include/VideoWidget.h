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
        void toggleVideoStream();
        void applyBackgroundBlur(cv::Mat& frame);

    private slots:
        void updateFrame();

    private:
        cv::VideoCapture cap;
        QLabel* label;
        QTimer* timer;

        // Video Stream modifications
        bool is_apply_blur;
        bool is_apply_background_blur;
        bool is_start_stream = true;
};
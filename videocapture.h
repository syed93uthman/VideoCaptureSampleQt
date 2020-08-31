#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H
#include "qframe.h"
#include <QTimer>
#include <opencv2/opencv.hpp>

class videoCapture : public QFrame
{
public:
    videoCapture();

    void setMat(cv::Mat *img);
    bool startVideoCapture(int i);
    QPixmap stopVideoCapture();

    QPixmap getPixMap();
    QImage* getQImage();

    QStringList getCameraList();
    QPixmap updateImageCapture();


private:
    cv::Mat frame;
    cv::VideoCapture cap;
    QImage qimg;

};

#endif // VIDEOCAPTURE_H

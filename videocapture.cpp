#include "videocapture.h"

videoCapture::videoCapture()
{

}

void videoCapture::setMat(cv::Mat *img){
    QImage qimgInput((uchar*)img->data,img->cols,img->rows,img->step,QImage::Format_RGB888);
    qimg= qimgInput;
}

bool videoCapture::startVideoCapture(int i){
    cap.open(i);

    if(!cap.isOpened())  // Check if we succeeded
    {
        return false;
    }
    else
    {
        return true;
    }
}

QPixmap videoCapture::stopVideoCapture(){
    cv::Mat image = cv::Mat::zeros(frame.size(),CV_8UC3);
    qimg = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    return QPixmap::fromImage(qimg);
}

QStringList videoCapture::getCameraList(){
    QStringList capList;
    cv::VideoCapture tmpCap;
    for(int i = 0 ; i < 10 ;i++){
        tmpCap.open(i);
        if(!tmpCap.isOpened()){
        }
        else{
            capList<< QString("Camera ").append(QString::number(i));
            tmpCap.release();
        }

    }

    return capList;
}

QPixmap videoCapture::getPixMap(){
    return QPixmap::fromImage(qimg);
}

QImage* videoCapture::getQImage(){
    return &qimg;
}

QPixmap videoCapture::updateImageCapture(){
    cap >> frame;
    cvtColor(frame, frame, CV_BGR2RGB);
    qimg = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    return QPixmap::fromImage(qimg);
}

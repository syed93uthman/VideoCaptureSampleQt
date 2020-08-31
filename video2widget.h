#ifndef VIDEO2WIDGET_H
#define VIDEO2WIDGET_H

#include <QWidget>
#include <QTimer>
#include "videocapture.h"

namespace Ui {
class Video2Widget;
}

class Video2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Video2Widget(QWidget *parent = nullptr);
    ~Video2Widget();

    videoCapture video;

private slots:
    void on_startPushButton_clicked();
    void update_window();

private:
    bool cameraRunning = false;

    QImage *img;
    QTimer *timer;
    QStringList capList;
    Ui::Video2Widget *ui;
};

#endif // VIDEO2WIDGET_H

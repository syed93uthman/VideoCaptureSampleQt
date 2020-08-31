#ifndef VIDEO1WIDGET_H
#define VIDEO1WIDGET_H

#include <QWidget>
#include <QTimer>
#include "videocapture.h"

QT_BEGIN_NAMESPACE
namespace Ui {class Video1Widget;}
QT_END_NAMESPACE

class Video1Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Video1Widget(QWidget *parent = nullptr);
    ~Video1Widget();

    videoCapture video;

private slots:
    void on_startPushButton_clicked();
    void update_window();

private:
    bool cameraRunning = false;

    QImage *img;
    QTimer *timer;
    QStringList capList;
    Ui::Video1Widget *ui;
};

#endif // VIDEO1WIDGET_H

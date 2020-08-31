#include "video1widget.h"
#include "ui_video1widget.h"

#include <QMessageBox>

Video1Widget::Video1Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video1Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    capList = video.getCameraList();
    ui->capComboBox->addItems(capList);
}

Video1Widget::~Video1Widget()
{
    delete ui;
}

void Video1Widget::on_startPushButton_clicked()
{
    if(!cameraRunning){
        QString selectedCamString =  ui->capComboBox->currentText();
        selectedCamString.remove("Camera ");
        int selected = selectedCamString.toInt();
        if(selected == 0){
            QMessageBox::information(this,"Titile","Select number 0");
        }
        else if(selected == 2){
            QMessageBox::information(this,"Titile","Select number 2");
        }

        if(video.startVideoCapture(selected)){
            connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
            timer->start(30);
            ui->startPushButton->setText("STOP");
            cameraRunning = true;
        }
        else{
             ui->label->setText("Fail");
        }
    }
    else {
        ui->startPushButton->setText("START");
        disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        timer->stop();
        ui->label->setPixmap(video.stopVideoCapture());
        cameraRunning = false;
    }
}

void Video1Widget::update_window(){
    ui->label->setPixmap(video.updateImageCapture());
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     QPixmap bkgnd("C:/Users/Naidu/Downloads/qt5_application/image.jpeg");
     bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
     QPalette palette;
     palette.setBrush(QPalette::Background, bkgnd);
     this->setPalette(palette);
     readfile("C:/Users/Naidu/Desktop/QTC++");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readfile(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice:: Text))
    {
      qDebug()<< "IP Address Received";
        on_pushButton_clicked();
    }
    file.close();
}
void MainWindow::readfile2(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice:: Text))
    {
      qDebug()<< "Google  pinged";
        on_pushButton_2_clicked();
    }
    file.close();
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox:: about(this, "Current Status of Program", "IP Address Received");

}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox:: about(this, "Current Status of Program", "Google Ping Validated");

}



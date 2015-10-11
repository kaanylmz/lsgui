#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "apencere.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    apencere dialog;
    if (dialog.exec())
    {
        param << dialog.param;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray ba;
    QString program = "ls";

    QProcess myProcess(this);
    myProcess.start(program, param);

    if (myProcess.waitForStarted(-1)) {
        while(myProcess.waitForReadyRead(-1)) {
            ba += myProcess.readAllStandardOutput();
        }
    }

    ui->textBrowser->setText(ba.data());
    param.clear();

}

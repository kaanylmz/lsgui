#include "apencere.h"
#include "ui_apencere.h"

apencere::apencere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apencere)
{
    ui->setupUi(this);
}

apencere::~apencere()
{
    delete ui;
}

void apencere::on_pushButton_clicked()
{
    param = "";
    QList<QAbstractButton *> liste = ui->buttonGroup->buttons();

    for(int i=0;i<liste.size();i++){
        if(liste.at(i)->isChecked()){
            param += liste.at(i)->objectName().split(QRegExp("_")).at(1);
        }
    }
    if((param.size())>0){
        param = "-" + param;
    }

    this->accept();
}

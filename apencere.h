#ifndef APENCERE_H
#define APENCERE_H

#include <QDialog>
#include <QAbstractButton>
#include <QDebug>

namespace Ui {
class apencere;
}

class apencere : public QDialog
{
    Q_OBJECT

public:
    explicit apencere(QWidget *parent = 0);
    QString param;
    ~apencere();

private slots:
    void on_pushButton_clicked();

private:
    Ui::apencere *ui;
};

#endif // APENCERE_H

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dialog::accept);
}

Dialog::~Dialog()
{
    delete ui;
}



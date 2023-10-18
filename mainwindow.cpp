    #include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    gameWindow = new Form(ui->comboBox->currentText());
    gameWindow->show();
    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}


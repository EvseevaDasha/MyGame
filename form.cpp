#include "form.h"
#include "ui_form.h"
#include "skin.h"
#include <QDebug>

Form::Form(const QString& skinName) :
    QWidget(),
    ui(new Ui::Form),
    skinName(skinName)
{
    ui->setupUi(this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    resetScene();
}

Form::~Form()
{
    delete ui;
}

void Form::gameStopped() {
    dialog = new Dialog(this); 
    connect(dialog, &Dialog::accepted, this, &Form::restartGame);
    dialog->show();
}

void Form::restartGame() {
    resetScene();
}

void Form::resetScene() {
    scene = new Scene(this);
    connect(scene, &Scene::gameStopped, this, &Form::gameStopped);
    ui->graphicsView->setScene(scene);
    Skin skin(skinName);
    scene->AddCharacter(skin);
}

void Form::on_pushButton_clicked()
{
    close();
}


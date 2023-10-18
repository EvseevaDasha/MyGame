#ifndef FORM_H
#define FORM_H

#include "scene.h"
#include "dialog.h"
#include <QWidget>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(const QString& skinName);
    ~Form();

public slots:
    void gameStopped();
    void restartGame();

private:
    Ui::Form *ui;
    Scene *scene;
    Dialog* dialog;
    QString skinName;

    void resetScene();

private slots:
    void on_pushButton_clicked();
};

#endif // FORM_H

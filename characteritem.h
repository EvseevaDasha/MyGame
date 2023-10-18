#ifndef CHARACTERITEM_H
#define CHARACTERITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

#include "skin.h"

#define UPDATES 10


class characterItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit characterItem(const Skin& skin);

    void jump();
    void run();
    void freeze();

private:
    enum class State {
        Stop = 0,
        Run,
        Jump
    };
    State state = State::Stop;
    unsigned runningFrame = 0;

    const Skin skin;

    qreal vertSpeed = 0;
    qreal vertSpeed2 = 0;

private slots:
    void update();
};

#endif // CHARACTERITEM_H

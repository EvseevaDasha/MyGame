#include "characteritem.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>

characterItem::characterItem(const Skin& skin) : skin(skin)
{
    setPixmap(skin.getRunFrame(0));
    setPos(50, 400);

    QTimer *characterLegTimer = new QTimer(this);
    connect(characterLegTimer, &QTimer::timeout, this, &characterItem::update);
    characterLegTimer->start(1000 / UPDATES);
}

void characterItem::update()
{
    vertSpeed += vertSpeed2 / UPDATES;

    moveBy(0, vertSpeed);

    if (y() >= 400) {
        setY(400);
        vertSpeed2 = 0;
        vertSpeed = 0;
        state = State::Run;
    }
    if (y() <= 225) {
        vertSpeed2 = 200;
    }

    if (state == State::Run)
    {
        runningFrame = (runningFrame + 1) % 2;
        setPixmap(skin.getRunFrame(runningFrame));
    }
    else if (state == State::Jump)
    {
        setPixmap(skin.getJumpFrame());
    }
}

void characterItem::jump()
{
    if (state != State::Jump) {
        state = State::Jump;
        vertSpeed2 = -150;
    }
}

void characterItem::run()
{
    state = State::Run;
}

void characterItem::freeze()
{
    state = State::Stop;
}

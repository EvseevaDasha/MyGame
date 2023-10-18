#include "barrier.h"
#include "characteritem.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QGraphicsScene>
#include "scene.h"

Barrier::Barrier(int speed) : QGraphicsPixmapItem(), speed(speed)
{
    setPixmap(QPixmap(":/resources/cactuss.png"));
    setPos(1000, 425);

    QTimer* updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &Barrier::update);
    updateTimer->start(1000 / 100);
}

Barrier::~Barrier()
{

}

void Barrier::freezeInPlace()
{
    state = BarrierState::Frozen;
}

bool Barrier::collidesCharacter()
{
    foreach(QGraphicsItem * item, collidingItems()){
        characterItem * characterI = dynamic_cast<characterItem*>(item);
        if(characterI){
            return true;
        }
    }
    return false;
}

void Barrier::update() {
    if (state == BarrierState::Frozen) return;

    moveBy(speed, 0);

    if (collidesCharacter()) {
        dynamic_cast<Scene*>(scene())->stopGame();
        return;
    }

    if (x() < 50 && !pastCharacter) {
        pastCharacter = true;
        dynamic_cast<Scene*>(scene())->incrementScore();
    }
}



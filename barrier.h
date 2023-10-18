#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>


class Barrier : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Barrier(int speed);
    ~Barrier();

    void freezeInPlace();

private slots:
    void update();

private:
    enum class BarrierState {
        Running = 0,
        Frozen
    };

    BarrierState state = BarrierState::Running;
    bool collidesCharacter();
    bool pastCharacter = false;

    int speed;
};

#endif // BARRIER_H

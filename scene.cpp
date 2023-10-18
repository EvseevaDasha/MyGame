#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QAbstractButton>


Scene::Scene(QObject *parent): QGraphicsScene(parent), score()
{
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/resources/forest.png"));
    addItem(pixItem);

    barrierTimer = new QTimer(this);
    connect(barrierTimer, &QTimer::timeout, [=](){
        Barrier *barrier = new Barrier(-(speed));
        addItem(barrier);
    });

    QTimer* speedTimer = new QTimer(this);
    connect(speedTimer, &QTimer::timeout, [=](){
        speed += 0.1;
    });
    speedTimer->start(5000);
}

void Scene::AddCharacter(const Skin& skin)
{
    character = new characterItem(skin);
    addItem(character);
}

void Scene::startGame()
{
    character->run();
    gameState = GameState::Running;
    barrierTimer->start(1700);
    score = 0;
    createScoreTextItem();
}

void Scene::incrementScore()
{
    score++;
    scoreTextItem->setPlainText("Score: " + QString::number(score));
}

void Scene::createScoreTextItem()
{
    scoreTextItem = new QGraphicsTextItem();
    scoreTextItem->setPlainText("Score: 0");
    QFont mFont("consolas", 30, QFont::Bold);
    scoreTextItem->setFont(mFont);
    scoreTextItem->setDefaultTextColor(Qt::white);
    addItem(scoreTextItem);
    scoreTextItem->setPos(QPointF(700, 50));
}

void Scene::freeze()
{
    character->freeze();
    QList<QGraphicsItem*> sceneItems = items();
    foreach(QGraphicsItem *item, sceneItems){
        Barrier * barrier = dynamic_cast<Barrier*>(item);
        if(barrier){
            barrier->freezeInPlace();
        }
    }

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        if (gameState == GameState::Ready) {
            startGame();
        }
        else if (gameState == GameState::Running) {
            character->jump();
        }
    }
}

void Scene::stopGame() {
    barrierTimer->stop();
    freeze();
    gameState = GameState::Ended;
    emit gameStopped();
}

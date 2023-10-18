#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "barrier.h"
#include "characteritem.h"
#include "skin.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum class GameState {
        Ready = 0,
        Running,
        Ended
    };

    explicit Scene(QObject *parent = nullptr);
    void AddCharacter(const Skin& skin);

    void startGame();
    void stopGame();
    void incrementScore();

signals:
    void gameStopped();

public slots:
private:
    void createScoreTextItem();
    void freeze();
    QTimer *barrierTimer;
    characterItem *character;
    GameState gameState = GameState::Ready;
    int score;
    int speed = 7;
    QGraphicsTextItem *scoreTextItem;

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SCENE_H

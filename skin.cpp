#include "skin.h"


Skin::Skin(const QString& folder) {
    QString dir = ":/resources/" + folder + "/";
    runFrames << QPixmap(dir + "run0.png") << QPixmap(dir + "run1.png");
    jumpFrame = QPixmap(dir + "jump.png");
}

const QPixmap& Skin::getJumpFrame() const {
    return jumpFrame;
}

const QPixmap& Skin::getRunFrame(unsigned int i) const {
    return runFrames[i];
}

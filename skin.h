#ifndef KR_SKIN_H
#define KR_SKIN_H

#include <QString>
#include <QPixmap>


class Skin {
public:
    Skin(const QString& folder);

    const QPixmap& getJumpFrame() const;
    const QPixmap& getRunFrame(unsigned i) const;

private:
    QPixmap jumpFrame;
    QVector<QPixmap> runFrames;
};


#endif //KR_SKIN_H

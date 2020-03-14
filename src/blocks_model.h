#ifndef BLOCKSMODEL_H
#define BLOCKSMODEL_H

#include "game_level.h"
#include <QObject>

class BlocksModel : public QObject
{
    Q_OBJECT
public:
    BlocksModel(QObject *parent = nullptr): _level(GameLevel::Easy) {};
    ~BlocksModel() = default;

    void setLevel(const GameLevel& level){
        _level = level;
        emit levelChanged(_level);
        // Generate blocks in here and handle two states (in model and in view)?
    }

signals:
    void levelChanged(const GameLevel level);

private:
    GameLevel _level;
};

#endif // BLOCKSMODEL_H

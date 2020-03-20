#ifndef BLOCKSMODEL_H
#define BLOCKSMODEL_H

#include <QObject>
#include <memory>

#include "../game_level.h"
#include "../move_stack/move.h"
#include "../block/block.h"

class BlocksModel : public QObject
{
    Q_OBJECT
public:
    BlocksModel(QObject *parent = nullptr);
    virtual ~BlocksModel() = default;
    void print();

signals:
    void gameStarted(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& size);
    void levelChanged(const GameLevel level);
    void blockSwaped(Block& a, Block& b, const Move& move, bool undo);
    void puzzleSolved();

public slots:
    void setLevel(const GameLevel& level);
    void moveBlock(const Position& move);
    void undoMove(const Move& move);
    void start();

private:
    void isSolved();
    void swapBlock(const Move& move, bool undo = false);

    size_t _level;
    std::vector<std::shared_ptr<Block>> _blocks;
};

#endif // BLOCKSMODEL_H

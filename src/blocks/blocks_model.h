#ifndef BLOCKSMODEL_H
#define BLOCKSMODEL_H

#include <QObject>
#include <memory>

#include "../game_level.h"
#include "../move_stack/move.h"
#include "../block/block.h"
#include "../state_manager/state_manager_model.h"
#include "../block/block_layout_item.h"

class BlocksModel : public QObject
{
    Q_OBJECT
public:
    BlocksModel(QObject *parent = nullptr);
    virtual ~BlocksModel() = default;
    void print();

signals:
    void gameStarted(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    void gameRestored(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    void blocksUpdated(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks);
    void levelChanged(const GameLevel level);
    void blockSwaped(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    void puzzleSolved();

public slots:
    void setLevel(const GameLevel& level);
    void moveBlock(const Position& move);
    void undoMove(const std::shared_ptr<Move>& move);
    void start();
    void stateLoadedHandler(const LoadState& state);

private:
    void isSolved();
    void swapBlock(const std::shared_ptr<Move>& move, bool undo = false);

    size_t _level;
    std::vector<std::shared_ptr<Block<BlockLayoutItem>>> _blocks;
};

#endif // BLOCKSMODEL_H

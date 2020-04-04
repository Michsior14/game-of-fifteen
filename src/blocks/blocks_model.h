#ifndef BLOCKSMODEL_H
#define BLOCKSMODEL_H

#include <QObject>
#include <memory>

#include "../game_level.h"
#include "../move_stack/move.h"
#include "../block/block.h"
#include "../state_manager/state_manager_model.h"
#include "../block/block_layout_item.h"

/**
 * @brief
 *
 */
class BlocksModel : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    BlocksModel(QObject *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~BlocksModel() = default;
    /**
     * @brief
     *
     */
    void print();

signals:
    /**
     * @brief
     *
     * @param blocks
     * @param size
     */
    void gameStarted(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    /**
     * @brief
     *
     * @param blocks
     * @param size
     */
    void gameRestored(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    /**
     * @brief
     *
     * @param blocks
     */
    void blocksUpdated(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks);
    /**
     * @brief
     *
     * @param level
     */
    void levelChanged(const GameLevel level);
    /**
     * @brief
     *
     * @param a
     * @param b
     * @param move
     * @param undo
     */
    void blockSwaped(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    /**
     * @brief
     *
     */
    void puzzleSolved();

public slots:
    /**
     * @brief
     *
     * @param level
     */
    void setLevel(const GameLevel& level);
    /**
     * @brief
     *
     * @param move
     */
    void moveBlock(const Position& move);
    /**
     * @brief
     *
     * @param move
     */
    void undoMove(const std::shared_ptr<Move>& move);
    /**
     * @brief
     *
     */
    void restart();
    /**
     * @brief
     *
     * @param level
     */
    void start(const GameLevel& level);
    /**
     * @brief
     *
     * @param state
     */
    void stateLoadedHandler(const LoadState& state);

private:
    /**
     * @brief
     *
     */
    void isSolved();
    /**
     * @brief
     *
     * @param move
     * @param undo
     */
    void swapBlock(const std::shared_ptr<Move>& move, bool undo = false);

    size_t _level; /**< TODO: describe */
    std::vector<std::shared_ptr<Block<BlockLayoutItem>>> _blocks; /**< TODO: describe */
};

#endif // BLOCKSMODEL_H

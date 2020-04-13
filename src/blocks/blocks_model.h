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
 * @brief The model responsible for Blocks logic.
 * Handles all movements on the board.
 *
 */
class BlocksModel : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates the model.
     *
     * @param parent The Qt's parent object.
     */
    BlocksModel(QObject *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~BlocksModel() = default;
    /**
     * @brief Prints the current state of the board.
     *
     */
    void print();

signals:
    /**
     * @brief Emitted when new game has been started.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     * @param size The edge size of a board (i.e. 4 in case of board created for 16 blocks)
     */
    void gameStarted(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    /**
     * @brief Emitted when game board has been restored.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     * @param size The edge size of a board (i.e. 4 in case of board created for 16 blocks)
     */
    void gameRestored(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    /**
     * @brief Emitted whenever the position of one of the blocks has changed.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     */
    void blocksUpdated(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks);
    /**
     * @brief Emitted whenever the current game level has changed.
     *
     * @param level The game level that has been choosen.
     */
    void levelChanged(const GameLevel level);
    /**
     * @brief Emitted when pair of the blocks has switched their positions on the board.
     *
     * @param a The first Block that changed the placement.
     * @param b The second Block that changed the placement.
     * @param move Describes the move that happend on the board (how positions changed).
     * @param undo Indicates if it is an undo action.
     */
    void blockSwaped(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    /**
     * @brief Informes if the board has been solved.
     *
     */
    void puzzleSolved();

public slots:
    /**
     * @brief Sets the level of a board.
     *
     * @param level The level to set.
     */
    void setLevel(const GameLevel& level);
    /**
     * @brief Moves the block to the free position if it is possible.
     *
     * @param from The coordinates of a block to start from.
     */
    void moveBlock(const Position& from);
    /**
     * @brief Undo the move on the board.
     *
     * @param move The move to undo.
     */
    void undoMove(const std::shared_ptr<Move>& move);
    /**
     * @brief Restarts the game.
     *
     */
    void restart();
    /**
     * @brief Starts the game.
     *
     * @param level The level to start game with.
     */
    void start(const GameLevel& level);
    /**
     * @brief Handler for signals when new state has been loaded (game has been loaded from file).
     *
     * @param state The state object, holding level, numbers and size of the board.
     */
    void stateLoadedHandler(const LoadState& state);

private:
    /**
     * @brief Checks if the board is solved.
     *
     */
    void isSolved();
    /**
     * @brief Exchanges the placement of two Blocks.
     *
     * @param move Holds the information about indexes of Blocks.
     * @param undo Indicates if it is an undo action.
     */
    void swapBlock(const std::shared_ptr<Move>& move, bool undo = false);

    size_t _level; /**< The current level of an board. */
    std::vector<std::shared_ptr<Block<BlockLayoutItem>>> _blocks; /**< The blocks that creates the board, */
};

#endif // BLOCKSMODEL_H

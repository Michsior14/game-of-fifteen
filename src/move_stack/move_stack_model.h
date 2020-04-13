#ifndef MOVE_STACK_H
#define MOVE_STACK_H

#include <stddef.h>
#include <list>
#include <QObject>
#include <QTimer>

#include "move.h"
#include "../block/block.h"
#include "../block/block_layout_item.h"
#include "../state_manager/state_manager_model.h"

/**
 * @brief The model responsible for storing all moves that have been made by the user
 * and passed time.
 *
 */
class MoveStackModel: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The stack iterator.
     *
     */
    using iterator = std::list<std::shared_ptr<Move>>::const_iterator;
    /**
     * @brief Creates the new model.
     *
     */
    MoveStackModel();
    /**
     * @brief The default destructor
     */
    virtual ~MoveStackModel();
    /**
     * @brief Undo the last move if there is any.
     *
     */
    void undo();
    /**
     * @brief Returns the number of total moves done by the user, including `undo` ones.
     *
     * @return size_t The number of total moves.
     */
    size_t inline totalMoves() const {
        return _totalMoves;
    }
    /**
     * @brief Returns the iterator to the first move in the stack.
     *
     * @return iterator The iterator.
     */
    iterator inline begin() const {
        return _moves.begin();
    }
    /**
     * @brief Returns the iterator to the last move in the stack.
     *
     * @return iterator The iterator.
     */
    iterator inline end() const {
        return _moves.end();
    }

signals:
    /**
     * @brief Emitted when number of moves has changed.
     *
     * @param counter The number of moves.
     * @param moves The list of pointers to changed moves.
     */
    void totalMovesChanged(const size_t& counter, const std::list<std::shared_ptr<Move>>& moves);
    /**
     * @brief Emitted when passed time changes.
     *
     * @param timePassed The number of seconds since the first move.
     */
    void timePassedChanged(const size_t& timePassed);
    /**
     * @brief Emitted when move has been undone.
     *
     * @param move The move that has been undone.
     */
    void undoMove(const std::shared_ptr<Move>& move);

public slots:
    /**
     * @brief Handles the swapped blocks signal.
     *
     * @param a The first Block that changed the placement.
     * @param b The second Block that changed the placement.
     * @param move Describes the move that happend on the board (how positions changed).
     * @param undo Indicates if it is an undo action.
     */
    void blockSwapedHandler(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    /**
     * @brief Handles the new game signal.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     * @param size The edge size of a board (i.e. 4 in case of board created for 16 blocks)
     */
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size);
    /**
     * @brief Handles the puzzle solved signal.
     *
     */
    void puzzleSolvedHandler();
    /**
     * @brief Handler for signals when new state has been loaded (game has been loaded from file).
     *
     * @param state The state object, holding level, numbers and size of the board.
     */
    void stateLoadedHandler(const LoadState& state);

private:
    /**
     * @brief Adds move to the stack.
     *
     * @param move
     */
    void add(const std::shared_ptr<Move>& move);
    /**
     * @brief Sets the total number of moves and emits proper signal.
     *
     * @param moves The number of moves.
     */
    void setTotalMoves(size_t moves);
    /**
     * @brief Sets the passed time and emits proper signal.
     *
     * @param timePassed The passed time.
     */
    void setTimePassed(size_t timePassed);
    /**
     * @brief Stops the active timer.
     *
     */
    void stopTimer();
    /**
     * @brief Clears the move stack and reset all resources.
     *
     */
    void clear();

    size_t _totalMoves = 0; /**< The number of all moves. */
    size_t _timePassed = 0; /**< The time passed since the first move. */
    std::list<std::shared_ptr<Move>> _moves; /**< The list of done moves. */
    QTimer* _timer; /**< The timer used to mesure how much time passed from the first move. */
};

#endif // MOVE_STACK_H

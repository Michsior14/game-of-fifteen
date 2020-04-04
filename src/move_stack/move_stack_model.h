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
 * @brief
 *
 */
class MoveStackModel: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     */
    using iterator = std::list<std::shared_ptr<Move>>::const_iterator;
    /**
     * @brief
     *
     */
    MoveStackModel();
    virtual ~MoveStackModel();

    /**
     * @brief
     *
     */
    void undo();

    /**
     * @brief
     *
     * @return size_t
     */
    size_t inline totalMoves() const {
        return _totalMoves;
    }
    /**
     * @brief
     *
     * @return iterator
     */
    iterator inline begin() const {
        return _moves.begin();
    }
    /**
     * @brief
     *
     * @return iterator
     */
    iterator inline end() const {
        return _moves.end();
    }

signals:
    /**
     * @brief
     *
     * @param moves
     */
    void movesChanged(const size_t& moves);
    /**
     * @brief
     *
     * @param counter
     * @param moves
     */
    void totalMovesChanged(const size_t& counter, const std::list<std::shared_ptr<Move>>& moves);
    /**
     * @brief
     *
     * @param timePassed
     */
    void timePassedChanged(const size_t& timePassed);
    /**
     * @brief
     *
     * @param move
     */
    void undoMove(const std::shared_ptr<Move>& move);

public slots:
    /**
     * @brief
     *
     * @param a
     * @param b
     * @param move
     * @param undo
     */
    void blockSwapedHandler(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    /**
     * @brief
     *
     * @param blocks
     * @param level
     */
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& level);
    /**
     * @brief
     *
     */
    void puzzleSolvedHandler();
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
     * @param move
     */
    void add(const std::shared_ptr<Move>& move);
    /**
     * @brief
     *
     * @param moves
     */
    void setTotalMoves(size_t moves);
    /**
     * @brief
     *
     * @param timePassed
     */
    void setTimePassed(size_t timePassed);
    /**
     * @brief
     *
     */
    void stopTimer();
    /**
     * @brief
     *
     */
    void clear();

    size_t _totalMoves = 0; /**< TODO: describe */
    size_t _timePassed = 0; /**< TODO: describe */
    std::list<std::shared_ptr<Move>> _moves; /**< TODO: describe */
    QTimer* _timer; /**< TODO: describe */
};

#endif // MOVE_STACK_H

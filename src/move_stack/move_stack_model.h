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
    using iterator = std::list<std::shared_ptr<Move>>::const_iterator;
    /**
     * @brief
     *
     */
    MoveStackModel();
    virtual ~MoveStackModel();

    void undo();

    size_t inline totalMoves() const {
        return _totalMoves;
    }
    iterator inline begin() const {
        return _moves.begin();
    }
    iterator inline end() const {
        return _moves.end();
    }

signals:
    void movesChanged(const size_t& moves);
    void totalMovesChanged(const size_t& counter, const std::list<std::shared_ptr<Move>>& moves);
    void timePassedChanged(const size_t& timePassed);
    void undoMove(const std::shared_ptr<Move>& move);

public slots:
    void blockSwapedHandler(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move, bool undo);
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& level);
    void puzzleSolvedHandler();
    void stateLoadedHandler(const LoadState& state);

private:
    void add(const std::shared_ptr<Move>& move);
    void setTotalMoves(size_t moves);
    void setTimePassed(size_t timePassed);
    void stopTimer();
    void clear();

    size_t _totalMoves = 0;
    size_t _timePassed = 0;
    std::list<std::shared_ptr<Move>> _moves;
    QTimer* _timer;
};

#endif // MOVE_STACK_H

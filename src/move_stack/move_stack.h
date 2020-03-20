#ifndef MOVE_STACK_H
#define MOVE_STACK_H

#include <stddef.h>
#include <list>
#include <QObject>

#include "move.h"
#include "../block/block.h"

/**
 * @brief
 *
 */
class MoveStack: public QObject
{
    Q_OBJECT
public:
    using iterator = std::list<Move>::const_iterator;
    /**
     * @brief
     *
     */
    MoveStack() {};
    virtual ~MoveStack() = default;

    void undo(){
        if(_moves.size() == 0){
            return;
        }

        setTotalMoves(_totalMoves+1);
        emit undoMove(_moves.back());
        _moves.pop_back();
    };
    size_t inline totalMoves() const {
        return _totalMoves;
    }
    iterator begin() const {
        return _moves.begin();
    }
    iterator end() const {
        return _moves.end();
    }

signals:
    void totalMovesChanged(const size_t& moves);
    void undoMove(const Move& move);

public slots:
    void blockSwapedHandler(Block& a, Block& b, const Move& move, bool undo) {
        Q_UNUSED(a);
        Q_UNUSED(b);
        if(undo){
            return;
        }
        add(move);
    }
    void gameStartedHandler(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& level){
        Q_UNUSED(blocks);
        Q_UNUSED(level);
        clear();
    }

private:
    void add(const Move& move) {
        _moves.push_back(move);
        setTotalMoves(_totalMoves+1);
    }
    void setTotalMoves(size_t moves) {
        _totalMoves = moves;
        emit totalMovesChanged(_totalMoves);
    }
    void clear(){
        _moves.clear();
        setTotalMoves(0);
    };

    size_t _totalMoves;
    std::list<Move> _moves;
};

#endif // MOVE_STACK_H

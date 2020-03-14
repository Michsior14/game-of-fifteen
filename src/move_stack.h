#ifndef MOVE_STACK_H
#define MOVE_STACK_H

#include <stddef.h>
#include <list>
#include <QObject>

struct Position {
    size_t row;
    size_t column;

    Position(size_t posRow, size_t posCol): row(posRow), column(posCol) {};
    virtual ~Position() = default;
};

struct Move {
    Position from;
    Position to;

    Move(Position fromPos, Position toPos): from(fromPos), to(toPos){};
    virtual ~Move() = default;
};

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
    void add(const Move& move) {
        _moves.push_back(move);
        setTotalMoves(_totalMoves+1);
    }
    void undo(){
        if(_moves.size() == 0){
            return;
        }

        setTotalMoves(_totalMoves+1);
        emit undoMove(_moves.back());
        _moves.pop_back();
    };
    void clear(){
        _moves.clear();
        setTotalMoves(0);
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

private:
    void setTotalMoves(size_t moves) {
        _totalMoves = moves;
        emit totalMovesChanged(_totalMoves);
    }

    size_t _totalMoves;
    std::list<Move> _moves;
};

#endif // MOVE_STACK_H

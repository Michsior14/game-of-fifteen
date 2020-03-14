#ifndef MOVE_STACK_H
#define MOVE_STACK_H

#include <stddef.h>
#include <list>

struct Position {
    size_t row;
    size_t column;
};

struct Move {
    Position from;
    Position to;
};

/**
 * @brief
 *
 */
template <class T>
class MoveStack
{
public:
    /**
     * @brief
     *
     */
    MoveStack() {
        clear();
    };
    void add(const T& move) {
        _moves.push_back(move);
        _totalMoves++;
    }
    const T undo(){
        _totalMoves++;
        const auto last = _moves.back();
        _moves.pop_back();
        return last;
    };
    void clear(){
        _moves.clear();
        _totalMoves = 0;
    };
    size_t inline moves() const {
        return _moves;
    }
private:
    size_t _totalMoves;
    std::list<T> _moves;
};

#endif // MOVE_STACK_H

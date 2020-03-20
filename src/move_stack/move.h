#ifndef MOVE_H
#define MOVE_H

#include <stddef.h>

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

#endif // MOVE_H

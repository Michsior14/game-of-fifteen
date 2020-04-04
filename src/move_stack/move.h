#ifndef MOVE_H
#define MOVE_H

#include <stddef.h>

/**
 * @brief
 *
 */
struct Position {
    size_t row; /**< TODO: describe */
    size_t column; /**< TODO: describe */

    /**
     * @brief
     *
     * @param posRow
     * @param posCol
     */
    Position(size_t posRow, size_t posCol): row(posRow), column(posCol) {};
    /**
     * @brief
     *
     */
    virtual ~Position() = default;
};

/**
 * @brief
 *
 */
struct Move {
    Position from; /**< TODO: describe */
    Position to; /**< TODO: describe */

    /**
     * @brief
     *
     * @param fromPos
     * @param toPos
     */
    Move(Position fromPos, Position toPos): from(fromPos), to(toPos){};
    /**
     * @brief
     *
     */
    virtual ~Move() = default;
};

#endif // MOVE_H

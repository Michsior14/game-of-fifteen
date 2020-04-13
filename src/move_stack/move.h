#ifndef MOVE_H
#define MOVE_H

#include <stddef.h>

/**
 * @brief The structure that indicates the position of Block in the grid layout.
 *
 */
struct Position {
    size_t row; /**< The row in the grid */
    size_t column; /**< The column in the grid */

    /**
     * @brief Creates the position.
     *
     * @param posRow The row in the grid.
     * @param posCol THe column in the grid.
     */
    Position(const size_t posRow, const size_t posCol): row(posRow), column(posCol) {};
    /**
     * @brief The default destructor.
     *
     */
    virtual ~Position() = default;
};

/**
 * @brief Represents the move of Block between two positions on the grid layout.
 *
 */
struct Move {
    Position from; /**< The starting position of the move. */
    Position to; /**< The ending position of the move. */

    /**
     * @brief Creates the move out of provided positions.
     *
     * @param fromPos The starting position of the move.
     * @param toPos The ending position of the move.
     */
    Move(const Position fromPos, const Position toPos): from(fromPos), to(toPos){};
    /**
     * @brief The default destructor.
     *
     */
    virtual ~Move() = default;
};

#endif // MOVE_H

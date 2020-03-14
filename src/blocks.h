#ifndef BLOCKS_H
#define BLOCKS_H

#include <stddef.h>
#include <QGridLayout>

#include "game_level.h"
#include "block.h"
#include "move_stack.h"

/**
 * @brief
 *
 */
class Blocks: public QGridLayout {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param level
     * @param parent
     */
    Blocks(const GameLevel level, MoveStack* stack, QWidget* parent = nullptr);
    /**
     * @brief
     *
     * @param level
     */
    void newPuzzle(const GameLevel level);
    void restartPuzzle();
    /**
     * @brief
     *
     */
    virtual ~Blocks() = default;

    /**
     * @brief
     *
     * @param row
     * @param column
     */
    void move(const size_t row, const size_t column);
    /**
     * @brief
     *
     * @return bool
     */
    bool isSolved();
    /**
     * @brief
     *
     */
    void print();
    /**
     * @brief
     *
     * @param row
     * @param column
     * @return Block
     */
    Block* blockAtPosition(const size_t row, const size_t column);

public slots:
    void undoMove(const Move& move);

private slots:
    /**
     * @brief
     *
     */
    void blockClicked();

private:
    /**
     * @brief
     *
     */
    void clear();
    /**
     * @brief
     *
     * @param rowA
     * @param columnA
     * @param rowB
     * @param columnB
     */
    void swapBlocks(const size_t rowA, const size_t columnA, const size_t rowB, const size_t columnB, const bool save = true);

    size_t _level; /**< TODO: describe */
    MoveStack* _moveStack;
};

#endif // BLOCKS_H

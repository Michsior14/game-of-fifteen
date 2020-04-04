#ifndef NUMBERED_BLOCK_H
#define NUMBERED_BLOCK_H

#include "block.h"
#include "block_layout_item.h"

/**
 * @brief
 *
 */
class NumberedBlock: public Block<BlockLayoutItem> {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    NumberedBlock(const size_t value, QGraphicsItem* parent=nullptr): Block(value, parent) {};
    /**
     * @brief
     *
     */
    virtual ~NumberedBlock() = default;
    /**
     * @brief
     *
     * @return bool
     */
    bool isFree() const override {
        return false;
    };
};

#endif // NUMBERED_BLOCK_H

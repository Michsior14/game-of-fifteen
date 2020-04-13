#ifndef NUMBERED_BLOCK_H
#define NUMBERED_BLOCK_H

#include "block.h"
#include "block_layout_item.h"

/**
 * @brief Represents a Block with number displayed on it.
 *
 */
class NumberedBlock: public Block<BlockLayoutItem> {
    Q_OBJECT
public:
    /**
     * @brief Creates the Block based on provided value.
     *
     * @param value The underlaying value assigned to the Block.
     * @param parent The Qt's parent object.
     */
    NumberedBlock(const size_t value, QGraphicsItem* parent=nullptr): Block(value, parent) {};
    /**
     * @brief The default destructor.
     *
     */
    virtual ~NumberedBlock() = default;
    /**
     * @brief Defines the Block as not "free".
     *
     * @return bool Always False.
     */
    bool isFree() const override {
        return false;
    };
};

#endif // NUMBERED_BLOCK_H

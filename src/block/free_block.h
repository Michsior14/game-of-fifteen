#ifndef FREE_BLOCK_H
#define FREE_BLOCK_H

#include "block.h"
#include "block_layout_item.h"

/**
 * @brief Represents empty Block (without the title displayed to the user).
 *
 */
class FreeBlock: public Block<BlockLayoutItem> {
    Q_OBJECT
public:
    /**
     * @brief Creates the free Block.
     *
     * @param value The underlaying value assigned to the Block.
     * @param parent The Qt's parent object.
     */
    FreeBlock(const size_t value, QGraphicsItem* parent=nullptr): Block(value, "", parent) {};
    /**
     * @brief The default destructor.
     *
     */
    virtual ~FreeBlock() = default;
    /**
     * @brief Defines the Block as "free".
     *
     * @return bool Always True.
     */
    bool isFree() const override  {
        return true;
    };
};

#endif // FREE_BLOCK_H

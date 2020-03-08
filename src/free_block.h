#ifndef FREE_BLOCK_H
#define FREE_BLOCK_H

#include "block.h"

/**
 * @brief
 *
 */
class FreeBlock: public Block {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    FreeBlock(size_t value, QWidget* parent=nullptr): Block(value, "", parent) {};
    /**
     * @brief
     *
     */
    virtual ~FreeBlock() = default;
    /**
     * @brief
     *
     * @return bool
     */
    bool isFree() const override  {
        return true;
    };
};

#endif // FREE_BLOCK_H

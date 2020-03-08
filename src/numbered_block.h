#ifndef NUMBERED_BLOCK_H
#define NUMBERED_BLOCK_H

#include "block.h"

/**
 * @brief
 *
 */
class NumberedBlock: public Block {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    NumberedBlock(const size_t value, QWidget* parent=nullptr): Block(value, parent) {};
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

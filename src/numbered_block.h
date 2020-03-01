#ifndef NUMBERED_BLOCK_H
#define NUMBERED_BLOCK_H

#include "block.h"

class NumberedBlock: public Block {
public:
    NumberedBlock(const size_t _value): Block(_value) {}

    bool IsFree() const override {
        return false;
    };
};

#endif // NUMBERED_BLOCK_H

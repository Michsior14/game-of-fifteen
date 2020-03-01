#ifndef FREE_BLOCK_H
#define FREE_BLOCK_H

#include "block.h"

class FreeBlock: public Block {
public:
    FreeBlock(size_t _value): Block(_value, "") {}

    bool IsFree() const override {
        return true;
    };
};

#endif // FREE_BLOCK_H

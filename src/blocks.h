#ifndef BLOCKS_H
#define BLOCKS_H

#include <stddef.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <iostream>
#include <memory>
#include "block.h"
#include "numbered_block.h"
#include "free_block.h"

enum class Movement {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

template<size_t N>
class Blocks {

public:
    Blocks() {
        size = N * N;
        blocks.reserve(size);

        size_t i = 1;
        while(i < size){
            blocks.push_back(std::make_shared<NumberedBlock>(i++));
        }
        blocks.push_back(std::make_shared<FreeBlock>(i));

        shuffle();
    }

    Movement move(const size_t index) {
        if(index >= N && blocks[index-N]->IsFree()) {
            std::swap(blocks[index], blocks[index-N]);
            return Movement::UP;
        } else if ((index+1) % N > 1 && blocks[index-1]->IsFree()) {
            std::swap(blocks[index], blocks[index-1]);
            return Movement::LEFT;
        } else if ((index+1) % N > 0 && blocks[index+1]->IsFree()) {
            std::swap(blocks[index], blocks[index+1]);
            return Movement::RIGHT;
        } else if(index < N * (N-1) && blocks[index+N]->IsFree()) {
            std::swap(blocks[index], blocks[index+N]);
            return Movement::DOWN;
        }
        return Movement::NONE;
    }

    void print() {
        for(size_t i = 0 ; i < size; i++){
            std::cout << std::setw(2) << blocks[i]->Title() << " |";
            if((i+1) % N == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

private:
    void shuffle() {
        size_t time = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(blocks.begin(), blocks.end(), std::default_random_engine(time));
    }

    size_t size;
    std::vector<std::shared_ptr<Block>> blocks;
};

#endif // BLOCKS_H

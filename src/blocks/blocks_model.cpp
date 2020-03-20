#include <random>
#include <chrono>
#include <iostream>
#include <iomanip>

#include "blocks_model.h"
#include "../block/numbered_block.h"
#include "../block/free_block.h"

BlocksModel::BlocksModel(QObject *parent) : QObject(parent)
{
}

void BlocksModel::setLevel(const GameLevel& level){
    _level = static_cast<size_t>(level);
    emit levelChanged(level);
    start();
}

void BlocksModel::start() {
    size_t blocksSize = _level * _level;

    _blocks.clear();
    _blocks.reserve(blocksSize);

    size_t i = 1;
    while(i < blocksSize){
        _blocks.push_back(std::make_shared<NumberedBlock>(i++));
    }
    _blocks.push_back(std::make_shared<FreeBlock>(i));

    size_t time = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(_blocks.begin(), _blocks.end(), std::default_random_engine(time));
    emit gameStarted(_blocks, _level);
}

void BlocksModel::moveBlock(const Position& from) {
    if(from.row >= 1 && _blocks[(from.row - 1) * _level + from.column]->isFree()) {
        swapBlock(Move(from, Position(from.row-1, from.column)));
    } else if (from.column != 0 && _blocks[from.row * _level + from.column - 1]->isFree()) {
        swapBlock(Move(from, Position(from.row, from.column - 1)));
    } else if (from.column != _level-1 && _blocks[from.row * _level + from.column + 1]->isFree()) {
        swapBlock(Move(from, Position(from.row, from.column + 1)));
    } else if(from.row != _level-1 && _blocks[(from.row + 1) * _level + from.column]->isFree()) {
        swapBlock(Move(from, Position(from.row+1, from.column)));
    }
    isSolved();
}


void BlocksModel::undoMove(const Move& move){
    swapBlock(Move(move.to, move.from), true);
}

void BlocksModel::swapBlock(const Move& move, bool undo) {
    auto aIdx = move.from.row * _level + move.from.column;
    auto bIdx = move.to.row * _level + move.to.column;
    auto tmp = _blocks[aIdx];
    _blocks[aIdx] = _blocks[bIdx];
    _blocks[bIdx] = tmp;
    emit blockSwaped(*_blocks[bIdx].get(), *_blocks[aIdx].get(), move, undo);
}

void BlocksModel::isSolved() {
    for(size_t i = 0; i+1 < _level * _level; i++) {
        if(_blocks[i]->value() != i+1) {
            return;
        }
    }
    emit puzzleSolved();
    start();
}

void BlocksModel::print() {
    for(size_t i = 0; i < _level; i++) {
        for(size_t j = 0; j < _level; j++) {
            std::cout << std::setw(2) << _blocks[i * _level + j]->title() << "(" << &_blocks[i * _level + j] << ") |";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

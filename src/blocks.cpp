#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <QMessageBox>

#include "blocks.h"
#include "block.h"
#include "numbered_block.h"
#include "free_block.h"


Blocks::Blocks(const size_t edge, QWidget* parent): QGridLayout(parent) {
    newPuzzle(edge);
}

void Blocks::newPuzzle(size_t edge) {
    clear();

    _edge = edge;
    size_t blocksSize = _edge * _edge;
    std::vector<Block*> blocks;
    blocks.reserve(blocksSize);

    size_t i = 1;
    while(i < blocksSize){
        blocks.push_back(new NumberedBlock(i++));
    }
    blocks.push_back(new FreeBlock(i));

    size_t time = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(blocks.begin(), blocks.end(), std::default_random_engine(time));

    for(i = 0; i < _edge; i++) {
        for(size_t j = 0; j < _edge; j++) {
            auto block = blocks[i*_edge+j];
            connect(block, SIGNAL(clicked()), this, SLOT(blockClicked()));
            QGridLayout::addWidget(block, i, j);
        }
    }
}

void Blocks::move(const size_t row, const size_t column) {
    if(row >= 1 && blockAtPosition(row-1, column)->isFree()) {
        swapBlocks(row, column, row-1, column);
    } else if (column != 0 && blockAtPosition(row, column-1)->isFree()) {
        swapBlocks(row, column, row, column-1);
    } else if (column != _edge-1 && blockAtPosition(row, column+1)->isFree()) {
        swapBlocks(row, column, row, column+1);
    } else if(row != _edge-1 && blockAtPosition(row+1, column)->isFree()) {
        swapBlocks(row, column, row+1, column);
    }

    if(isSolved()) {
        QMessageBox::information(parentWidget(), tr("Game Over"), tr("You won! Congratulations!"));
        newPuzzle(_edge);
    }
}

Block* Blocks::blockAtPosition(const size_t row, const size_t column) {
   return dynamic_cast<Block*>(QGridLayout::itemAtPosition(row, column)->widget());
}

bool Blocks::isSolved() {
    for(size_t i = 0; i < _edge; i++) {
        for(size_t j = 0; j < _edge; j++) {
            if(blockAtPosition(i, j)->value() != (i*_edge+j)+1) {
                return false;
            }
        }
    }
    return true;
}

void Blocks::print() {
    for(size_t i = 0; i < _edge; i++) {
        for(size_t j = 0; j < _edge; j++) {
            std::cout << std::setw(2) << blockAtPosition(i, j)->value() << " |";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Blocks::blockClicked() {
    Block* clickedButton = qobject_cast<Block*>(sender());
    int row, column, rowSpan, columnSpan;
    QGridLayout::getItemPosition(QGridLayout::indexOf(clickedButton), &row, &column, &rowSpan, &columnSpan);
    move(row, column);
}

void Blocks::swapBlocks(const size_t rowA, const size_t columnA, const size_t rowB, const size_t columnB) {
    auto a = blockAtPosition(rowA, columnA);
    auto b = blockAtPosition(rowB, columnB);
    QGridLayout::addWidget(a, rowB, columnB);
    QGridLayout::addWidget(b, rowA, columnA);
}

void Blocks::clear() {
    for (int i = 0; i < QGridLayout::count(); i++) {
        QGridLayout::itemAt(i)->widget()->deleteLater();
    }
    _edge = 0;
}

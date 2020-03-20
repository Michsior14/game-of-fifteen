#include <stddef.h>
#include <iostream>
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>

#include "blocks_view.h"
#include "../block/block_layout_item.h"

BlocksView::BlocksView(QWidget *parent) : QGraphicsView(parent), _layout(new QGraphicsGridLayout) {
   const auto scene = new QGraphicsScene;
   const auto centerWidget = new QGraphicsWidget;
   centerWidget->setLayout(_layout);
   scene->addItem(centerWidget);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setScene(scene);
};

void BlocksView::gameStartedHandler(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& level){
    clear();

    for(size_t i = 0; i < level; i++) {
        for(size_t j = 0; j < level; j++) {
            auto block = blocks[i*level+j];
            _layout->addItem(block->layoutItem(), i, j);
        }
    }
    auto hint = _layout->sizeHint(Qt::SizeHint::PreferredSize);
    auto width = hint.width(), height = hint.height();
    setFixedSize(width+5, height+5);
    setSceneRect(0, 0, width, height);
};

void BlocksView::blockSwapedHandler(Block& a, Block& b, const Move& move){
    _layout->removeItem(a.layoutItem());
    _layout->removeItem(b.layoutItem());
    _layout->addItem(a.layoutItem(), move.to.row, move.to.column);
    _layout->addItem(b.layoutItem(), move.from.row, move.from.column);
};

void BlocksView::puzzleSolvedHandler(){
    QMessageBox::information(parentWidget(), tr("Game Over"), tr("You won! Congratulations!"), tr("New game"));
};

void BlocksView::mousePressEvent(QMouseEvent *event) {
    if(items(event->pos()).empty()){
        return;
    }

    auto first = dynamic_cast<BlockLayoutItem*>(items(event->pos()).first());
    if(event->type() != QEvent::MouseButtonPress || event->button() != Qt::MouseButton::LeftButton || !first){
        return;
    }

    for(int i = 0; i < _layout->rowCount(); i++){
        for(int j = 0; j < _layout->columnCount(); j++) {
            if(first == _layout->itemAt(i, j)) {
                emit blockClicked(Position(i, j));
                return;
            }
        }
    }
};

void BlocksView::clear() {
    for(int i = 0; i < _layout->count(); i++){
        _layout->removeAt(i);
    }
}

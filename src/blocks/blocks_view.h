#ifndef BLOCKSVIEW_H
#define BLOCKSVIEW_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <memory>

#include "../game_level.h"
#include "../move_stack/move.h"
#include "../block/block.h"

class BlocksView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit BlocksView(QWidget *parent = nullptr);
    virtual ~BlocksView() = default;

signals:
    void blockClicked(const Position& position);

public slots:
    void gameStartedHandler(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& level);
    void blockSwapedHandler(Block& a, Block& b, const std::shared_ptr<Move>& move);
    void puzzleSolvedHandler();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void clear();
    QGraphicsGridLayout* _layout;
};

#endif // BLOCKSVIEW_H

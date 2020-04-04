#ifndef BLOCKSVIEW_H
#define BLOCKSVIEW_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <memory>

#include "../game_level.h"
#include "../move_stack/move.h"
#include "../block/block.h"
#include "../block/block_layout_item.h"

/**
 * @brief
 *
 */
class BlocksView : public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit BlocksView(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~BlocksView() = default;

signals:
    /**
     * @brief
     *
     * @param position
     */
    void blockClicked(const Position& position);

public slots:
    /**
     * @brief
     *
     * @param blocks
     * @param level
     */
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& level);
    /**
     * @brief
     *
     * @param a
     * @param b
     * @param move
     */
    void blockSwapedHandler(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move);
    /**
     * @brief
     *
     */
    void puzzleSolvedHandler();

protected:
    /**
     * @brief
     *
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);

private:
    /**
     * @brief
     *
     */
    void clear();
    QGraphicsGridLayout* _layout; /**< TODO: describe */
};

#endif // BLOCKSVIEW_H

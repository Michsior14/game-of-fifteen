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
 * @brief View responsible for showing all Blocks that takes part in the game.
 *
 */
class BlocksView : public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief Creates the view.
     *
     * @param parent The Qt's parent object.
     */
    explicit BlocksView(QWidget *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~BlocksView() = default;

signals:
    /**
     * @brief Emitted whenever displayed Block has been clicked.
     *
     * @param position The possition of the Block that has been clicked.
     */
    void blockClicked(const Position& position);

public slots:
    /**
     * @brief Handles the new game signal.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     * @param size The edge size of a board (i.e. 4 in case of board created for 16 blocks)
     */
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& level);
    /**
     * @brief Handles the swapped blocks signal.
     *
     * @param a The first Block that changed the placement.
     * @param b The second Block that changed the placement.
     * @param move Describes the move that happend on the board (how positions changed).
     */
    void blockSwapedHandler(Block<BlockLayoutItem>& a, Block<BlockLayoutItem>& b, const std::shared_ptr<Move>& move);
    /**
     * @brief Handles the puzzle solved signal.
     *
     */
    void puzzleSolvedHandler();

protected:
    /**
     * @brief Handles mouse pressed events that origin from the blocks view.
     *
     * @param event The mouse event.
     */
    void mousePressEvent(QMouseEvent *event);

private:
    /**
     * @brief Removes all items from the layout.
     *
     */
    void clear();
    QGraphicsGridLayout* _layout; /**< The layout that holds all blocks inside */
};

#endif // BLOCKSVIEW_H

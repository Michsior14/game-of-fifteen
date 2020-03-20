#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE

#include "move_stack/move_stack.h"
#include "move_stack/move_stack_view.h"
#include "move_stack/move_stack_controller.h"
#include "blocks/blocks_model.h"
#include "blocks/blocks_view.h"
#include "blocks/blocks_controller.h"
//#include "state_manager.h"

/**
 * @brief
 *
 */
class Game : public QMainWindow
{
    Q_OBJECT
public:
    explicit Game();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    void createActions();
    void createMenus();

    QMenu* gameMenu;
    QMenu* levelMenu;

    QAction* newGameAct;
    QAction* saveGameAct;
    QAction* easyLevelAct;
    QAction* mediumLevelAct;
    QAction* hardLevelAct;
    QAction* undoMove;

    //StateManager *stateManager;

    BlocksModel _blocksModel;
    BlocksView* _blocksView;
    BlocksController _blocksController;

    MoveStack _moveStack;
    MoveStackView* _moveView;
    MoveStackController _moveStackController;
};

#endif // GAME_H

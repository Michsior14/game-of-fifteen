#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE

#include "move_stack/move_stack_model.h"
#include "move_stack/move_stack_view.h"
#include "move_stack/move_stack_controller.h"
#include "blocks/blocks_model.h"
#include "blocks/blocks_view.h"
#include "blocks/blocks_controller.h"
#include "state_manager/state_manager_model.h"
#include "state_manager/state_manager_controller.h"

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
    QAction* loadGameAct;
    QAction* easyLevelAct;
    QAction* mediumLevelAct;
    QAction* hardLevelAct;
    QAction* undoMove;

    StateManagerModel _stateManagerModel;
    MoveStackModel _moveStackModel;
    BlocksModel _blocksModel;

    MoveStackView* _moveView;
    MoveStackController _moveStackController;

    BlocksView* _blocksView;
    BlocksController _blocksController;

    StateManagerController _stateManagerController;
};

#endif // GAME_H

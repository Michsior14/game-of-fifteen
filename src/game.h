#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QAction;
class QActionGroup;
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
 * @brief The main window used to display the game.
 *
 */
class Game : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief The creates the main window.
     *
     */
    explicit Game();
    /**
     * @brief The default destructor.
     *
     */
    virtual ~Game();

    /**
     * @brief Shows the window in the center of a screen.
     *
     */
    void show();

protected:
#ifndef QT_NO_CONTEXTMENU
    /**
     * @brief Reimplement to recive context menu events.
     *
     * @param event The context of menu events.
     */
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    /**
     * @brief Creates actions used in the menu.
     *
     */
    void createActions();
    /**
     * @brief Creates menus on the Game window.
     *
     */
    void createMenus();

    QMenu* _gameMenu; /**< The main menu instance. */
    QMenu* _levelMenu; /**< The level submenu instance. */

    QAction* _newGameAct; /**< The new game action instance. */
    QAction* _saveGameAct; /**< The save game action instance. */
    QAction* _loadGameAct; /**< The load game action instance. */
    QAction* _easyLevelAct; /**< The easy level action instance. */
    QAction* _mediumLevelAct; /**< The medium level action instance. */
    QAction* _customLevelAct; /**< The custom level action instance. */
    QAction* _hardLevelAct; /**< The hard level action instance. */
    QAction* _undoMove; /**< The undo move action instance. */
    QActionGroup* _levelGroup; /**< The level group instance. */

    StateManagerModel _stateManagerModel; /**< The StateManagerModel instance. */
    MoveStackModel _moveStackModel; /**< The MoveStackModel instance. */
    BlocksModel _blocksModel; /**< The BlocksModel instance. */

    MoveStackView* _moveView; /**< The MoveStackView instance. */
    MoveStackController _moveStackController; /**< The MoveStackController instance. */

    BlocksView* _blocksView; /**< The BlocksView instance. */
    BlocksController _blocksController; /**< The BlocksController instance. */

    StateManagerController _stateManagerController; /**< The StateManagerController instance. */
};

#endif // GAME_H

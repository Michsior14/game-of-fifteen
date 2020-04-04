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
    /**
     * @brief
     *
     */
    explicit Game();
    /**
     * @brief
     *
     */
    virtual ~Game();

protected:
#ifndef QT_NO_CONTEXTMENU
    /**
     * @brief
     *
     * @param event
     */
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    /**
     * @brief
     *
     */
    void createActions();
    /**
     * @brief
     *
     */
    void createMenus();

    QMenu* _gameMenu; /**< TODO: describe */
    QMenu* _levelMenu; /**< TODO: describe */

    QAction* _newGameAct; /**< TODO: describe */
    QAction* _saveGameAct; /**< TODO: describe */
    QAction* _loadGameAct; /**< TODO: describe */
    QAction* _easyLevelAct; /**< TODO: describe */
    QAction* _mediumLevelAct; /**< TODO: describe */
    QAction* _hardLevelAct; /**< TODO: describe */
    QAction* _undoMove; /**< TODO: describe */

    StateManagerModel _stateManagerModel; /**< TODO: describe */
    MoveStackModel _moveStackModel; /**< TODO: describe */
    BlocksModel _blocksModel; /**< TODO: describe */

    MoveStackView* _moveView; /**< TODO: describe */
    MoveStackController _moveStackController; /**< TODO: describe */

    BlocksView* _blocksView; /**< TODO: describe */
    BlocksController _blocksController; /**< TODO: describe */

    StateManagerController _stateManagerController; /**< TODO: describe */
};

#endif // GAME_H

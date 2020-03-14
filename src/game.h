#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE

#include "blocks.h"

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

    QMenu *gameMenu;
    QMenu *levelMenu;

    QAction *newGameAct;
    QAction *easyLevelAct;
    QAction *mediumLevelAct;
    QAction *hardLevelAct;

    Blocks *blocks;
};

#endif // GAME_H

#include <QtWidgets>

#include "game_level.h"
#include "game.h"

Game::Game() : QMainWindow()
{
    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *centerWidget = new QWidget;
    blocks = new Blocks(GameLevel::Easy);
    centerWidget->setLayout(blocks);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(centerWidget);
    widget->setLayout(layout);

    createActions();
    createMenus();
}

#ifndef QT_NO_CONTEXTMENU
void Game::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void Game::createActions(){
    newGameAct = new QAction(tr("&New Game"), this);
    newGameAct->setShortcuts(QKeySequence::New);
    newGameAct->setStatusTip(tr("Create a new game"));
    connect(newGameAct, &QAction::triggered, this, [this]{ blocks->restartPuzzle(); });

    easyLevelAct = new QAction(tr("Easy"), this);
    connect(easyLevelAct, &QAction::triggered, this, [this]{ blocks->newPuzzle(GameLevel::Easy); });

    mediumLevelAct = new QAction(tr("Medium"), this);
    connect(mediumLevelAct, &QAction::triggered, this, [this]{ blocks->newPuzzle(GameLevel::Medium); });

    hardLevelAct = new QAction(tr("Hard"), this);
    connect(hardLevelAct, &QAction::triggered, this, [this]{ blocks->newPuzzle(GameLevel::Hard); });
}

void Game::createMenus(){
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(newGameAct);

    levelMenu = gameMenu->addMenu(tr("Choose level"));
    levelMenu->addAction(easyLevelAct);
    levelMenu->addAction(mediumLevelAct);
    levelMenu->addAction(hardLevelAct);
}

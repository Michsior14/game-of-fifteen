#include <QtWidgets>
#include <QFileDialog>

#include "game_level.h"
#include "game.h"
#include "move_stack_view.h"
#include "move_stack_controller.h"

Game::Game() : QMainWindow()
{
    moveStack = new MoveStack();
    blocks = new Blocks(GameLevel::Easy, moveStack);
    stateManager = new StateManager(moveStack, blocks);

    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    MoveStackView* moveView = new MoveStackView;
    new MoveStackController(moveView, moveStack, blocks);

    QWidget *centerWidget = new QWidget;
    centerWidget->setLayout(blocks);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(moveView);
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

    undoMove = new QAction(tr("Undo"), this);
    undoMove->setShortcuts(QKeySequence::Undo);
    undoMove->setStatusTip(tr("Undo last move"));
    connect(undoMove, &QAction::triggered, this, [this]{ moveStack->undo(); });


    saveGameAct = new QAction(tr("&Save Game"), this);
    saveGameAct->setShortcuts(QKeySequence::Save);
    saveGameAct->setStatusTip(tr("Save the game"));
    connect(saveGameAct, &QAction::triggered, this, [this]{
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("Save Game"), "",
                tr("GameSave (*.save);;All Files (*)"));
        stateManager->saveGame(fileName.toStdString());
    });

}

void Game::createMenus(){
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(newGameAct);
    gameMenu->addAction(saveGameAct);

    levelMenu = gameMenu->addMenu(tr("Choose level"));
    levelMenu->addAction(easyLevelAct);
    levelMenu->addAction(mediumLevelAct);
    levelMenu->addAction(hardLevelAct);

    gameMenu->addAction(undoMove);
}

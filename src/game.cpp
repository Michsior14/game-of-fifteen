#include <QtWidgets>
#include <QFileDialog>
#include <iostream>

#include "game_level.h"
#include "game.h"

Game::Game() : QMainWindow(),
    _blocksView(new BlocksView),
    _blocksController(_blocksModel, *_blocksView),
    _moveView(new MoveStackView),
    _moveStackController(_moveStack, *_moveView, _blocksModel)
{
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    //stateManager = new StateManager(moveStack, blocks);

    auto widget = new QWidget;
    setCentralWidget(widget);

    auto topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    auto layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(_moveView);
    layout->addWidget(_blocksView);
    widget->setLayout(layout);

    createActions();
    createMenus();

    _blocksController.init();
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
    connect(newGameAct, &QAction::triggered, this, [this]{ _blocksModel.start(); });

    easyLevelAct = new QAction(tr("Easy"), this);
    connect(easyLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Easy); });

    mediumLevelAct = new QAction(tr("Medium"), this);
    connect(mediumLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Medium); });

    hardLevelAct = new QAction(tr("Hard"), this);
    connect(hardLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Hard); });

    undoMove = new QAction(tr("Undo"), this);
    undoMove->setShortcuts(QKeySequence::Undo);
    undoMove->setStatusTip(tr("Undo last move"));
    connect(undoMove, &QAction::triggered, this, [this]{ _moveStack.undo(); });


    saveGameAct = new QAction(tr("&Save Game"), this);
    saveGameAct->setShortcuts(QKeySequence::Save);
    saveGameAct->setStatusTip(tr("Save the game"));
    connect(saveGameAct, &QAction::triggered, this, [this]{
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("Save Game"), "",
                tr("GameSave (*.save);;All Files (*)"));
       // stateManager->saveGame(fileName.toStdString());
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

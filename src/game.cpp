#include <QtWidgets>
#include <QFileDialog>
#include <iostream>

#include "game_level.h"
#include "game.h"

Game::Game() : QMainWindow(),
    _moveView(new MoveStackView),
    _moveStackController(_moveStackModel, *_moveView, _blocksModel, _stateManagerModel),
    _blocksView(new BlocksView),
    _blocksController(_blocksModel, *_blocksView, _stateManagerModel),
    _stateManagerController(_stateManagerModel, _blocksModel, _moveStackModel)
{
    layout()->setSizeConstraint(QLayout::SetFixedSize);

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

Game::~Game() {
    delete _gameMenu;
    delete _levelMenu;

    delete _newGameAct;
    delete _saveGameAct;
    delete _loadGameAct;
    delete _easyLevelAct;
    delete _mediumLevelAct;
    delete _hardLevelAct;
    delete _undoMove;

    delete _moveView;
    delete _blocksView;
}

#ifndef QT_NO_CONTEXTMENU
void Game::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void Game::createActions(){
    _newGameAct = new QAction(tr("&New Game"), this);
    _newGameAct->setShortcuts(QKeySequence::New);
    _newGameAct->setStatusTip(tr("Create a new game"));
    connect(_newGameAct, &QAction::triggered, this, [this]{ _blocksModel.start(); });

    _easyLevelAct = new QAction(tr("Easy"), this);
    connect(_easyLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Easy); });

    _mediumLevelAct = new QAction(tr("Medium"), this);
    connect(_mediumLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Medium); });

    _hardLevelAct = new QAction(tr("Hard"), this);
    connect(_hardLevelAct, &QAction::triggered, this, [this]{ _blocksModel.setLevel(GameLevel::Hard); });

    _undoMove = new QAction(tr("Undo"), this);
    _undoMove->setShortcuts(QKeySequence::Undo);
    _undoMove->setStatusTip(tr("Undo last move"));
    connect(_undoMove, &QAction::triggered, this, [this]{ _moveStackModel.undo(); });

    _saveGameAct = new QAction(tr("&Save Game"), this);
    _saveGameAct->setShortcuts(QKeySequence::Save);
    _saveGameAct->setStatusTip(tr("Save the game"));
    connect(_saveGameAct, &QAction::triggered, this, [this]{
       _stateManagerModel.saveGame(QFileDialog::getSaveFileName(this,
                                                                tr("Save Game"), QDate::currentDate().toString("dd-MM-yyyy") + ".save",
                                                                tr("GameSave (*.save);;All Files (*)")));
    });

    _loadGameAct = new QAction(tr("L&oad Game"), this);
    _loadGameAct->setShortcuts(QKeySequence::Open);
    _loadGameAct->setStatusTip(tr("Load the game"));
    connect(_loadGameAct, &QAction::triggered, this, [this]{
       _stateManagerModel.loadGame(QFileDialog::getOpenFileName(this,
                                                                tr("Load Game"), "",
                                                                tr("GameSave (*.save);;All Files (*)")));
    });
}

void Game::createMenus(){
    _gameMenu = menuBar()->addMenu(tr("&Game"));
    _gameMenu->addAction(_newGameAct);
    _gameMenu->addAction(_saveGameAct);
    _gameMenu->addAction(_loadGameAct);

    _levelMenu = _gameMenu->addMenu(tr("Choose level"));
    _levelMenu->addAction(_easyLevelAct);
    _levelMenu->addAction(_mediumLevelAct);
    _levelMenu->addAction(_hardLevelAct);

    _gameMenu->addAction(_undoMove);
}

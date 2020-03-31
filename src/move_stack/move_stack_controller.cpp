#include "move_stack_controller.h"

MoveStackController::MoveStackController(MoveStackModel& model, MoveStackView& view, BlocksModel& blocksModel, StateManagerModel& stateManagerModel, QObject *parent) : QObject(parent), _view(view), _model(model), _blocksModel(blocksModel) {
    connect(&_model, &MoveStackModel::totalMovesChanged, &_view, &MoveStackView::setCountLabel);
    connect(&_model, &MoveStackModel::timePassedChanged, &_view, &MoveStackView::setTimePassed);
    connect(&_model, &MoveStackModel::undoMove, &_blocksModel, &BlocksModel::undoMove);
    connect(&_blocksModel, &BlocksModel::blockSwaped, &_model, &MoveStackModel::blockSwapedHandler);
    connect(&_blocksModel, &BlocksModel::gameStarted, &_model, &MoveStackModel::gameStartedHandler);
    connect(&_blocksModel, &BlocksModel::puzzleSolved, &_model, &MoveStackModel::puzzleSolvedHandler);
    connect(&stateManagerModel, &StateManagerModel::stateLoaded, &_model, &MoveStackModel::stateLoadedHandler);
}

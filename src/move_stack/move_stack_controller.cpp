#include "move_stack_controller.h"

MoveStackController::MoveStackController(MoveStackModel& model, MoveStackView& view, BlocksModel& blocksModel, StateManagerModel& stateManagerModel, QObject *parent) : QObject(parent) {
    connect(&model, &MoveStackModel::totalMovesChanged, &view, &MoveStackView::setCountLabel);
    connect(&model, &MoveStackModel::timePassedChanged, &view, &MoveStackView::setTimePassed);
    connect(&model, &MoveStackModel::undoMove, &blocksModel, &BlocksModel::undoMove);
    connect(&blocksModel, &BlocksModel::blockSwaped, &model, &MoveStackModel::blockSwapedHandler);
    connect(&blocksModel, &BlocksModel::gameStarted, &model, &MoveStackModel::gameStartedHandler);
    connect(&blocksModel, &BlocksModel::puzzleSolved, &model, &MoveStackModel::puzzleSolvedHandler);
    connect(&stateManagerModel, &StateManagerModel::stateLoaded, &model, &MoveStackModel::stateLoadedHandler);
}

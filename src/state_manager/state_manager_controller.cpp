#include "state_manager_controller.h"

StateManagerController::StateManagerController(StateManagerModel& model, BlocksModel& blocksModel, MoveStackModel& movesStackModel, QObject *parent) : QObject(parent), _model(model), _blocksModel(blocksModel), _moveStackModel(movesStackModel) {
    connect(&_blocksModel, &BlocksModel::gameStarted, &_model, &StateManagerModel::gameStartedHandler);
    connect(&_blocksModel, &BlocksModel::blocksUpdated, &_model, &StateManagerModel::blocksUpdatedHandler);
    connect(&_moveStackModel, &MoveStackModel::totalMovesChanged, &_model, &StateManagerModel::totalMovesHandler);
    connect(&_moveStackModel, &MoveStackModel::timePassedChanged, &_model, &StateManagerModel::timePassedHandler);
}

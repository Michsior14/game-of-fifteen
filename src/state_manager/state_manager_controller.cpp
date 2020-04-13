#include "state_manager_controller.h"

StateManagerController::StateManagerController(StateManagerModel& model, BlocksModel& blocksModel, MoveStackModel& movesStackModel, QObject *parent) : QObject(parent) {
    connect(&blocksModel, &BlocksModel::gameStarted, &model, &StateManagerModel::gameStartedHandler);
    connect(&blocksModel, &BlocksModel::blocksUpdated, &model, &StateManagerModel::blocksUpdatedHandler);
    connect(&movesStackModel, &MoveStackModel::totalMovesChanged, &model, &StateManagerModel::totalMovesHandler);
    connect(&movesStackModel, &MoveStackModel::timePassedChanged, &model, &StateManagerModel::timePassedHandler);
}

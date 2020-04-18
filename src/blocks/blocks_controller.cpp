#include "blocks_controller.h"

BlocksController::BlocksController(BlocksModel& model, BlocksView& view, StateManagerModel& stateManagerModel, QObject *parent) : QObject(parent), _model(model) {
    connect(&_model, &BlocksModel::gameStarted, &view, &BlocksView::gameStartedHandler);
    connect(&_model, &BlocksModel::gameRestored, &view, &BlocksView::gameStartedHandler);
    connect(&_model, &BlocksModel::puzzleSolved, &view, &BlocksView::puzzleSolvedHandler);
    connect(&_model, &BlocksModel::blockSwaped, &view, &BlocksView::blockSwapedHandler);
    connect(&view, &BlocksView::blockClicked, &_model, &BlocksModel::moveBlock);
    connect(&stateManagerModel, &StateManagerModel::stateLoaded, &_model, &BlocksModel::stateLoadedHandler);
}

void BlocksController::init() {
    _model.start(static_cast<size_t>(GameLevel::Easy));
}

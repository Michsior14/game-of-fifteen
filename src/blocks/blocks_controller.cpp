#include "blocks_controller.h"

BlocksController::BlocksController(BlocksModel& model, BlocksView& view, StateManagerModel& stateManagerModel, QObject *parent) : QObject(parent), _view(view),  _model(model), _stateManagerModel(stateManagerModel) {
    connect(&_model, &BlocksModel::gameStarted, &_view, &BlocksView::gameStartedHandler);
    connect(&_model, &BlocksModel::gameRestored, &_view, &BlocksView::gameStartedHandler);
    connect(&_model, &BlocksModel::puzzleSolved, &_view, &BlocksView::puzzleSolvedHandler);
    connect(&_model, &BlocksModel::blockSwaped, &_view, &BlocksView::blockSwapedHandler);
    connect(&_view, &BlocksView::blockClicked, &_model, &BlocksModel::moveBlock);
    connect(&stateManagerModel, &StateManagerModel::stateLoaded, &_model, &BlocksModel::stateLoadedHandler);
}

void BlocksController::init() {
    _model.start(GameLevel::Easy);
}

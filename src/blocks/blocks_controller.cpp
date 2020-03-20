#include "blocks_controller.h"

BlocksController::BlocksController(BlocksModel& model, BlocksView& view, QObject *parent) : QObject(parent), _view(view),  _model(model) {
    connect(&_model, &BlocksModel::gameStarted, &_view, &BlocksView::gameStartedHandler);
    connect(&_model, &BlocksModel::puzzleSolved, &_view, &BlocksView::puzzleSolvedHandler);
    connect(&_model, &BlocksModel::blockSwaped, &_view, &BlocksView::blockSwapedHandler);
    connect(&_view, &BlocksView::blockClicked, &_model, &BlocksModel::moveBlock);
}

void BlocksController::init() {
    _model.setLevel(GameLevel::Easy);
}

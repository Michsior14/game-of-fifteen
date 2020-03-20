#include "move_stack_controller.h"

MoveStackController::MoveStackController(MoveStack& model, MoveStackView& view, BlocksModel& blocksModel, QObject *parent) : QObject(parent), _view(view), _model(model), _blocksModel(blocksModel) {
    connect(&_model, &MoveStack::totalMovesChanged, &_view, &MoveStackView::setCountLabel);
    connect(&_model, &MoveStack::undoMove, &_blocksModel, &BlocksModel::undoMove);
    connect(&_blocksModel, &BlocksModel::blockSwaped, &_model, &MoveStack::blockSwapedHandler);
    connect(&_blocksModel, &BlocksModel::gameStarted, &_model, &MoveStack::gameStartedHandler);
}

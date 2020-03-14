#include "move_stack_controller.h"

MoveStackController::MoveStackController(MoveStackView* view, MoveStack* model, Blocks* blocks, QObject *parent) : QObject(parent), _view(view), _model(model), _blocks(blocks) {
    connect(model, &MoveStack::totalMovesChanged, _view, &MoveStackView::setCountLabel);
    connect(model, &MoveStack::undoMove, _blocks, &Blocks::undoMove);
    model->clear();
}

#ifndef MOVESTACKCONTROLLER_H
#define MOVESTACKCONTROLLER_H

#include "move_stack_view.h"
#include "move_stack.h"
#include "../blocks/blocks_model.h"

#include <QObject>

class MoveStackController : public QObject
{
    Q_OBJECT
public:
    explicit MoveStackController(MoveStack& model, MoveStackView& view, BlocksModel& blocks, QObject *parent = nullptr);
    virtual ~MoveStackController() = default;

private:
    MoveStackView& _view;
    MoveStack& _model;
    BlocksModel& _blocksModel;
};

#endif // MOVESTACKCONTROLLER_H

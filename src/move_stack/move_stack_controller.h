#ifndef MOVESTACKCONTROLLER_H
#define MOVESTACKCONTROLLER_H

#include "move_stack_view.h"
#include "move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

class MoveStackController : public QObject
{
    Q_OBJECT
public:
    explicit MoveStackController(MoveStackModel& model, MoveStackView& view, BlocksModel& blocks, StateManagerModel& stateManagerModel, QObject *parent = nullptr);
    virtual ~MoveStackController() = default;

private:
    MoveStackView& _view;
    MoveStackModel& _model;
    BlocksModel& _blocksModel;
};

#endif // MOVESTACKCONTROLLER_H

#ifndef STATEMANAGERCONTROLLER_H
#define STATEMANAGERCONTROLLER_H

#include "state_manager_model.h"
#include "../move_stack/move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

class StateManagerController : public QObject
{
    Q_OBJECT
public:
    explicit StateManagerController(StateManagerModel& model, BlocksModel& blocksModel, MoveStackModel& movesStackModel, QObject *parent = nullptr);
    virtual ~StateManagerController() = default;

private:
    StateManagerModel& _model;
    BlocksModel& _blocksModel;
    MoveStackModel& _moveStackModel;
};

#endif // STATEMANAGERCONTROLLER_H

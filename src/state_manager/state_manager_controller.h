#ifndef STATEMANAGERCONTROLLER_H
#define STATEMANAGERCONTROLLER_H

#include "state_manager_model.h"
#include "../move_stack/move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

/**
 * @brief
 *
 */
class StateManagerController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param model
     * @param blocksModel
     * @param movesStackModel
     * @param parent
     */
    explicit StateManagerController(StateManagerModel& model, BlocksModel& blocksModel, MoveStackModel& movesStackModel, QObject *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~StateManagerController() = default;

private:
    StateManagerModel& _model; /**< TODO: describe */
    BlocksModel& _blocksModel; /**< TODO: describe */
    MoveStackModel& _moveStackModel; /**< TODO: describe */
};

#endif // STATEMANAGERCONTROLLER_H

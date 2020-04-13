#ifndef STATEMANAGERCONTROLLER_H
#define STATEMANAGERCONTROLLER_H

#include "state_manager_model.h"
#include "../move_stack/move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

/**
 * @brief Connects StateManaggerModel with Blocks nad MoveStack models.
 *
 */
class StateManagerController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates the controller.
     *
     * @param model The StateManagerModel instance.
     * @param blocksModel The BlocksModel instance.
     * @param movesStackModel The MoveStackModel instance.
     * @param parent The Qt's parent object.
     */
    explicit StateManagerController(StateManagerModel& model, BlocksModel& blocksModel, MoveStackModel& movesStackModel, QObject *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~StateManagerController() = default;
};

#endif // STATEMANAGERCONTROLLER_H

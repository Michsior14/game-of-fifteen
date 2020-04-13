#ifndef MOVESTACKCONTROLLER_H
#define MOVESTACKCONTROLLER_H

#include "move_stack_view.h"
#include "move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

/**
 * @brief Connects MoveStackModel with MoveStackView.
 *
 */
class MoveStackController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates the controller.
     *
     * @param model The MoveStackModel instance.
     * @param view The MoveStackView instance.
     * @param blocks The BlocksModel instance.
     * @param stateManagerModel The StateManagerModel instance.
     * @param parent The Qt's parent object.
     */
    explicit MoveStackController(MoveStackModel& model, MoveStackView& view, BlocksModel& blocks, StateManagerModel& stateManagerModel, QObject *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~MoveStackController() = default;
};

#endif // MOVESTACKCONTROLLER_H

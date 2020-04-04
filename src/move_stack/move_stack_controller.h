#ifndef MOVESTACKCONTROLLER_H
#define MOVESTACKCONTROLLER_H

#include "move_stack_view.h"
#include "move_stack_model.h"
#include "../blocks/blocks_model.h"

#include <QObject>

/**
 * @brief
 *
 */
class MoveStackController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param model
     * @param view
     * @param blocks
     * @param stateManagerModel
     * @param parent
     */
    explicit MoveStackController(MoveStackModel& model, MoveStackView& view, BlocksModel& blocks, StateManagerModel& stateManagerModel, QObject *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~MoveStackController() = default;

private:
    MoveStackView& _view; /**< TODO: describe */
    MoveStackModel& _model; /**< TODO: describe */
    BlocksModel& _blocksModel; /**< TODO: describe */
};

#endif // MOVESTACKCONTROLLER_H

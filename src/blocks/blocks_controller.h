#ifndef BLOCKCONTROLLER_H
#define BLOCKCONTROLLER_H

#include <QObject>
#include "blocks_view.h"
#include "blocks_model.h"

/**
 * @brief Connects BlocksModel with BlockView.
 *
 */
class BlocksController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates the controller.
     *
     * @param model The BlocksModel instance.
     * @param view The BlocksView instance.
     * @param stateManagerModel The StateManagerModel instance.
     * @param parent The Qt's parent object.
     */
    explicit BlocksController(BlocksModel& model, BlocksView& view, StateManagerModel& stateManagerModel, QObject *parent = nullptr);
    /**
     * @brief Initialize the default values for the model.
     *
     */
    void init();

private:
    BlocksModel& _model; /**< The blocks model instance. */
};

#endif // BLOCKCONTROLLER_H

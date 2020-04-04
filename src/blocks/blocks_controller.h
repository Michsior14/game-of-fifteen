#ifndef BLOCKCONTROLLER_H
#define BLOCKCONTROLLER_H

#include <QObject>
#include "blocks_view.h"
#include "blocks_model.h"

/**
 * @brief
 *
 */
class BlocksController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param model
     * @param view
     * @param stateManagerModel
     * @param parent
     */
    explicit BlocksController(BlocksModel& model, BlocksView& view, StateManagerModel& stateManagerModel, QObject *parent = nullptr);
    /**
     * @brief
     *
     */
    void init();

private:
    BlocksView& _view; /**< TODO: describe */
    BlocksModel& _model; /**< TODO: describe */
    StateManagerModel& _stateManagerModel; /**< TODO: describe */
};

#endif // BLOCKCONTROLLER_H

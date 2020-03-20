#ifndef BLOCKCONTROLLER_H
#define BLOCKCONTROLLER_H

#include <QObject>
#include "blocks_view.h"
#include "blocks_model.h"

class BlocksController : public QObject
{
    Q_OBJECT
public:
    explicit BlocksController(BlocksModel& model, BlocksView& view, QObject *parent = nullptr);
    void init();

private:
    BlocksView& _view;
    BlocksModel& _model;
};

#endif // BLOCKCONTROLLER_H

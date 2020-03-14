#ifndef MOVESTACKCONTROLLER_H
#define MOVESTACKCONTROLLER_H

#include "move_stack_view.h"
#include "move_stack.h"
#include "blocks.h"

#include <QObject>

class MoveStackController : public QObject
{
    Q_OBJECT
public:
    explicit MoveStackController(MoveStackView* view, MoveStack* model, Blocks* blocks, QObject *parent = nullptr);
    virtual ~MoveStackController() = default;

private:
    MoveStackView* _view;
    MoveStack* _model;
    Blocks* _blocks;
};

#endif // MOVESTACKCONTROLLER_H

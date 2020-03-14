#ifndef STATEMANGER_H
#define STATEMANGER_H
#include "blocks.h"
#include "move_stack.h"

#include <QObject>

/**
 * @brief
 *
 */
class StateManager: public QObject {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param _blocks
     */
    StateManager(MoveStack* moveStack, Blocks * blocks);
    /**
     * @brief
     *
     */
    void saveGame(std::string path);
    /**
     * @brief
     *
     */
    void loadGame();
private:
    Blocks* _blocks; /**< TODO: describe */
    MoveStack* _moveStack;
};

#endif // STATEMANGER_H

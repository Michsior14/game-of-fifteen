#ifndef STATEMANGER_H
#define STATEMANGER_H
#include "blocks.h"

/**
 * @brief
 *
 */
class StateManger
{
public:
    /**
     * @brief
     *
     * @param _blocks
     */
    StateManger(Blocks * _blocks);

    /**
     * @brief
     *
     */
    void saveGame();
    /**
     * @brief
     *
     */
    void loadGame();

private:
    Blocks* _blocks; /**< TODO: describe */
};

#endif // STATEMANGER_H

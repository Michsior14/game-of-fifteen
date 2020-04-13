#ifndef STATEMANGER_H
#define STATEMANGER_H

#include <QObject>
#include <QString>

#include "../block/block.h"
#include "../block/block_layout_item.h"
#include "../move_stack/move.h"

/**
 * @brief The structure used to pass loaded state of a game to models.
 *
 */
struct LoadState {
    qint32 level; /**< The game level. */
    qint32 timePassed; /**< The time passed in the saved game. */
    qint32 movesCounter; /**< The number of moves in the saved game. */
    std::vector<qint32> blocks; /**< The numbers used to create all blocks.  */
    std::vector<Move> moves; /**< The moves done in the save game. */
};

/**
 * @brief The model responsible for the loading/saving current game from/to file.
 *
 */
class StateManagerModel: public QObject {
    Q_OBJECT
public:
    /**
     * @brief Creates the model.
     *
     */
    StateManagerModel();
    /**
     * @brief Saves the current state of a game to the passed path.
     *
     * @param path The path to the file, game will be save to.
     */
    void saveGame(const QString& path);

    /**
     * @brief Loads the state of a game from the passed path.
     *
     * @param path The path to the file, game will be load from.
     */
    void loadGame(const QString& path);

signals:
    /**
     * @brief Emitted when new state has been loaded (game has been loaded from file).
     *
     * @param state The state object, holding level, numbers and size of the board.
     */
    void stateLoaded(const LoadState& state);

public slots:
    /**
     * @brief Handles the new game signal.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     * @param size The edge size of a board (i.e. 4 in case of board created for 16 blocks)
     */
    inline void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size) {
        _level = size;
        _blocks = blocks;
    }
    /**
     * @brief Handles changes of the blocks.
     *
     * @param blocks The array of pointers to all Blocks that creates the board.
     */
    inline void blocksUpdatedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks) {
        _blocks = blocks;
    }
    /**
     * @brief Handles the total moves changes.
     *
     * @param counter The number of moves.
     * @param moves The list of pointers to changed moves.
     */
    inline void totalMovesHandler(const size_t& counter, const std::list<std::shared_ptr<Move>>& moves){
        _movesCounter = counter;
        _moves = moves;
    }
    /**
     * @brief Handles the time passed.
     *
     * @param timePassed The number of seconds since the first move.
     */
    inline void timePassedHandler(const size_t& timePassed){
        _timePassed = timePassed;
    }

private:
    size_t _level; /**< The game level. */
    size_t _movesCounter; /**< The total number of moves. */
    size_t _timePassed; /**< The time passed since first move. */
    std::vector<std::shared_ptr<Block<BlockLayoutItem>>> _blocks; /**< The current game board. */
    std::list<std::shared_ptr<Move>> _moves; /**< The list of all moves of the current game. */
};

#endif // STATEMANGER_H

#ifndef STATEMANGER_H
#define STATEMANGER_H

#include <QObject>
#include <QString>

#include "../block/block.h"
#include "../block/block_layout_item.h"
#include "../move_stack/move.h"

/**
 * @brief
 *
 */
struct LoadState {
    qint32 level; /**< TODO: describe */
    qint32 timePassed; /**< TODO: describe */
    qint32 movesCounter; /**< TODO: describe */
    std::vector<qint32> blocks; /**< TODO: describe */
    std::vector<Move> moves; /**< TODO: describe */
};

/**
 * @brief
 *
 */
class StateManagerModel: public QObject {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param _blocks
     */
    StateManagerModel();
    /**
     * @brief
     *
     */
    void saveGame(const QString& path);
    /**
     * @brief
     *
     */
    void loadGame(const QString& path);

signals:
    /**
     * @brief
     *
     * @param state
     */
    void stateLoaded(const LoadState& state);

public slots:
    /**
     * @brief
     *
     * @param blocks
     * @param size
     */
    void gameStartedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks, const size_t& size) {
        _level = size;
        _blocks = blocks;
    }
    /**
     * @brief
     *
     * @param blocks
     */
    void blocksUpdatedHandler(const std::vector<std::shared_ptr<Block<BlockLayoutItem>>>& blocks) {
        _blocks = blocks;
    }
    /**
     * @brief
     *
     * @param movesCounter
     * @param moves
     */
    void totalMovesHandler(const size_t& movesCounter, const std::list<std::shared_ptr<Move>>& moves){
        _movesCounter = movesCounter;
        _moves = moves;
    }
    /**
     * @brief
     *
     * @param timePassed
     */
    void timePassedHandler(const size_t& timePassed){
        _timePassed = timePassed;
    }


private:
    size_t _level; /**< TODO: describe */
    size_t _movesCounter; /**< TODO: describe */
    size_t _timePassed; /**< TODO: describe */
    std::vector<std::shared_ptr<Block<BlockLayoutItem>>> _blocks; /**< TODO: describe */
    std::list<std::shared_ptr<Move>> _moves; /**< TODO: describe */
};

#endif // STATEMANGER_H

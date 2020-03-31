#ifndef STATEMANGER_H
#define STATEMANGER_H

#include <QObject>
#include <QString>

#include "../block/block.h"
#include "../move_stack/move.h"

struct LoadState {
    qint32 level;
    qint32 timePassed;
    qint32 movesCounter;
    std::vector<qint32> blocks;
    std::vector<Move> moves;
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
    void stateLoaded(const LoadState& state);

public slots:
    void gameStartedHandler(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& size) {
        _level = size;
        _blocks = blocks;
    }
    void blocksUpdatedHandler(const std::vector<std::shared_ptr<Block>>& blocks) {
        _blocks = blocks;
    }
    void totalMovesHandler(const size_t& movesCounter, const std::list<std::shared_ptr<Move>>& moves){
        _movesCounter = movesCounter;
        _moves = moves;
    }
    void timePassedHandler(const size_t& timePassed){
        _timePassed = timePassed;
    }


private:
    size_t _level;
    size_t _movesCounter;
    size_t _timePassed;
    std::vector<std::shared_ptr<Block>> _blocks;
    std::list<std::shared_ptr<Move>> _moves;
};

#endif // STATEMANGER_H

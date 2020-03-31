#include "move_stack_model.h"

MoveStackModel::MoveStackModel() : _timer(new QTimer) {
    connect(_timer, &QTimer::timeout, this, [this]{ setTimePassed(_timePassed+1); });
};

MoveStackModel::~MoveStackModel() {
    delete _timer;
};

void MoveStackModel::undo(){
    if(_moves.size() == 0){
        return;
    }

    emit undoMove(_moves.back());
    _moves.pop_back();
    setTotalMoves(_totalMoves+1);
};

void MoveStackModel::blockSwapedHandler(Block& a, Block& b, const std::shared_ptr<Move>& move, bool undo) {
    Q_UNUSED(a);
    Q_UNUSED(b);
    if(undo){
        return;
    }
    add(move);
}

void MoveStackModel::gameStartedHandler(const std::vector<std::shared_ptr<Block>>& blocks, const size_t& level){
    Q_UNUSED(blocks);
    Q_UNUSED(level);
    clear();
}

void MoveStackModel::puzzleSolvedHandler() {
    stopTimer();
}

void MoveStackModel::stateLoadedHandler(const LoadState& state) {
   clear();
   for(auto move : state.moves) {
       _moves.push_back(std::make_shared<Move>(move.from, move.to));
   }
   setTotalMoves(state.movesCounter);
   setTimePassed(state.timePassed);
   _timer->start(1000);
}

void MoveStackModel::add(const std::shared_ptr<Move>& move) {
    if(_totalMoves == 0) {
        _timer->start(1000);
    }
    _moves.push_back(move);
    setTotalMoves(_totalMoves+1);
}

void MoveStackModel::setTotalMoves(size_t moves) {
    _totalMoves = moves;
    emit totalMovesChanged(_totalMoves, _moves);
}

void MoveStackModel::setTimePassed(size_t timePassed) {
    _timePassed = timePassed;
    emit timePassedChanged(_timePassed);
}

void MoveStackModel::stopTimer() {
    if(_timer->isActive()) {
        _timer->stop();
    }
}

void MoveStackModel::clear(){
    stopTimer();
    _moves.clear();
    setTotalMoves(0);
    setTimePassed(0);
};

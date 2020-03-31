#include <QDebug>
#include <QFile>

#include "state_manager_model.h"

StateManagerModel::StateManagerModel() {}

void StateManagerModel::saveGame(const QString& path){
    if(path == ""){
        return;
    }

    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Unbuffered)){
        QDataStream  stream(&file);
        stream << (qint32)_level;
        for(auto block : _blocks){
            stream << (qint32)block->value();
        }

        stream << (qint32)_timePassed << (qint32)_movesCounter << (qint32)_moves.size();
        for(auto move : _moves) {
            stream << (qint32)move->from.row << (qint32)move->from.column << (qint32)move->to.row << (qint32)move->to.column;
        }
        file.close();
    }
}

void StateManagerModel::loadGame(const QString& path){
    if(path == ""){
        return;
    }

    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Unbuffered)){
        LoadState state;
        qint32 fromRow, fromColumn, toRow, toColumn, temp;
        QDataStream  stream(&file);

        stream >> state.level;
        for(size_t i = 0; i < (size_t)state.level * state.level; i++){
            stream >> temp;
            state.blocks.push_back(temp);
        }

        stream >> state.timePassed >> state.movesCounter >> temp;
        for(size_t i = 0; i < (size_t)temp; i++){
            stream >> fromRow >> fromColumn >> toRow >> toColumn;
            state.moves.push_back(Move(Position(fromRow, fromColumn), Position(toRow, toColumn)));
        }
        file.close();

        emit stateLoaded(state);
    }
}

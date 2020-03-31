#ifndef MOVESTACKVIEW_H
#define MOVESTACKVIEW_H

#include <QWidget>
#include <QLabel>

#include "../move_stack/move.h"

class MoveStackView : public QWidget
{
    Q_OBJECT
public:
    MoveStackView(QWidget *parent = nullptr);
    virtual ~MoveStackView();

public slots:
    void setCountLabel(const size_t& couter, const std::list<std::shared_ptr<Move>>& moves) {
        Q_UNUSED(moves);
        _countLabel->setNum(static_cast<int>(couter));
    }

    void setTimePassed(const size_t& timePassed) {
        _timePassedLabel->setNum(static_cast<int>(timePassed));
    }

private:
    QLabel* _countLabel;
    QLabel* _timePassedLabel;
};

#endif // MOVESTACKVIEW_H

#ifndef MOVESTACKVIEW_H
#define MOVESTACKVIEW_H

#include <QWidget>
#include <QLabel>

#include "../move_stack/move.h"

/**
 * @brief
 *
 */
class MoveStackView : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    MoveStackView(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~MoveStackView();

public slots:
    /**
     * @brief
     *
     * @param couter
     * @param moves
     */
    void setCountLabel(const size_t& couter, const std::list<std::shared_ptr<Move>>& moves) {
        Q_UNUSED(moves);
        _countLabel->setNum(static_cast<int>(couter));
    }

    /**
     * @brief
     *
     * @param timePassed
     */
    void setTimePassed(const size_t& timePassed) {
        _timePassedLabel->setNum(static_cast<int>(timePassed));
    }

private:
    QLabel* _countLabel; /**< TODO: describe */
    QLabel* _timePassedLabel; /**< TODO: describe */
};

#endif // MOVESTACKVIEW_H

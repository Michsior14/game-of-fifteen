#ifndef MOVESTACKVIEW_H
#define MOVESTACKVIEW_H

#include <QWidget>
#include <QLabel>

#include "../move_stack/move.h"

/**
 * @brief The view responsible for display information about done moves.
 *
 */
class MoveStackView : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Creates the view.
     *
     * @param parent The Qt's parent object.
     */
    MoveStackView(QWidget *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~MoveStackView();
public slots:
    /**
     * @brief Handles the total moves changes.
     *
     * @param counter The number of moves.
     * @param moves The list of pointers to changed moves.
     */
    void setCountLabel(const size_t& couter, const std::list<std::shared_ptr<Move>>& moves) {
        Q_UNUSED(moves);
        _countLabel->setNum(static_cast<int>(couter));
    }
    /**
     * @brief Handles the time passed.
     *
     * @param timePassed The number of seconds since the first move.
     */
    void setTimePassed(const size_t& timePassed) {
        _timePassedLabel->setNum(static_cast<int>(timePassed));
    }
private:
    QLabel* _countLabel; /**< The label for number of moves. */
    QLabel* _timePassedLabel; /**< The label for passed time. */
};

#endif // MOVESTACKVIEW_H

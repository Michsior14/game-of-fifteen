#ifndef MOVESTACKVIEW_H
#define MOVESTACKVIEW_H

#include <QWidget>
#include <QLabel>

class MoveStackView : public QWidget
{
    Q_OBJECT
public:
    MoveStackView(QWidget *parent = nullptr);
    virtual ~MoveStackView() {
        delete _countLabel;
    };

public slots:
    void setCountLabel(const size_t& moves) {
        _countLabel->setNum(static_cast<int>(moves));
    }

private:
    QLabel* _countLabel;
};

#endif // MOVESTACKVIEW_H

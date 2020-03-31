#include <QHBoxLayout>

#include "move_stack_view.h"

MoveStackView::MoveStackView(QWidget *parent) : QWidget(parent), _countLabel(new QLabel), _timePassedLabel(new QLabel)
{
   const auto layout = new QHBoxLayout;
   layout->addWidget(new QLabel(tr("Moves: ")));
   layout->addWidget(_countLabel);
   layout->addWidget(new QLabel(tr("Time: ")));
   layout->addWidget(_timePassedLabel);
   setLayout(layout);
}

MoveStackView::~MoveStackView() {
    delete _countLabel;
    delete _timePassedLabel;
}

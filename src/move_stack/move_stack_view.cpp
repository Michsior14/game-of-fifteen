#include <QHBoxLayout>

#include "move_stack_view.h"

MoveStackView::MoveStackView(QWidget *parent) : QWidget(parent), _countLabel(new QLabel)
{
   const auto layout = new QHBoxLayout;
   layout->addWidget(new QLabel(tr("Moves: ")));
   layout->addWidget(_countLabel);
   setLayout(layout);
}

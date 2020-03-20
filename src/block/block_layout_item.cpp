#include "block_layout_item.h"

#include <QGradient>
#include <QGraphicsLinearLayout>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

QSize BlockLayoutItem::size = QSize(50, 50);

BlockLayoutItem::BlockLayoutItem(const std::string& text, QGraphicsItem *parent)
    : QGraphicsLayoutItem(), QGraphicsItem(parent), _text(text)
{
    geometry().setSize(size);
    setGraphicsItem(this);
}

void BlockLayoutItem::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0*/)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QRectF frame(QPointF(0,0), geometry().size());
    // paint a background rect (with gradient)
//    painter->setBrush(QBrush(gradient));
    painter->drawRect(frame);

    painter->setFont(QFont("Arial", 14));
    painter->drawText(frame, Qt::AlignHCenter | Qt::AlignVCenter, QString::fromStdString(_text));
}

QRectF BlockLayoutItem::boundingRect() const
{
    return QRectF(QPointF(0, 0), geometry().size());
}

void BlockLayoutItem::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF BlockLayoutItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
    case Qt::MaximumSize:
        return size;
    default:
        return constraint;
    }
}

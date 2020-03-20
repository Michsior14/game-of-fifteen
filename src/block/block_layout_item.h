#ifndef BLOCKLAYOUTITEM_H
#define BLOCKLAYOUTITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>


class BlockLayoutItem : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
    BlockLayoutItem(const std::string& text, QGraphicsItem *parent = nullptr);
    virtual ~BlockLayoutItem() = default;
    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    std::string text() const {return _text;};

private:
    std::string _text;
    static QSize size;
};

#endif // BLOCKLAYOUTITEM_H

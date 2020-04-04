#ifndef BLOCKLAYOUTITEM_H
#define BLOCKLAYOUTITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>


/**
 * @brief
 *
 */
class BlockLayoutItem : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
    /**
     * @brief
     *
     * @param text
     * @param parent
     */
    BlockLayoutItem(const std::string& text, QGraphicsItem *parent = nullptr);
    /**
     * @brief
     *
     */
    virtual ~BlockLayoutItem() = default;
    // Inherited from QGraphicsLayoutItem
    /**
     * @brief
     *
     * @param geom
     */
    void setGeometry(const QRectF &geom);
    /**
     * @brief
     *
     * @param which
     * @param constraint
     * @return QSizeF
     */
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;

    // Inherited from QGraphicsItem
    /**
     * @brief
     *
     * @return QRectF
     */
    QRectF boundingRect() const;
    /**
     * @brief
     *
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    /**
     * @brief
     *
     * @return std::string
     */
    std::string text() const {return _text;};

private:
    std::string _text; /**< TODO: describe */
    static QSize size; /**< TODO: describe */
};

#endif // BLOCKLAYOUTITEM_H

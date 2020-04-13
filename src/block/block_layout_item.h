#ifndef BLOCKLAYOUTITEM_H
#define BLOCKLAYOUTITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>


/**
 * @brief The layout item used for presentation of the Block.
 * Holds information about size, position etc.
 *
 */
class BlockLayoutItem : public QGraphicsLayoutItem, public QGraphicsItem, public QObject
{
public:
    /**
     * @brief Creates layout item based on the provided title and parent object.
     *
     * @param text The title of a Block.
     * @param parent The Qt's parent of a Block.
     */
    BlockLayoutItem(const std::string& text, QGraphicsItem *parent = nullptr);
    /**
     * @brief The default destructor.
     *
     */
    virtual ~BlockLayoutItem() = default;
    // Inherited from QGraphicsLayoutItem
    /**
     * @brief Sets the geometry of the layout item. Overrides the QGraphicsLayoutItem implementation.
     *
     * @param geom The geometry to set.
     */
    void setGeometry(const QRectF &geom);
    /**
     * @brief Allows Qt to set proper item size based on size hint and constraint.
     *
     * @param which The condition to get size for.
     * @param constraint Passes width and height to constrain the output.
     * @return QSizeF The desired size of an element.
     */
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;
    // Inherited from QGraphicsItem
    /**
     * @brief Gets the bounding box of the layout element.
     *
     * @return QRectF The element's bounding box.
     */
    QRectF boundingRect() const;
    /**
     * @brief Paints the element content in local coordinates.
     *
     * @param painter The painter implementation.
     * @param option The styles options for painting.
     * @param widget Points the widget that is being painted on.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    /**
     * @brief Gets the title of layout item.
     *
     * @return std::string The title of layout item.
     */
    std::string text() const {return _text;};
private:
    std::string _text; /**< The title of layout item. */
    static QSize size; /**< The prefered size of all layout items. */
};

#endif // BLOCKLAYOUTITEM_H

#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>
#include <string>
#include <QGraphicsItem>

#include "block_layout_item.h"
/**
 * @brief
 *
 */
class Block: public QObject {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    Block(const size_t value, QGraphicsItem* parent): _value(value), _layoutItem(std::make_shared<BlockLayoutItem>(std::to_string(value), parent)) {};
    /**
     * @brief
     *
     * @param value
     * @param title
     * @param parent
     */
    Block(const size_t value, const std::string title, QGraphicsItem* parent): _value(value), _layoutItem(std::make_unique<BlockLayoutItem>(title, parent)) {};
    /**
     * @brief
     *
     * @return size_t
     */
    size_t value() const { return _value; };
    /**
     * @brief
     *
     * @return std::string
     */
    std::string title() const { return _layoutItem->text(); };
    BlockLayoutItem* layoutItem() { return _layoutItem.get(); };
    /**
     * @brief
     *
     * @return bool
     */
    virtual bool isFree() const = 0;
    /**
     * @brief
     *
     */
    virtual ~Block() = default;
private:
    size_t _value; /**< TODO: describe */
    std::shared_ptr<BlockLayoutItem> _layoutItem;
};

#endif // BLOCK_H

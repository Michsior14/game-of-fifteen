#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>
#include <string>
#include <QGraphicsItem>
#include <QDebug>

/**
 * @brief
 *
 */
template <typename T>
class Block: public QObject {
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    Block(const size_t value, QGraphicsItem* parent): _value(value), _layoutItem(std::make_shared<T>(std::to_string(value), parent)) {};
    /**
     * @brief
     *
     * @param value
     * @param title
     * @param parent
     */
    Block(const size_t value, const std::string title, QGraphicsItem* parent): _value(value), _layoutItem(std::make_unique<T>(title, parent)) {};
    /**
     * @brief
     *
     */
    virtual ~Block() = default;
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
    T* layoutItem() { return _layoutItem.get(); };
    /**
     * @brief
     *
     * @return bool
     */
    virtual bool isFree() const = 0;
private:
    size_t _value; /**< TODO: describe */
    std::shared_ptr<T> _layoutItem;
};

#endif // BLOCK_H

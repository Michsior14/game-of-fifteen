#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>
#include <string>
#include <QGraphicsItem>
#include <QDebug>

/**
 * @brief Abstract class used to connect layout with model.
 * Holds the information if created block is the empty one or not.
 *
 */
template <typename T>
class Block: public QObject {
public:
    /**
     * @brief Creates Block using number only (same title and internal value).
     *
     * @param value The number a block should hold.
     * @param parent The parent Qt object.
     */
    Block(const size_t value, QGraphicsItem* parent): _value(value), _layoutItem(std::make_shared<T>(std::to_string(value), parent)) {};
    /**
     * @brief Creates Block with number and title as separate values. Useful for "empty" blocks.
     *
     * @param value The number a block should hold.
     * @param title The title of the block (displayed value to the user).
     * @param parent The parent Qt object.
     */
    Block(const size_t value, const std::string title, QGraphicsItem* parent): _value(value), _layoutItem(std::make_unique<T>(title, parent)) {};
    /**
     * @brief Default virtual destructor
     *
     */
    virtual ~Block() = default;
    /**
     * @brief Gets current number assigned to the Block.
     *
     * @return size_t Number assigned to the Block.
     */
    size_t value() const { return _value; };
    /**
     * @brief Gets current title assigned to the Block.
     *
     * @return std::string The title assigned to the Block.
     */
    std::string title() const { return _layoutItem->text(); };
    /**
     * @brief Gets a layout item assigned to the Block.
     *
     * @return T* The layout item pointer
     */
    T* layoutItem() { return _layoutItem.get(); };
    /**
     * @brief Gets information if the Block is "empty" or not.
     *
     * @return bool "True" if the Block is free, "False" otherwise.
     */
    virtual bool isFree() const = 0;
private:
    size_t _value; /**< The current number value of the Block. */
    std::shared_ptr<T> _layoutItem; /**< The pointer to layout item of the Block */
};

#endif // BLOCK_H

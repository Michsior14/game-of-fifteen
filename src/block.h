#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>
#include <string>
#include <QPushButton>


/**
 * @brief
 *
 */
class Block: public QPushButton {
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param value
     * @param parent
     */
    Block(const size_t value, QWidget* parent): QPushButton(QString::number(value), parent), _value(value) {};
    /**
     * @brief
     *
     * @param value
     * @param title
     * @param parent
     */
    Block(const size_t value, const std::string title, QWidget* parent): QPushButton(QString::fromUtf8(title.c_str()), parent), _value(value) {};
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
    std::string title() const { return QPushButton::text().toStdString(); };
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
};

#endif // BLOCK_H

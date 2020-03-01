#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>
#include <string>

class Block {

public:
    Block(const size_t _value): title(std::to_string(_value)), value(_value) {};
    Block(const size_t _value, const std::string _title): title(_title), value(_value) {};
    size_t Value() const { return value; };
    std::string Title() const { return title; };
    virtual bool IsFree() const = 0;
private:
    std::string title;
    size_t value;
};

#endif // BLOCK_H

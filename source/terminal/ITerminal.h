#ifndef _ITERMINAL_H_
#define _ITERMINAL_H_

#include <memory>
#include <string>

class ITerminal {
public:
    virtual ~ITerminal() = default;
    virtual char readChar() = 0;
    virtual void write(const std::string& str) = 0;
};

#endif
#ifndef _POSIX_TERMINAL_H_
#define _POSIX_TERMINAL_H_

#include <termios.h>
#include <unistd.h>

#include "ITerminal.h"

struct TermGuard {
    termios orig;
    TermGuard();
    ~TermGuard();
};

class PosixTerminal : public ITerminal {
public:
    PosixTerminal();
    char readChar() override;
    void write(const std::string& str) override;
private:
    std::unique_ptr<TermGuard> _termGuard;
};

#endif
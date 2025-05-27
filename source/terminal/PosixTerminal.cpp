#include "PosixTerminal.h"

TermGuard::TermGuard() {
    tcgetattr(STDIN_FILENO, &orig);
    termios raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

TermGuard::~TermGuard() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig);
}

PosixTerminal::PosixTerminal()
    : _termGuard(std::make_unique<TermGuard>()) {}

char PosixTerminal::readChar() {
    char c;
    if(read(STDIN_FILENO, &c, 1) < 0) {
        return '\0';
    }
    return c;
}

void PosixTerminal::write(const std::string& str) {
    ::write(STDOUT_FILENO, str.c_str(), str.size());
}
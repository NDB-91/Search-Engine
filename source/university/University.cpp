#include "University.h"

University::University(const Name& name)
    : _name(name) {}

University::~University() {
    
}

University::Name University::name() const {
    return _name;
}
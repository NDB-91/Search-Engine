#ifndef _REGISTRY_H_
#define _REGISTRY_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "Object.h"

class Registry {
public:
    Registry();
    
private:
    std::unordered_map<std::string, std::shared_ptr<Object*>> _registry;
};

#endif
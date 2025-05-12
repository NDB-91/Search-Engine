#ifndef _IVISITABLE_H_
#define _IVISITABLE_H_

#include <memory>
#include "IVisitor.h"

class IVisitable {
public:
    virtual ~IVisitable() = default;

    /**
     * @brief Accepts a visitor.
     * 
     * @param visitor The visitor to accept.
     */
    virtual void accept(std::shared_ptr<IVisitor> visitor) = 0;
};

#endif
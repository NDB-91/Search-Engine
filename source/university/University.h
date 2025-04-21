#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <string>

class University {
public:
    enum class Name {
        HCMUS,
        USSH,
        UIT,
        HCMUT,
        HCMUTE,
        NEU,
        FTU,
    };
public:
    University(const Name& name);
    ~University();

    Name name() const;
private:
    Name _name;
};

#endif
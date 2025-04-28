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
        Unknown,
    };
public:
    University(const Name& name);
    ~University();

    Name name() const;

    static std::string toString(Name name) {
        switch (name) {
            case Name::HCMUS: return "HCMUS";
            case Name::USSH: return "USSH";
            case Name::UIT: return "UIT";
            case Name::HCMUT: return "HCMUT";
            case Name::HCMUTE: return "HCMUTE";
            case Name::NEU: return "NEU";
            case Name::FTU: return "FTU";
            default: return "Unknown";
        }
    }

    static Name fromString(const std::string& str) {
        if (str == "HCMUS") return Name::HCMUS;
        if (str == "USSH") return Name::USSH;
        if (str == "UIT") return Name::UIT;
        if (str == "HCMUT") return Name::HCMUT;
        if (str == "HCMUTE") return Name::HCMUTE;
        if (str == "NEU") return Name::NEU;
        if (str == "FTU") return Name::FTU;
        return Name::Unknown;
    }

private:
    Name _name;
};

#endif
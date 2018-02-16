//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_INTVALUE_H
#define JOIN_INTVALUE_H

#include "../ValueClass.h"

class IntValue : public ValueClass{
private:
    int value;
public:
    IntValue(std::string in)  {
        value = std::stoi(in);
    }

    int getValue() const {
        return value;
    }

    std::ostream &operator<<(std::ostream &os) {
        os << value;
        return os;
    }


};

#endif //JOIN_INTVALUE_H

//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_STRINGVALUE_H
#define JOIN_STRINGVALUE_H

#include <string>
#include "../ValueClass.h"

class StringValue : public ValueClass{
private:
    std::string value;
public:
    StringValue(const std::string &value) : value(value) {}

    const std::string &getValue() const {
        return value;
    }
    std::ostream &operator<<(std::ostream &os) {
        os << value;
        return os;
    }

};


#endif //JOIN_STRINGVALUE_H

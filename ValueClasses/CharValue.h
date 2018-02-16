//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_CHARVALUE_H
#define JOIN_CHARVALUE_H

#include <string>
#include "../ValueClass.h"

class CharValue : public ValueClass {
public:
    CharValue(std::string in) {
        //Todo: fuck with c_str()
    }

    char getValue() const {
        return value;
    }

    std::ostream &operator<<(std::ostream &os) {
        //os << value;
        return os;
    }

private:
    char value;

};

#endif //JOIN_CHARVALUE_H

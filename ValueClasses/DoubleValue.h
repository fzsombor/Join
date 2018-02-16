//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_DOUBLEVALUE_H
#define JOIN_DOUBLEVALUE_H

#include <ostream>
#include "../ValueClass.h"

class DoubleValue : public ValueClass{
private:
    double value;
public:

    DoubleValue(std::string in)  {
        value = std::stod(in);
    }
    double getValue() const {
        return value;
    }

    std::ostream &operator<<(std::ostream &os) {
        os << value;
        return os;
    }

};


#endif //JOIN_DOUBLEVALUE_H

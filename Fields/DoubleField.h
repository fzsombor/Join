//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_DOUBLEFIELD_H
#define JOIN_DOUBLEFIELD_H

#include <string>
#include "../Field.h"

class DoubleField : public Field {

private:
    double value;
public:
    DoubleField(std::string value) {
        this->value = std::stod(value);
    }

    double getValue(){
        return value;
    }

    std::ostream& operator<<( std::ostream& output) const{
        output << this->value;
        return output;

    }

    void print() {
        std::cout << value;
    }

};

#endif //JOIN_DOUBLEFIELD_H

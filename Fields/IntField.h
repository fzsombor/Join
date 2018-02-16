//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_INTFIELD_H
#define JOIN_INTFIELD_H


#include <string>
#include <iostream>
#include "../Field.h"

class IntField : public Field {

public:
    int value;
public:
    IntField(){}
    IntField(std::string value) {
        this->value = std::stoi(value);

    }

    int getValue(){
        return value;
    }

    std::ostream& operator<<( std::ostream& output) const{
        output << this->value;
        return output;

    }

    void print() const {
        std::cout << value;
    }

};



#endif //JOIN_INTFIELD_H

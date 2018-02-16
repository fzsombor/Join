//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_INTFIELD_H
#define JOIN_INTFIELD_H

#include <string>
#include "../Field.h"

class IntField : public Field {

private:
    int value;
public:
    IntField(std::string value) {
        this->value = std::stoi(value);
    }

    int getValue(){
        return value;
    }

};

#endif //JOIN_INTFIELD_H

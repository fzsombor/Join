//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_INTFIELD_H
#define JOIN_INTFIELD_H

#include "../Field.h"

class IntField : public Field {

private:
    int value;
public:
    IntField(int value) : value(value){}

    int getValue(){
        return value;
    }

};

#endif //JOIN_INTFIELD_H

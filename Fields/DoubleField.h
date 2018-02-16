//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_DOUBLEFIELD_H
#define JOIN_DOUBLEFIELD_H

#include "../Field.h"

class DoubleField : public Field {

private:
    double value;
public:
    DoubleField(double value): value(value){}

    double getValue(){
        return value;
    }

};

#endif //JOIN_DOUBLEFIELD_H

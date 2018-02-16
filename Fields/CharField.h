//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_CHARFIELD_H
#define JOIN_CHARFIELD_H


#include "../Field.h"

class CharField : public Field {
private:
    char value;
public:
    CharField(char value) : value(value){}

    char getValue(){
        return value;
    }

};


#endif //JOIN_CHARFIELD_H

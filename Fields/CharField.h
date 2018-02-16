//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_CHARFIELD_H
#define JOIN_CHARFIELD_H


#include <string>
#include "../Field.h"

class CharField : public Field {
private:
    char value;
public:
    CharField(std::string value){
        //this->value =  value;
    }

    char getValue(){
        return value;
    }

    std::ostream& operator<<( std::ostream& output) const{
        output << this->value;
        return output;

    }

    void print() const{
        std::cout << value;
    }

};


#endif //JOIN_CHARFIELD_H

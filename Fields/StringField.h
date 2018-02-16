//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_STRINGFIELD_H
#define JOIN_STRINGFIELD_H

#include <string>
#include "../Field.h"

class StringField : public Field{
private:
    std::string value;
public:
    StringField(std::string value) : value(value){}

    std::string getValue(){
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

#endif //JOIN_STRINGFIELD_H

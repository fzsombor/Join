//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_FIELD_H
#define JOIN_FIELD_H


#include <ostream>
#include "ValueClass.h"
#include "ValueClasses/IntValue.h"
#include "ValueClasses/StringValue.h"
#include "ValueClasses/DoubleValue.h"
#include "ValueClasses/CharValue.h"

class Field {

private:
    ValueClass *value;

    //enum for switch-case
    enum typeValue {
        INT,
        STRING,
        LONG,
        CHAR,
        DOUBLE,
        SHORT,
        ERROR
    };

public:
    Field(std::string token, const std::string type){

        switch (hashIt(type)) {
            case INT:
                value = new IntValue(token);
                break;
            case STRING:
                value = new StringValue(token);
                break;
                /*    case LONG:
                        tableData[i].push_back(new IntField(token));
                        break; */
            case CHAR:
                value = new CharValue(token);   //not working with char TODO: CharValue ctor
                break;
            case DOUBLE:
               value = new DoubleValue(token);
                break;
                /*    case SHORT:
                        tableData[i].push_back(new IntField(token));
                        break; */
            default:
                std::cerr << "Error: Unsupported column type.";
                break;

        }

    }

     std::ostream &operator<<(std::ostream &os) {
        value->operator<<(os);
        return os;
    }

    void print (){
        std::cout << value.getValue();
    }




    typeValue hashIt(std::string const &inString) {
        if (inString == "int") return INT;
        if (inString == "string") return STRING;
        if (inString == "long") return LONG;
        if (inString == "char") return CHAR;
        if (inString == "double") return DOUBLE;
        if (inString == "short") return SHORT;
        std::cerr << "Error: Unsupported column type.";


        return ERROR;

    }

};


#endif //JOIN_FIELD_H

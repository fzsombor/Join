//
// Created by Fedor Zsombor on 2018. 02. 16..
//

#ifndef JOIN_FIELD_H
#define JOIN_FIELD_H


#include <ostream>
#include "Expr.h"

class Field {

private:
    Expr value;

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
    Field(std::string token, const std::string type) {

        switch (hashIt(type)) {
            case INT:
                value = Expr(std::stoi(token));
                break;
            case STRING:
                value = Expr(token);
                break;

            case DOUBLE:
                value = Expr(std::stod(token));
                break;

            default:
                std::cerr << "Error: Unsupported column type.";
                break;

        }

    }


    void getValue(int *retval) {
        *retval = value.getIntExpr();
    }

    void getValue(double *retval) {
        *retval = value.getDoubleExpr();
    }

    void getValue(std::string *retval) {
        *retval = value.getStringExp();
    }

    Expr getValue() {
        return value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Field &field) {
        os << field.value;
        return os;
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

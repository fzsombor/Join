//
// Created by Fedor Zsombor on 2018. 02. 23..
//

#ifndef JOIN_TYPEVALUE_H
#define JOIN_TYPEVALUE_H

#include <string>
#include <iostream>

class TypeValue

enum typeValues {
    INT,
    STRING,
    LONG,
    CHAR,
    DOUBLE,
    SHORT,
    ERROR
};

typeValues hashIt(std::string const &inString) {
    if (inString == "int") return INT;
    if (inString == "string") return STRING;
    if (inString == "long") return LONG;
    if (inString == "char") return CHAR;
    if (inString == "double") return DOUBLE;
    if (inString == "short") return SHORT;
    std::cerr << "Error: Unsupported column type.";


    return ERROR;

}


#endif //JOIN_TYPEVALUE_H

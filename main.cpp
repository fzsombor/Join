const int TABLE_SIZE = 128;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "Hash.h
//#include "HashEntry.h"
//#include "HashTable.h"
#include "Table.h"



int main(int argc, char *argv[]) {


    std::string lhsFilePath = argv[1];
    std::string rhsFilePath = argv[2];
    std::string equation = argv[2];

    Table *lhsTable = new Table(lhsFilePath);
    Table *rhsTable = new Table(rhsFilePath);




//enum for switch-case
    static enum typeValue {
        INT,
        STRING,
        LONG,
        CHAR,
        DOUBLE,
        SHORT
    };

    /*
    typeValue hashIt(std::string const &inString) {
        if (inString == "int") return INT;
        if (inString == "string") return STRING;
        if (inString == "long") return LONG;
        if (inString == "char") return CHAR;
        if (inString == "double") return DOUBLE;
        if (inString == "short") return SHORT;
        std::cerr << "Error: Unsupported column type.";


        return NULL;

    }



    std::string type;

    switch (hashIt(type)) {
        case INT:

            for (int i = 0; i <; ++i) {

            }

            break;
        case STRING:
            break;
        case LONG:
            break;
        case CHAR:
            break;
        case DOUBLE:
            break;
        case SHORT:
        default:
            std::cerr << "Error: Unsupported column type.";
    }
     */


 //   for (std::vector<std::string>::const_iterator i = lhsColumns.begin(); i != lhsColumns.end(); ++i)
 //       std::cout << *i << ' ';







    //HashTable hashT = new HashTable<int, >(); //hash-key, data type, Hash class



    return 0;
}
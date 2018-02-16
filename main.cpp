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

    Table lhsTable(lhsFilePath);
    Table rhsTable(rhsFilePath);

    std::string lhsColumn;
    std::string rhsColumn;

    int lhsColumnN;  //Literal column number -1
    int rhsColumnN;

    std::string delimiter = "=";
    size_t posT = 0;
    posT = equation.find(delimiter);
    lhsColumn = equation.substr(0,posT);
    rhsColumn = equation.substr(posT+delimiter.length());


    for (int i = 0; i < rhsTable.getColumnSize(); ++i) {

        if(rhsTable.getColumnName(i) == rhsColumn)
        {
         rhsColumnN = i;
            break;
        }

    }









    //HashTable hashT = new HashTable<int, >(); //hash-key, data type, Hash class



    return 0;
}
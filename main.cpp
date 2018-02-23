const int TABLE_SIZE = 128;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "Hash.h
//#include "HashEntry.h"
//#include "HashTable.h"
#include "Table.h"
#include "HashTable.h"
#include "HashJoin.h"


int main(int argc, char *argv[]) {

    std::string lhsFilePath = argv[1];
    std::string rhsFilePath = argv[2];
    std::string equation = argv[3];

    Table lhsTable(lhsFilePath);
    Table rhsTable(rhsFilePath);

    std::string lhsColumn;
    std::string rhsColumn;

    int lhsColumnN = -1;
    int rhsColumnN = -1;

    std::string delimiter = "=";
    size_t posT = 0;
    posT = equation.find(delimiter);
    lhsColumn = equation.substr(0, posT);
    rhsColumn = equation.substr(posT + delimiter.length());


    for (int i = 0; i < rhsTable.getColumnSize(); ++i) {

        if (!rhsTable.getColumnName(i).compare(rhsColumn)) {
            rhsColumnN = i;
            break;
        }

    }
    if (rhsColumnN == rhsTable.getRowSize())
        std::cerr << "There is no column named " << rhsColumn << " in the RHS table." << std::endl;

    for (int i = 0; i < lhsTable.getColumnSize(); ++i) {

        if (!lhsTable.getColumnName(i).compare(lhsColumn)) {
            lhsColumnN = i;
            break;
        }

    }

    if (lhsColumnN == rhsTable.getRowSize())
        std::cerr << "There is no column named " << lhsColumn << " in the LHS table." << std::endl;


    HashJoin(lhsTable, rhsTable, lhsColumnN, rhsColumnN);


    return 0;
}

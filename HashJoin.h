//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHJOIN_H
#define JOIN_HASHJOIN_H


#include "Table.h"
#include "HashTable.h"

class HashJoin {
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
    //Table *result;
public:


    HashJoin(Table &lhsTable, Table &rhsTable, int lhsColumnN, int rhsColumnN) {


        HashTable hashTable = HashTable(rhsTable, rhsColumnN);

        for (int j = 0; j < lhsTable.getColumnSize(); ++j) {
            std::cout << lhsTable.getColumnName(j) << "\t";
        }
        std::cout << "|\t";

        for (int j = 0; j < rhsTable.getColumnSize(); ++j) {
            std::cout << rhsTable.getColumnName(j) << "\t";
        }
        std::cout << std::endl;

        for (int j = 0; j < rhsTable.getColumnSize() + lhsTable.getColumnSize() + 1; ++j) {
            std::cout << "----";
        }
        std::cout << std::endl;

        switch (hashIt(lhsTable.getColumnType(lhsColumnN))) {

            case INT:

                int lvali;
                int rvali;
                for (int i = 0; i < lhsTable.getRowSize(); ++i) {

                    lhsTable.tableData[lhsColumnN][i]->getValue(&lvali);

                    HashEntry *
                            actual;

                    if (hashTable.hashtable[hashTable.hashFunc(lvali)] != nullptr) {
                        rvali = hashTable.hashtable[hashTable.hashFunc(lvali)]->getKey().getIntExpr();
                        actual = hashTable.hashtable[hashTable.hashFunc(lvali)];
                    }


                    if (lvali == rvali) {
                        lhsTable.printRow(i);
                        std::cout << "|\t";
                        rhsTable.printRow(actual->getValue());
                        std::cout << std::endl;
                    }

                    while (actual != nullptr) {
                        actual = actual->getNext();
                        if (actual != nullptr) {
                            rvali = actual->getKey().getIntExpr();
                            if (lvali == rvali) {
                                lhsTable.printRow(i);
                                std::cout << "|\t";
                                rhsTable.printRow(actual->getValue());
                                std::cout << std::endl;
                            }
                        }

                    }


                }


                break;
            case DOUBLE:

                double lvald;
                double rvald;
                for (int i = 0; i < lhsTable.getRowSize(); ++i) {

                    lhsTable.tableData[lhsColumnN][i]->getValue(&lvald);

                    HashEntry *
                            actual;

                    if (hashTable.hashtable[hashTable.hashFunc(lvald)] != nullptr) {
                        rvald = hashTable.hashtable[hashTable.hashFunc(lvald)]->getKey().getDoubleExpr();
                        actual = hashTable.hashtable[hashTable.hashFunc(lvald)];
                    }


                    if (lvald == rvald) {
                        lhsTable.printRow(i);
                        std::cout << "|\t";
                        rhsTable.printRow(actual->getValue());
                        std::cout << std::endl;
                    }

                    while (actual != nullptr) {
                        actual = actual->getNext();
                        if (actual != nullptr) {
                            rvald = actual->getKey().getDoubleExpr();
                            if (lvald == rvald) {
                                lhsTable.printRow(i);
                                std::cout << "|\t";
                                rhsTable.printRow(actual->getValue());
                                std::cout << std::endl;
                            }
                        }

                    }


                }

                break;

            case STRING:

                std::string lvals;
                std::string rvals;
                for (int i = 0; i < lhsTable.getRowSize(); ++i) {

                    lhsTable.tableData[lhsColumnN][i]->getValue(&lvals);

                    HashEntry *
                            actual;

                    if (hashTable.hashtable[hashTable.hashFunc(lvals)] != nullptr) {
                        rvals = hashTable.hashtable[hashTable.hashFunc(lvals)]->getKey().getStringExp();
                        actual = hashTable.hashtable[hashTable.hashFunc(lvals)];
                    }


                    if (!lvals.compare(rvals)) {
                        lhsTable.printRow(i);
                        std::cout << "|\t";
                        rhsTable.printRow(actual->getValue());
                        std::cout << std::endl;
                    }

                    while (actual != nullptr) {
                        actual = actual->getNext();
                        if (actual != nullptr) {
                            rvals = actual->getKey().getStringExp();
                            if (!lvals.compare(rvals)) {
                                lhsTable.printRow(i);
                                std::cout << "|\t";
                                rhsTable.printRow(actual->getValue());
                                std::cout << std::endl;
                            }
                        }

                    }


                }

                break;

        }


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


#endif //JOIN_HASHJOIN_H

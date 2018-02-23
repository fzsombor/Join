//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHTABLE_H
#define JOIN_HASHTABLE_H

#include <cmath>
#include "HashEntry.h"
#include "Table.h"


class HashTable {
public:
    HashEntry **hashtable;
    int tableSize;


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

    HashTable(Table &table, int columnN) {

        tableSize = table.getRowSize();

        hashtable = new HashEntry *[tableSize];

        for (int j = 0; j < tableSize; ++j) {
            //delete hashtable[j];
            hashtable[j] = nullptr;
        }

        tableSize = table.getRowSize();
        for (int i = 0; i < tableSize; ++i) {
            put(table.tableData[columnN][i]->getValue(), i);
        }


    }

    bool put(Expr key, int value) {
        int hashValue;
        switch ((typeValue) key.getType()) {
            case INT:
                hashValue = hashFunc(key.getIntExpr());
                break;
            case DOUBLE:
                hashValue = hashFunc(key.getDoubleExpr());
                break;
            case STRING:
                hashValue = hashFunc(key.getStringExp());
                break;

        }

        HashEntry *prev = nullptr;
        HashEntry *actual = hashtable[hashValue];

        while (actual != nullptr) {
            prev = actual;
            actual = actual->getNext();
        }

        if (actual == nullptr) {
            actual = new HashEntry(key, value);

            if (prev == nullptr) {

                hashtable[hashValue] = actual;
            } else {
                prev->setNext(actual);
            }
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

    int hashFunc(int v) {
        return v % tableSize;
    }

    int hashFunc(double v) {
        return (int) v % tableSize;
    }

    int hashFunc(std::string v) {
        int result = 0;
        for (size_t i = 0; i < v.length(); ++i) {
            result += v[i] * pow(31, i);
        }
        return result % tableSize;
    }


};


#endif //JOIN_HASHTABLE_H

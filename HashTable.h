//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHTABLE_H
#define JOIN_HASHTABLE_H

#include "HashEntry.h"
#include "Hash.h"
#include "Table.h"

template<typename KEY, typename VALUE, typename FUNCTION = Hash<KEY>>
class HashTable {
private:
    HashEntry<KEY, VALUE> **hashtable;
    FUNCTION hashFunc;
public:

    HashTable() {
        hashtable = new HashEntry<KEY, VALUE> *[1]();
    }

    bool put(KEY &key, VALUE &value) {
        int hashValue = hashFunc(key);
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
            } else{
                prev->setNext(actual);
            }
        }
    }

    //create table from column param @columnN
    bool createTable(Table& table, int columnN){

        for (int i = 0; i < table.getRowSize(); ++i) {
             //   table.tableData[columnN][i].getValue();
        }

    }

};


#endif //JOIN_HASHTABLE_H

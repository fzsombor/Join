//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHTABLE_H
#define JOIN_HASHTABLE_H

#include "HashEntry.h"
#include "Hash.h"

template<typename KEY, typename VALUE, typename FUNCTION = Hash<KEY>>
class HashTable {
private:
    HashEntry<KEY, VALUE> **table;
    FUNCTION hashFunc;
public:

    HashTable() {
        table = new HashEntry<KEY, VALUE> *[1]();
    }

    bool put(KEY &key, VALUE &value) {
        int hashValue = hashFunc(key);
        HashEntry *prev = nullptr;
        HashEntry *actual = table[hashValue];

        while (actual != nullptr) {
            prev = actual;
            actual = actual->getNext();
        }

        if (actual == nullptr) {
            actual = new HashEntry(key, value);

            if (prev == nullptr) {

                table[hashValue] = actual;
            } else{
                prev->setNext(actual);
            }
        }
    }

    bool createTable();

};


#endif //JOIN_HASHTABLE_H

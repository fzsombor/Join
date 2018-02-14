//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHTABLE_H
#define JOIN_HASHTABLE_H

#include "HashEntry.h"
#include "Hash.h"

template <typename KEY, typename VALUE, typename FUNCTION = Hash<KEY>>
class HashTable {
private:
    HashEntry<KEY, VALUE> **table;

};


#endif //JOIN_HASHTABLE_H

//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHENTRY_H
#define JOIN_HASHENTRY_H

#include "Field.h"


class HashEntry {
private:
    Expr key;
    int value;
    HashEntry *next;
public:
    HashEntry() {

    }

    ~HashEntry() {

        delete next;
    }

    HashEntry(Expr newKey, int newValue) {
        key = newKey;
        value = newValue;
        next = nullptr;
    }

    Expr getKey() {
        return key;
    }

    int getValue() {
        return value;
    }

    HashEntry *getNext() {
        return next;
    }

    void setKey(Expr newKey) {
        key = newKey;
    }

    void setValue(int newValue) {
        value = newValue;
    }

    void setNext(HashEntry *newNext) {
        next = newNext;
    }


};


#endif //JOIN_HASHENTRY_H

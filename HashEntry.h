//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASHENTRY_H
#define JOIN_HASHENTRY_H

template<typename KEY, typename VALUE>
class HashEntry {
private:
    KEY key;
    VALUE value;
    HashEntry *next;
public:
    HashEntry(KEY newKey, VALUE newValue){
        key = newKey;
        value = newValue;
        next = NULL;
    }
    KEY getKey() {
        return key;
    }

    VALUE getValue() {
        return value;
    }

    HashEntry *getNext() {
        return next;
    }

    void setKey(KEY newKey) {
        key = newKey;
    }

    void setValue(VALUE newValue) {
        value = newValue;
    }

    void setNext(HashEntry *newNext) {
        next = newNext;
    }


};


#endif //JOIN_HASHENTRY_H

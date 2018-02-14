//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_HASH_H
#define JOIN_HASH_H

template <typename KEY>
class Hash {

    long operator()(KEY key){
        return (long) key % TABLE_SIZE;
    }
};

#endif //JOIN_HASH_H

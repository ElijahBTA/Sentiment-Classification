//
// Created by Elijah on 9/29/2022.
//
#include "DSString.h"
#ifndef ASSIGNMENT2_SENTIMENT_STORE_H
#define ASSIGNMENT2_SENTIMENT_STORE_H
#include <iostream>
class store{
public:
    DSString wordStore;
    store(int sent, DSString word) {
        wordStore = word;
        sentiment = sent;
    }
    store() = default;
    int sentiment;
    bool operator==(const DSString& rhs){
        return wordStore == rhs;
    }

};


#endif //ASSIGNMENT2_SENTIMENT_STORE_H


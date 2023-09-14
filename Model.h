
#include <iostream>
#include <algorithm>
#include <fstream>
#include<string>
#include "DSString.h"
#include <vector>
#include "DSVector.h"
#include "store.h"
#include <cstring>
#ifndef ASSIGNMENT2_SENTIMENT_MODEL_H
#define ASSIGNMENT2_SENTIMENT_MODEL_H


class Model {
private:
    DSVector<store> dictionary;
    DSVector<store> train;
    DSVector<DSString> words2;
    vector<char>currentword;
    DSVector<store> testing;
public:
    Model();
    Model(char** newArgs);
    void training(char*);
    void test(char*);
    void checking(char*,char*,char*);


};


#endif //ASSIGNMENT2_SENTIMENT_MODEL_H

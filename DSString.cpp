//
// Created by Elijah on 9/23/2022.
//

#include "DSString.h"
#include <string.h>
#include <stdexcept>
#include <string>
#include <cstring>
#include "store.h"

using namespace std;

// constructor with no parameters
DSString :: DSString (){
    len=1;
    count=0;
    data = new char[len];
    data[0]='\0';
}


// constructor that takes in a cstring
DSString :: DSString(const char* input){
    len = strlen(input) + 1;
    count=0;
    data = new char[len];
    for(int i = 0; i < len; ++i){
        data[i] = input[i];
    }
    data[len-1] = '\0';
}

// copy constructor
DSString :: DSString(const DSString &rhs){
    len = rhs.getLen();
    count=rhs.count;
    data = new char[len];
    for(int i=0; i<len; ++i){
        data[i]= rhs.data[i];

    }

}
//deconstructer
DSString::~DSString() {
delete [] data;
}
DSString &DSString::operator=(const DSString &abc){
delete [] data;
    len=abc.getLen();
    data= new char[len];
    for(int i=0; i<len; ++i){
        data[i]= abc.data[i];
    }
return *this;

}
DSString &DSString::operator=(const char *rhs){
    delete [] data;
    len= strlen(rhs);
    data=new char [len];
    for(int i=0; i<len;++i){
        data[i]=rhs[i];
    }
    return *this;
}
DSString DSString::operator+(const DSString &rhs) const{
   int length= rhs.getLen() + len;
   char *tmp=new char[length];
   strcpy(tmp,data);
   strcat(tmp,rhs.data);
   DSString x;
   x=tmp;
   delete [] tmp;
   return x;


}
DSString DSString::operator+(const char rhs) const {
    int length = 2+len;
    char *tmp = new char[length];
    strcpy(tmp, data);
    tmp[len] = rhs;
    tmp[len + 1] = '\0';
    DSString x;
    delete[] x.data;
    x.data = tmp;
    x.len = length;
    return x;
}


bool DSString::operator==(const DSString &rhs) const {
    return (strcmp(data,rhs.data)==0);


}
bool DSString::operator==(const char* rhs) const {
    return(strcmp(data,rhs)==0);
}



bool DSString::operator<(const DSString &rhs) const {
    size_t compSize = min(getLen(), rhs.getLen());
    for (size_t i = 0; i < compSize; ++i)
    {
        if (data[i] < rhs.data[i])
            return true;
        if (data[i] > rhs.data[i])
            return false;
    }
    return false;
}

bool DSString::operator<(const char *rhs) const {
    int compSize =getLen();
    int compSizes= strlen(rhs);
    int min;
    if(compSize<compSizes){
        min=compSize;
    }
    else{
       min= compSizes;
    }
    for (int i = 0; i < min; ++i)
    {
        if (data[i] < rhs[i])
            return true;
        if (data[i] > rhs[i])
            return false;
    }
    if(len < compSizes){
        return true;
    }
    return false;
}


std::ostream &operator<<(ostream &o, const DSString &rhs) {
    char* x=rhs.data;
    for(int i=0; i<rhs.getLen();i++){
        cout<<x[i];
    }
    return o;

}

DSVector<DSString> DSString::tokenizer() {
   char *temp=new char[len+1];
    strcpy(temp,data);
    for(int i=0; i<len;i++){
        temp[i]= tolower(temp[i]);
    }
    char* tok= strtok(temp,"1234567890.,/;:?! ");
    DSVector<DSString>words;
    while(tok!= nullptr){
        words.push_back(tok);
        tok= strtok(nullptr,"1234567890.,/;:?! ");
    }
    delete [] temp;
    return words;


}




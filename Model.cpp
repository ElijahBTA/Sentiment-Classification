
#include <iostream>
#include <algorithm>
#include <fstream>
#include<string>
#include "DSString.h"
#include <vector>
#include "DSVector.h"
#include "store.h"
#include <cstring>
#include <iomanip>
#include "Model.h"
size_t Searches(const DSVector<store>& dict, const DSString& bc ){
    for(int i=0;i<dict.size();i++){
        if(dict[i].wordStore==bc){
            return i;
        }
    }
    return -1;
}


void Model::training(char *files){
    char * buffer=new char[1000];
    ifstream file;
    file.open(files);
    file.getline(buffer, 1000);
    if(!file){
        cout<<"Did not open"<<endl;
    }
    while(!file.eof()) {
        file.getline(buffer, 1000, ',');
        //Gets sentiment everytime
        char sent=buffer[0];
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000, ',');
        file.getline(buffer, 1000);
        DSString t=buffer; //storing tweet inside object
        DSVector<DSString> words= t.tokenizer(); //making vector of objects and storing the seperate strings of tweet


        for(int i=0;i<words.size();i++){

            if(words[i].getLen()<3){
                break;
            }
            //determining if the word is in my dictionary or not and incrementing the counts
            store* storing= find(dictionary.begin(), dictionary.end(), words[i]);
            if(storing != dictionary.end()){
                if(sent=='4'){
                    storing->sentiment++;
                }else{
                    storing->sentiment--;
                }
            }
            else{
                store curr;
                curr.wordStore=words[i];
                if(sent=='4'){
                    curr.sentiment=1;
                }else{
                    curr.sentiment=-1;
                }
                dictionary.push_back(curr);
            }


        }

    }


    file.close();




}

Model::Model() {

}

Model::Model(char **newArgs) {

}

void Model::test(char* files2) {


    ifstream file2;
    file2.open(files2);
    char buff[1000];
    char id[20];

    file2.getline(buff, 1000);
    if(!file2.is_open()){
        cout<<"Did not open"<<endl;
    }
    while(!file2.eof()) {
        file2.getline(id, 1000, ',');
        file2.getline(buff, 1000, ',');
        file2.getline(buff, 1000, ',');
        file2.getline(buff, 1000, ',');
        file2.getline(buff, 1000, '\n');
        int sentiment = 0;
        char *tokens = strtok(buff, "1234567890.,/;:?! ");
        while (tokens != nullptr) {
            DSString tokenWord = tokens;
            tokens = strtok(nullptr, "1234567890.,/;:?! ");
            int index = Searches(dictionary, tokenWord);
            if (index == -1) {
                continue;
            } else {
                if (dictionary[index].sentiment > 0) {
                    sentiment++;
                } else if (dictionary[index].sentiment < 0) {
                    sentiment--;
                }
            }
        }
        if (sentiment < 0) {
            sentiment = 0;
        } else if (sentiment >= 0) {
            sentiment = 4;
        }

        testing.push_back(store(sentiment, DSString(id)));
    }
    file2.close();



}

void Model::checking(char* files3, char* output1, char* output2) {
    DSVector<int> answer;
    DSVector<long long> ids;
    ifstream file3;
    file3.open(files3);
    char s[20];
    file3.getline(s, 20);
    while(!file3.eof()) {
        file3.getline(s, 20, ',');
        answer.push_back(static_cast<int>(strtol(s, nullptr, 10)));
        file3.getline(s, 20, '\n');
        ids.push_back(static_cast<long long>(strtol(s, nullptr, 10)));
    }

    file3.close();
    int counter = 0;
    for(size_t i=0; i < testing.size(); ++i){
        if(testing[i].sentiment == answer[i]){
            ++counter;
        }
    }

    ofstream firstoutput;
    firstoutput.open(output1);
    for(int i=0; i<testing.size();i++){
        firstoutput<<testing[i].sentiment<<","<<" "<<ids[i]<<endl;
    }
    //The second output file outputs my  answer sentiment first then the second sentiment is the ground truth answer
    ofstream secondoutput;
    secondoutput.open(output2);
    secondoutput<<setprecision(3)<<(float)counter/(float)answer.size()<<endl;
    for(int i=0;i<testing.size();i++) {
        secondoutput<<testing[i].sentiment<<","<<" "<<answer[i]<<","<<" "<<ids[i]<<endl;
    }


}



#include "Model.h"
//need train method to this tweet is postive and this tweet is negative so training your model to know 
//need predict method if your right if the tweet is posivte or not 
//evaluate method to see if you were right 

using namespace std;




int main(int argv, char** argsc)
{

    Model a;
    a.training(argsc[1]);
    a.test(argsc[2]);
    a.checking(argsc[3], argsc[4], argsc[5]);





    return 0;

}



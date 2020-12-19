#include "BinomialDistribution.h"
#include "NegativeBinomialDistribution.h"
#include "PoissonDistribution.h"
#include "DiscreteDistribution.h"
#include "ContinuousDistribution.h"
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
    char *str = new char[100000];
    
    // the input from console is taken as a single long string(sentence)
    cin.get(str, 100000);
    int i, len = strlen(str), numOfcommas = 0;

    //Q.  What is being done with the string input?
    //Ans Let the string be: "D3 -1 0.4 -1 10,0.3 -1 -11,0.4 -1" then:
    // this string is split into substrings by replacing "-1" by "\0\0" and ' ' by '\0', each
    // sunstring is then extracted. The substrings that we'll get for this ex are:
    // 1. "D3"   
    // 2. "0.4"
    // 3. "10,0.3"
    // 4. "-11,0.4"
    // And then each substring is seperately splitted
    // in sub-sub-string by replacing the commas by '\0'
    // NOTE: if number of commas in substring equals zero then the substring
    // corresponds to poisson distribution else it corrsponds to either of the
    // binomial distributions(negative or normal). Also, if the 1st character of the
    // substring is a '-' then the substring corresponds to negBin distribution
    
    // The corresponding sub-sub-strings are:-
    // 1. "D3"
    // 2. "0.4"
    // 3.a. "10"     3.b. "0.3"
    // 4.a. "-11"    4.b. "0.4"
    // NOTE: there can be atmost 2 sub-sub-strings in a sub-string. So, we'll
    // have 2 pointers for the same


    // splitting the input into sub-strings
    i = 0;
    while(i < len){
        if(str[i] == ' '){
            str[i] = '\0'; 
        } else if(i == (len-2) || (str[i] == '-' && str[i+2] == ' ')) {
            str[i] = '\0'; i++;
            str[i] = '\0'; i++;
            str[i] = '\0';
        }
        i++;
    }

    // extracting the 1st substring and then updating the iterator i
    // and the ptr
    i = 0;
    char *ptr = str;
    char *distCode = new char[4]; // stores distance code like "D1", "D2"...
    strcpy(distCode, str);
    ptr += strlen(ptr) + 4;
    i += strlen(ptr) + 4;

    int j, n; // n is a temporary variable
    char *temp = new char[100]; // stores each substring temporarily while
                                // we extract info from it
    
    char *ptr1 = NULL, *ptr2 = NULL; // pointers for respective sub-sub-strings

    // vector to store an array of Discrete distribution pointers
    vector<DiscreteDistribution*> distList; 
    
    double p; // p is a temporary variable
    
    // extracting the substrings
    while(i < len-1){
        strcpy(temp, ptr);
        ptr1 = temp;

        // splitting the sub-strings into sub-sub-strings
        j = 0; 
        numOfcommas = 0;
        int temp_len = strlen(temp); 
        while(j < temp_len){
            if(temp[j] == ','){
                temp[j] = '\0';
                ptr2 = temp+j+1;
                numOfcommas++;
            } j++;
        }

        // creating corresponding discrete distribution object A/T the
        // conditions illustrated above 
        if(numOfcommas == 0){
            sscanf(ptr1, "%lf", &p);
            distList.push_back(new PoissonDistribution(p));
        } else {
            sscanf(ptr2, "%lf", &p);
            if(*ptr1 == '-'){
                sscanf(ptr1+1, "%d", &n);
                distList.push_back(new NegativeBinomialDistribution(n,p));
            } else {
                sscanf(ptr1, "%d", &n);
                distList.push_back(new BinomialDistribution(n,p));
            }
        }
        // updateing ptr and iterator i
        ptr += strlen(ptr) + 4;
        i += strlen(ptr) + 4;
    }


    // computing the probability distribution array for each 
    // discrete distribution object of distList
    int limit = distList.size();
    for(i = 0; i < limit; i++){
        distList[i] -> compute_probDist();
    }

    // computing the descriptive statistics for each 
    // discrete distribution object of distList
    for(i = 0; i < limit; i++){
        distList[i] -> descriptive_statistics();
    }

    cout << fixed;
    cout.precision(4);
    // printing out the descriptive statistics using the overloaded
    // (<<) operator
    for(i = 0; i < limit-1; i++){
        *distList[i] << cout;
        cout << " -1 ";
    }
    *distList[i] << cout;
    cout << " -1" << endl;

    // creating the distance matrix
    double dist;
    for(i = 0; i < limit; i++){
        for(j = 0; j < limit-1; j++){
            dist = computeDist(distCode, *distList[i], *distList[j]);
            if(dist == -1){ // if erroneous input
                cout << "-1,";        
            } else {
                cout << truncfunc(dist) << ",";
            }
        } 
        dist = computeDist(distCode, *distList[i], *distList[j]);
        if(dist == -1){ // if erroneous input
            cout << "-1" << endl;        
        } else {
            cout << truncfunc(dist) << endl;
        }
    }
    
    return 0;
}
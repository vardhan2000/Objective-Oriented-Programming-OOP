#include <iostream>
#include <cstring>
#include <cmath>
#include "BinomialDistribution.h" 
using namespace std;

// any character other than (0 to 9) and decimal point is considered as an additional character here
bool additionalCharacters(char str[]){
    int i, limit = strlen(str);
    for(i=0; i<limit; i++){
        if(str[i] != '.' && (str[i] < '0' || str[i] > '9')){
               return true;
           }
    } return false;
}

// returns false if given character(c) appears more than n times in the given string(str)
bool characterCount(char str[], char c, int n){
    int i, limit = strlen(str), count = 0;
    for(i=0; i<limit; i++){
        if(count > n){
            return false;
        }
        if(str[i] == c){
            count++;
        }
    } return true;
}

bool inputValidity(char str[], int len, int &n, double &p1, double &p2){
    int i = 0, j = 1; // i is the character by character iterator while j is the iterator for substrings
    char *ptr = str; // setting a pointer to the 1st substring
    double x; // temporary variable
    
    while(i < len){ // while starts

        // if any additional character or the decimal point appears more than twice
        if(additionalCharacters(ptr) || !characterCount(ptr,'.',1)){
            return false;
        }

        // converting the substring to a double
        sscanf(ptr, "%lf", &x);

        if(j == 1){ // if 1st substring
            if(ceil(x) != x || x == 0){ // if x is NOT an integer or x = 0
                return false;
            }
            n = x;

        } else { // if 2nd or 3rd substring
            if(x == 0 || x > 1){ // i.e. if x does NOT lie in the interval (0,1)
                return false;
            }

            if(j == 2){ // if 2nd substring
                p1 = x;
            } else { // if 3rd substring
                p2 = x;
            }
        }
        j++;//update the substring index
        i += strlen(ptr)+1;//update the iterative variable
        ptr += strlen(ptr)+1;//update the pointer to point to the next substring
    
    } // while ends 
    return true;
}

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
    bool correctInputFlag;  
    char *str = new char[100000];
    
    // the input from console is taken as a single long string(sentence)
    cin.get(str, 100000);
    int i, len = strlen(str), numOfspaces = 0;
    
    // n stores the number of trials
    // p1 and p2 store the corresponding success probabilities
    int n;
    double p1, p2;

    // validity of str(input) is checked at 2 stages

    // STAGE 1
    for(i=0; i<len; i++){
        if(numOfspaces > 2){
            cout << "-1 ";
            return 0;
        }

        if(str[i] == ' '){
            str[i] = '\0';
            numOfspaces++;
        }
    }

    if(numOfspaces != 2){
        cout << "-1 ";
        return 0;
    }

    // STAGE 2
    correctInputFlag = inputValidity(str, len, n, p1, p2);

    if(!correctInputFlag){
        cout << "-1 ";
        return 0;
    }

    // creating the 2 BinomialDistribution objects
    BinomialDistribution b1 = BinomialDistribution(n,p1);
    BinomialDistribution b2 = BinomialDistribution(n,p2);


    // calling the makeHist() method to compute the corresponding:-
    // 1. probability distribution array(which will act as a sequence to construct the histograms)
    // 2. intervals array(bin-values)
    // 3. frequency array
    b1.makeHist();
    b2.makeHist();

    vector<double> distances; // to store the 5 kinds of distances between the 2 histograms
    double dist;

    // computing and storing the 5 types of distances, between the 2 histograms 
    dist = ManhattanDistance(b1, b2, n+1);
    if(dist == -1) { return 0; }
    distances.push_back(dist);

    dist = EuclideanDistance(b1, b2, n+1);
    if(dist == -1) { return 0; }
    distances.push_back(dist);

    dist = Chebyshev_distance(b1, b2, n+1);
    if(dist == -1) { return 0; }
    distances.push_back(dist);

    dist = KL_distance(b1, b2, n+1);
    if(dist == -1) { return 0; }
    distances.push_back(dist);

    dist = JS_distance(b1, b2, n+1);
    if(dist == -1) { return 0; }
    distances.push_back(dist);

    cout.precision(4);
    cout << fixed;

    // printing the output
    for(double x: distances){
        cout << truncfunc(x) << " ";
    }
    return 0;
}
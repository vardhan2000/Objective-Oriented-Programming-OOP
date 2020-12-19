#include <cstring>
#include <cstdio>
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <vector> 
#include "DataSequence.h"
#include "Histogram.h"
using namespace std;


// returns true if there is any additional character
bool additionalCharacters(char str[]){
    int i, limit = strlen(str);
    for(i=0; i<limit; i++){
        if(str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '-' &&
           str[i] != '0' && str[i] != '1' && str[i] != '2' && 
           str[i] != '3' && str[i] != '4' && str[i] != '5' && 
           str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9'){
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


// Recall from main() that the 1st substring is an exception as its 1st character
// is NOT a space. So, to check if the current substring is 1st or NOT, we've introduced
// an extra parameter 'int k' for "computSize()", "checkSpaces_and_Commas()" 
// and "storeSequences()"


// computes size of vector ONLY IF 1st input is either "N" or "A" i.e. the substring before the
// 1st seperator(comma or a space), is either "N" or "A". ANYTHING other than
// that would result in a "false" return. And the 2nd input should be a perfect non-negative
// integer(0 is allowed). Aything other than that would result in a false return  
bool computeSize(char str[], int *size, int k, bool *newSeq){
    
    int i, limit = strlen(str), j = 0, i1 = 0, i2 = 0, t;
    char *temp1 = new char[1000];
    char *temp2 = new char[1000];

    if(str[limit-1] != ' '){ // last character of the valid substring must be a space
        return false;
    }

    if(k == 1){ // if 1st substring
        if(str[0] != 'N'){
            return false;
        }
        t = 0;
    } else {
        if(str[0] != ' ') {return false;}
        t = 1;
    }

    //extracting the 1st and 2nd sub-substrings and storing them in temp1 and temp2 respectively
    for(i = t; i < limit && j < 2; i++){
        if(str[i] == ',' || str[i] == ' '){ // if character is a seperator
            j++;
            if(j == 1){ // if it's the 1st seperator after t(th) index
                temp1[i1] = '\0';
                i1++;
            } else { 
                temp2[i2] = '\0';
                i2++;
            }

        // if character is NOT a seperator
        } else {
            if(j < 1){
                temp1[i1] = str[i];
                i1++;
            } else {
                temp2[i2] = str[i];
                i2++;
            }
        }
    }

    // Note that we'll check the validity of the 2nd sub-substring only if
    // the 1st sub-substring is "N"
    if(strcmp(temp1,"N") == 0){
        *newSeq = true; // update the newSeq flag
        // if the sub-substring contains any additional character or a minus or more than 1 decimal then return false 
        if(additionalCharacters(temp2) || !characterCount(temp2,'-',0) || !characterCount(temp2,'.',1)){
            return false;
        }

        float x;
        sscanf(temp2, "%f", &x); //convert the sub-substring to float
        sscanf(temp2, "%d", size); //convert the sub-substring to integer

        // (0 < x < 1) or (x % size != 0 given that size != 0)
        // then return false 
        if((x > 0 && x < 1) || (*size != 0 && fmod(x, *size) != 0)) {
            return false;
        } return true;

    } else if(strcmp(temp1,"A") == 0) {
        *newSeq = false; // update the newSeq flag
        return true;
    
    } else { // if the 1st sub-substring is neither 'A' nor 'N'
        return false;
    }   
}


// returns false if there is any comma in the place of a space and vice-versa OR 
// if there is a missing comma or a space
bool checkSpaces_and_Commas(char str[], int size, bool newSeq, int k){
    int spaceCount = 0, commaCount = 0; //they keep track of the number of spaces and number of commas respectively
    int i, limit = strlen(str), t;

    if(k == 1){ // if current substring is 1st substring 
        t = 0;
    } else {
        t = 1;
    }
    
    // while looping, if the current character is a comma or a space
    // then it is set to true else false
    bool seperatorFlag = false;


    // replacing the seperators(commmas and spaces) with '\0' so that
    // we can easily extract the substrings to store the values in vectors
    for(i=0; i<limit; i++){
        if(str[i] == ','){
            commaCount++;
            seperatorFlag = true;
            str[i] = '\0';
        } else if(str[i] == ' '){
            spaceCount++;
            seperatorFlag = true;
            str[i] = '\0';
        } 

        // If at all a new seperator(comma or space) is encountered, its 
        // validity will be checked depending on whether the substring
        // is corresponding to a new sequence or coreesponding to the 
        // addition of element to an already existing sequence. If the position
        // of the newly encountered seperator is valid, loop will "continue" else 
        // false will be returned 
        if(newSeq && seperatorFlag){
            seperatorFlag = false;
            if(t == 1 && (commaCount == 0 && spaceCount < 2)){
                continue;
            } else if (spaceCount == t && commaCount < 2){
                continue;
            } else if (commaCount == 1 && spaceCount < t+2){
                continue;
            } else if (spaceCount == t+1 && commaCount < size+1){
                continue;
            } else if (commaCount == size && spaceCount < t+3){
                continue;
            } else {
                return false;
            } 
        } else if(seperatorFlag) {
            seperatorFlag = false;
            if(commaCount == 0 && spaceCount < 2){
                continue;
            } else if (spaceCount == 1 && commaCount < 3){
                continue;
            } else if (commaCount == 2 && spaceCount < 3){
                continue;
            } else {
                return false;
            }
        }
    } return true;
}


// returns true i.e. results in successful storing of values in vectors ONLY IF
// there are NO missing delimitters. The delimitters should be at the correct 
// positions and their values should be none other than "-1". Also, each of
// the substring values that are to be stored in the give vectors(of type double),
// should be a perfect POSITIVE REAL number. Anything other than that would result in a false return.   
bool storeSequences(vector<vector<double>> &sequences, char str[], int size, int len, bool newSeq, vector<Histogram> &hList, vector<DataSequence> &dataSeq){
    int i=0;//iterative variables
    char *ptr = str;
    if(strcmp(ptr,"") == 0) {ptr++; i++;}
    i += strlen(ptr)+1; //skipping the 1st sub-substring as we'd already check it using 
                        // "computeSize()" funtion
    ptr += strlen(ptr)+1;

    int j = 2; // stores the index of each sub-substring(as the given substring str is splitted using
               // '\0' instead of comma and spaces); with starting index as 1
    
    double x;// temporary variable
    
    if(newSeq){ // if new sequence
        if(size == 0){
            return true;
        }
        Histogram h = Histogram(); // creating a new Histogram object
        hList.push_back(h); // add it to the list

        // pass the reference of the currently pushed Histogram object to
        // the newly created DataSequence object
        DataSequence d = DataSequence(hList.back()); 
        
        // this seq will be pushed in the 2d vector of sequences, 
        // explicitly maintained for main()
        vector<double> seq; 

        //skipping the 2nd sub-substring as we'd already check it using 
        // "computeSize()" funtion
        i += strlen(ptr)+1;
        ptr += strlen(ptr)+1; j++;

        while(i < len){//looping through the string, we'll extract each substring and if
                    //they are valid or not, corresponding to their positions in the string
            if(j > size+2) { return false; }

            // if the substring contains any additional character or a minus or 
            // more than 1 decimal point then return false
            if(additionalCharacters(ptr) || !characterCount(ptr, '-', 0) || !characterCount(ptr, '.', 1)){
                return false;
            
            } else {
                sscanf(ptr, "%lf", &x);//converting substring to a double
                
                seq.push_back(x); // add the element to the seq which will in turn be added to the 2d vector
                d.addElement(x); // add the element to d which will in turn be added to DataSeq vector 
            }
            j++;//update the substring index
            i += strlen(ptr)+1;//update the iterative variable
            ptr += strlen(ptr)+1;//update the pointer to point to the next substring
        }

        sequences.push_back(seq); // add the new seq to the 2d vector of main()
        dataSeq.push_back(d); // add the new DataSequence object to DataSeq vector
        return true;
    
    } else { // if we only need to update an already existing sequence
        int index;
        while(i < len){//looping through the string, we'll extract each substring and if
                    //they are valid or not, corresponding to their positions in the string

            if(j > 3){ return false; }

            // if the substring contains any additional character or a minus or 
            // more than 1 decimal point then return false
            if(additionalCharacters(ptr) || !characterCount(ptr, '-', 0) || !characterCount(ptr, '.', 1)){
                return false;
            
            } else {
                sscanf(ptr, "%lf", &x);//converting substring to a double
                
                if(j == 2){//if x is zero then return false else store it in corresponding vector
                    sscanf(ptr, "%d", &index);
                    if(x < 0 || x > sequences.size()) { 
                        return false; 
                    } else if(x > 0 && x < 1){
                        return false;
                    } else if(x != 0 && fmod(x,index) != 0){
                        return false;
                    }
                
                } else {
                    sequences[index].push_back(x); // add the element to the corresponding sequence in 2d vector
                    dataSeq[index].addElement(x); // add the element to the corresponding DataSequence object
                }
            }
            j++;//update the substring index
            i += strlen(ptr)+1;//update the iterative variable
            ptr += strlen(ptr)+1;//update the pointer to point to the next substring

        } return true;
    }
}


int main(){
    bool correctInputFlag;  
    char *str = new char[100000];
    
    // the input from console is taken as a single long string(sentence)
    cin.get(str, 100000);
    int i, len = strlen(str);

    //Q.  What is being done with the string input?
    //Ans Let the string be: "N,2,1,0 -1 N,1,2 -1 A,0,4 -1" then:
    // this string is split into substrings by replacing "-1" by "\0\0", each
    // sunstring is then extracted. The substrings that we'll get for this ex are:
    // 1. "N,2,1,0 "   
    // 2. " N,1,2 "
    // 3. " A,0,4 "
    // And then each substring is seperately checked for its validity(through 3 stages) by splitting
    // them in sub-sub-string by replacing the commas and spaces by '\0'
    // Note that every substring starts with a ' '(blank character); except the 1st substring.
    // So we need to take care of this exceptional case for the 1st substring while checking for 
    // its validity   

    // the last character of the string has to be '1' and
    // the 2nd last character has to be '-' for string to be valid
    if(str[len-2] != '-' || str[len-1] != '1'){
        cout << "-1\n";
        return 0;
    }

    // each delimitter is checked if it is valid or NOT i.e. -1 or not
    // If we have a valid delimitter we'll replace it with "\0\0"
    // else we'll print "-1" and exit main()  
    int subStringCount = 0;
    for(i = 0; i < len; i++){
        if(str[i] == '-'){
            if(str[i+1] != '1'){
                cout << "-1\n";
                return 0;
            } else {
                str[i] = '\0';
                str[i+1] = '\0';
                subStringCount++;
            }
        }
    }

    int sizeOfSeq, subStrLen = 0;
    char *subStr = str;

    // a boolean flag to check whether we've got a new sequence which is needed
    // to be added(if newSeq=true) or do we just need to update an already 
    // existing sequence(if newSeq = false)
    bool newSeq = false;

    // stores a list of original sequences explicitly in main(). It is NOT manipulated
    vector<vector<double>> sequences;
    
    // stores a list of histogram for sequences explicitly in main(). A reference of 
    // each of these histogram is passed to the corresponding DataSequence object, stored
    // in the dataSeq vector
    vector<Histogram> histList;
    
    // we 'reserve' to prevent the vector from reallocating the memory each time its 
    // size varies, since it would tamper the addresses of the stored Histogram objects
    // which would be a problem as we've used the reference of these very Histogram objects in the
    // DataSequence objects
    histList.reserve(10000);
    
    vector<DataSequence> dataSeq;
   
    // the MAIN LOOP. Each sustring is extracted, stored in 'temp' char array
    // checked for its validity through 3 stages. If valid then:
    // 1. either a new sequence is created and stored(if newSeq=true) OR
    // 2. existing sequence is updated(newSeq=false)
    for(i = 1; i <= subStringCount; i++){
        subStrLen = strlen(subStr);
        char *temp = new char[subStrLen+3];

        strcpy(temp, subStr);

        // STAGE 1
        correctInputFlag = computeSize(temp, &sizeOfSeq, i, &newSeq);//size of vector is computed and stored in sizeOfVector
                                                        // if inputs valid as per stage 1
        if(!correctInputFlag){
            cout << "-1\n";
            return 0;
        }

        // STAGE 2
        correctInputFlag = checkSpaces_and_Commas(temp, sizeOfSeq, newSeq, i);//checking for validity of seperators and replacing
                                                                    //them with '\0' if inputs valid as per stage 2
        if(!correctInputFlag){
            cout << "-1\n"; 
            return 0;
        }

        // STAGE 3

        // stores or updates a sequence if input valid as per stage 3
        correctInputFlag = storeSequences(sequences, temp, sizeOfSeq, subStrLen, newSeq, histList, dataSeq); 
                                                                                                         

        if(!correctInputFlag){
            cout << "-1\n"; 
            return 0;
        }

        subStr += subStrLen+2;
    }

    // printing the fiveNumberSummary, intervals and normalized frequencies
    // for each data sequence; using the overloaded operator
    for(DataSequence d: dataSeq){
        d.normalize();
        d << cout;
    }

    return 0;
}


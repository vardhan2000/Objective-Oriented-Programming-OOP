#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** I could have done everything in main but for modularity and reusability, I've made functions :)) **/

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

// returns false if there is any comma in the place of a space and vice-versa OR 
// if there is a missing comma or a space
bool checkSpaces_and_Commas(char str[], int size){
    int spaceCount = 0, commaCount = 0; //they keep track of the number of spaces and number of commas respectively
    int i, limit = strlen(str);
    
    // replacing the seperators(commmas and spaces) with '\0' so that
    // we can easily extract the substrings to store the values in vectors
    for(i=0; i<limit; i++){
        if(str[i] == ','){
            commaCount++;
            str[i] = '\0';
        } else if(str[i] == ' '){
            spaceCount++;
            str[i] = '\0';
        } 

        // if commaCount = 0 then spaceCount should be less than 3  
        if(commaCount == 0 && spaceCount < 3){
            continue;

        // if spaceCount = 2 then commaCount should be less than size
        } else if(spaceCount == 2 && commaCount < size){
            continue;

        // if commaCount = size-1 then spaceCount should be less than 5
        } else if(commaCount == size-1 && spaceCount < 5){
            continue;

        // if spaceCount = 4 then commaCount should be less than 2size-1
        } else if(spaceCount == 4 && commaCount < (2*size)-1){
            continue;

        // if commaCount = 2size-2 then spaceCount should be less than 6    
        } else if(commaCount == (2*size)-2 && spaceCount < 6){
            continue;
        } else {
            return false;
        }
    } return true;
}


// computes size of vector ONLY IF 1st input i.e. the substring before the
// 1st seperator(comma or a space), is a perfect positive integer. ANYTHING other than
// that would result in a "false" return. NOTE that 4.00 is allowed as it is a POSITIVE integer
// but 4.010 is NOT allowed as it is a fraction 
bool computeSize(char str[], int *size){
    
    //extract the 1st substring
    int i, limit = strlen(str);
    char *temp = (char *)calloc(1000, sizeof(char));
    for(i = 0; i < limit; i++){
        if(str[i] == ',' || str[i] == ' '){
            temp[i] = '\0';
            break;
        } temp[i] = str[i];
    }     

    float x;
    // if the substring contains any additional character or a minus or a decimal then return false 
    if(additionalCharacters(temp) || !characterCount(temp,'-',0) || !characterCount(temp,'.',1)){
        return false;
    }
    sscanf(str, "%f", &x); //convert the substring to float
    sscanf(str, "%d", size); //convert the substring to integer
    if(size <= 0 || fmod(x, *size) != 0) { // if integer is zero then return false
    	return false;
    } return true;
}


// returns true i.e. results in successful storing of values in vectors ONLY IF
// there are NO missing delimitters. The delimitters should be at the correct 
// positions and their values should be none other than "-1". Also, each of
// the substring values that are to be stored in the give vectors(of type double),
// should be a perfect POSITIVE REAL number. Anything other than that would result in a false return.   
bool storeVectors(double vector1[], double vector2[], char str[], int size, int len){
    int i=0, k1=0, k2=0; //iterative variables
    char *ptr = str;
    i += strlen(ptr)+1; //skipping the 1st substring as we'd already check it using 
                        // "computeSize()" funtion
    ptr += i;
    int j = 2; // stores the index of each substring(as the given string str is splitted using
               // '\0' instead of comma and spaces); with starting index as 1
    
    double x;// temporary variable

    while(i < len){//looping through the string, we'll extract each substring and if
                   //they are valid or not, corresponding to their positions in the string

        //substrings at indices 2,3,2size+4 should be a delimitter i.e
        //it should be equal to -1 for the input to be valid
        if(j == 2 || j == size+3 || j == (2*size)+4){
            if(strcmp("-1",ptr) != 0){
                return false;
            }
        
        //substrings at other indices should be a valid POSITIVE REAL number
        } else {

            // if the substring contains any additional character or a minus or 
            // more than 1 decimal point then return false
            if(additionalCharacters(ptr) || !characterCount(ptr, '-', 0) || !characterCount(ptr, '.', 1)){
                return false;
            
            } else {
                sscanf(ptr, "%lf", &x);//converting substring to a double
                if(x <= 0){//if x is zero then return false else store it in corresponding vector
                    return false;
                }
                
                if(j <= size+2){
                    vector1[k1] = x;
                    k1++;
                } else {
                    vector2[k2] = x;
                    k2++;
                }
            }
        }
        j++;//update the substring index
        i += strlen(ptr)+1;//update the iterative variable
        ptr += strlen(ptr)+1;//update the pointer to point to the next substring
    }

    //for valid inputs, the number of substrings should be equal to
    //2size+4. Hence, the value of j after the loop ends, should be 2size+5.
    //If it is not so, then return false
    if(j != (2*size)+5){
        return false;
    } return true;
}


//convert the given vector to a normalized one
void normalize(double v[], int size){
    int i;
    double sum = 0;
    for(i=0; i<size; i++){
        sum += v[i];
    }

    for(i=0; i<size; i++){
        v[i] = v[i]/sum;
    }
}

//returns the Manhattan distance for given vectors
double ManhattanDistance(double v1[], double v2[], int size){
    double distance = 0;
    int i;
    for(i=0; i<size; i++){
        distance +=  fabs(v1[i]-v2[i]);
    } return distance;
}

//returns the Euclidean distance for given vectors
double EuclideanDistance(double v1[], double v2[], int size){
    double distanceSquare = 0, distance;
    int i;
    for(i=0; i<size; i++){
        distanceSquare += pow(v1[i]-v2[i], 2);
    } distance = sqrt(distanceSquare);

    return distance;
}

//returns the Chebyshev distance for given vectors
double Chebyshev_distance(double v1[], double v2[], int size){
    double distance = 0;
    int i;
    for(i=0; i<size; i++){
        if(distance < fabs(v1[i]-v2[i])){
            distance = fabs(v1[i]-v2[i]);
        }
    } return distance;
}

//returns the KL divergence for given vectors
double KL_divergence(double v1[], double v2[], int size){
    double kl_divergence=0;
    int i;
    for(i=0; i<size; i++){
        kl_divergence += v1[i] * log(v1[i]/v2[i]);
    } return kl_divergence;
}

//returns the JS distance for given vectors
double JS_distance(double v1[], double v2[], int size){
    double js_divergence, js_distance, median[size];
    int i;

    //making the median vector
    for(i=0; i<size; i++){
        median[i] = (v1[i]+v2[i])/2;
    }

    js_divergence = (0.5*KL_divergence(v1,median,size))+(0.5*KL_divergence(v2,median,size));
    js_distance = sqrt(js_divergence);//NOTE that JS distance is the squre root of the JS divergence
    return js_distance;
}

static inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

int main(){
    bool correctInputFlag;  
    char *str = (char *)calloc(100000, sizeof(char));

    //the input from console is taken as a string
    scanf("%[^\n]%*c", str);
    int sizeOfVector;

    //The validity of inputs will be checked at 3 stages. If at all given inputs pass
    // through all these stages, will we compute the different distances for the
    // given input 

    // STAGE 1
    correctInputFlag = computeSize(str, &sizeOfVector);//size of vector is computed and stored in sizeOfVector
                                                       // if inputs valid as per stage 1
    if(!correctInputFlag){
        printf("-1\n");
        return 0;
    }

    // STAGE 2
    int len = strlen(str);
    correctInputFlag = checkSpaces_and_Commas(str, sizeOfVector);//checking for validity of seperators and replacing
                                                                 //them with '\0' if inputs valid as per stage 2
    if(!correctInputFlag){
        printf("-1\n");
        return 0;
    }

    //STAGE 3
    double vec1[sizeOfVector], vec2[sizeOfVector];
    correctInputFlag = storeVectors(vec1, vec2, str, sizeOfVector, len);//stores the values in corresponding 
                                                                        //vectors if inputs valid as per stage 3
    if(!correctInputFlag){
        printf("-1\n");
        return 0;
    }

    //normalize(vec1, sizeOfVector); normalize(vec2, sizeOfVector);
    double distances[5];

    distances[0] = ManhattanDistance(vec1,vec2,sizeOfVector);
    distances[1] = EuclideanDistance(vec1,vec2,sizeOfVector);
    distances[2] = Chebyshev_distance(vec1,vec2,sizeOfVector);

    //computing KL distance
    distances[3] = KL_divergence(vec1,vec2,sizeOfVector) + KL_divergence(vec2,vec1,sizeOfVector);
    
    distances[4] = JS_distance(vec1,vec2,sizeOfVector);

    //printing the output
    int i;
    double dd;
    for(i=0; i<5; i++){
        dd = truncfunc(distances[i]);
        if(i<4){
            printf("%0.4lf,", dd);
        } else {
            printf("%0.4lf\n", dd);
        }
    }
}

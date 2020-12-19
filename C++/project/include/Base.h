#ifndef BASE_H_
#define BASE_H_


/*
    IMT2019062 - Pranjal Walia
        !WARNING!
        - Do not attempt to modify this file.
        - It is an abstract class to be implemented by all the tasks
*/

#include<bits/stdc++.h>
class Base{
    public:
        virtual void read(std::string fileName) = 0;
        virtual void process() = 0;
        virtual void write() = 0;
};


#endif // BASE_H_

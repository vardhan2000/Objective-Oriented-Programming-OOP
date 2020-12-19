#include<bits/stdc++.h>

#include "../include/Base.h"

//! task5 includes
#include "../include/Edge.h"
#include "../include/Node.h"
#include "../include/UCINET_DL_Filter.h"


//! task2 includes
#include "../include/Image_Rotate.h"


//! task6 includes 
#include "../include/Face.h"
#include "../include/Vertex.h"
#include "../include/Triangle.h"
#include "../include/PLY_Filter.h"


//! task7 includes
#include "../include/PPMI.h"


//! task 8 includes
#include "../include/CSV_Reader.h"

using namespace std;


//! utility function to tokenise the input filename and determine extension
//! based on extension, create the instance of the appropriate file reader
vector<string> tokenize(string line , char delimeter){
    vector <string> tokens; 
    stringstream check1(line); 
    string intermediate; 
    while(getline(check1, intermediate, delimeter)) {   
        intermediate.erase(remove(intermediate.begin(), intermediate.end(), ' '), intermediate.end()); 
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

//2(.ppm) 5(.dl) 6(.ply) 7(.ppm) 8(.csv)

/*
    IMT2019062 Pranjal Walia
    !WARNING!
        - Do not modify this file
    
INSTRUCTIONS:
    - From './src/'
    - Compile using:
        $ make
        $ ./output <input_file_with_extension> <additional_arguments_for_task8_only>
        $ make clean

            or (If "make" not installed)

        $ g++ *.cpp -o output
        $ ./output <input_file_with_extension> <additional_arguments_for_task8_only>

*/

int32_t main(int argc, char **argv){

    if(argc == 1){
        cout << "Invalid Arguments, try again!" << endl;
        return 0;
    }

    map<string,string>tasks = {
        {"ascii" , "Task2"} , 
        {"dl" , "Task5"}, 
        {"ply" , "Task6"},
        {"ppm" , "Task7"},
        {"csv" , "Task8"}
    };

    
    string fileName = argv[1]; 
    cout << "Fetching required File: " << endl;
    vector<string> arguments = tokenize(fileName , '.');
    string extension = arguments[1];
    string task = tasks[extension];
    cout << "Executing for fileName: " << fileName << " for " << task << endl;

    //! check the task compatible by extension of input file on runTime
    //! assign the appropriate task instance to the base pointer 
    Base *current;

    if(task == "Task2"){
        cout << "Parsed the ascii.ppm file for Rotation" << endl;
        current = new Task2;
        current->read(fileName);
        current->process();
        current->write();
    }
    else if(task=="Task5"){
        cout << "Parsed the file for dl Filtering..." << endl;
        current = new Task5;
        current->read(fileName);
        current->process();
        current->write();
    }
    else if(task == "Task6"){
        cout << "Parsed for ply filtering..." << endl;
        current = new Task6;
        cout << "read" << endl;
        current->read(fileName);
        current->process();
        cout << "process" << endl;
        current->write();
        cout << "end write" << endl;
    } 
    else if(task == "Task7"){
        cout << "Parsed the PPM file for grayscale operation" << endl;
        current = new PPMI;
        current->read(fileName);
        current->process();
        current->write();
    }
    else if(task == "Task8"){
        cout << "Parsed the CSV successfully" << endl;
        int rowstart = std::stoi(argv[2]);
        int colmnstart = std::stoi(argv[3]);
        current = new Task8(rowstart,colmnstart);
        current->read(fileName);
        current->process();
        current->write();
    }




    // if(task == "Task2"){
    //     cout << "Parsed the ascii.ppm file for Rotation" << endl;
    //     Task2 current;
    //     current.read(fileName);
    //     current.process();
    //     current.write();
    // }
    // else if(task=="Task5"){
    //     cout << "Parsed the file for dl Filtering..." << endl;
    //     Task5 current;
    //     current.read(fileName);
    //     current.process();
    //     current.write();
    // }
    // else if(task == "Task6"){
    //     // Task6 current;
    //     // current.read();
    //     // current.process();
    //     // current.write();
    // } 
    // else if(task == "Task7"){
    //     cout << "Parsed the PPM file for grayscale operation" << endl;
    //     PPMI current;
    //     current.read(fileName);
    //     current.process();
    //     current.write();
    // }
    // else if(task == "Task8"){
    //     cout << "Parsed the CSV successfully" << endl;
    //     int rowstart = std::stoi(argv[2]);
    //     int colmnstart = std::stoi(argv[3]);
    //     Task8 current(rowstart,colmnstart);
    //     current.read(fileName);
    //     current.process();
    //     current.write();
    // }
    return 0;
}
#include "../include/Image_Rotate.h"
#include<sstream>
#include<fstream>

//! these three functions will only be called in main, so make sure your code works in accordance with this 

void Task2::read(std::string filename){ 
	
	// creating an ifstream object
	ifstream fin; 

	// "red", "green" and "blue" store the correponding color intensities
	// for each pixel
	string line, red, green, blue;
  
    // opening the given ppm file
    fin.open("../inputs/" + filename); 
	
	// reading the image headers and comment
	int i;
	for(i=0; i<4; i++){
		getline(fin, line);
		lines.push_back(line);
	}

	// extracting words from the file (where 
	// each word is the triplet for each corresponding pixel);
	// and then storing it in lines vector 
    while (fin >> red){ 
        string word = "";
		fin >> green;
		fin >> blue;
		word += red + " " + green + " " + blue + "  ";
		lines.push_back(word);
    } 
	// Close the file 
    fin.close();
}

// modifies the pixel triplets in lines vector from
// rgb to bgr
 void Task2::process(){
 	//! impelement all your workflow here, call any other functions as required after defining in this file
	int i, limit = lines.size();
	
	
	for(i=0; i<limit; i++){
	
		// do NOT make any change in the image headers and comments 
		if(i == 0 || i == 1 || i == 3){
			continue;
		}

		string newline = "", col, red, green, blue;
		istringstream iss(lines[i]);
		if(i == 2){
			iss >> col;
			numOfcol = stoi(col); // store the number of columns of the image
			continue;
		}
		
		// create a new pixel triplet each time
		iss >> red;
		iss >> green;
		iss >> blue;
		newline += blue + " " + red + " " + green + "  ";

		// replace the old triplet with the new one
		lines[i] = newline;
	}
}



void Task2::write(){
	// Creation of ofstream class object 
    ofstream fout;

	// create a new file to write
	fout.open("../outputs/brg_file", ios::out);

	// Execute a loop If file successfully opened 
	int i = 0, limit = lines.size();
    while (fout) { 
        // Write line in file 
		if(i >= limit){
			break;
		}

		// print the image headers and comments as it is 
		if(i < 4){
        	fout << lines[i] << endl;
			i++;

		// each line of the brg file should contain the same number of triplets
		// as there are number of columns of the image
		} else {
			for(int j = 0; j < numOfcol; j++){
				fout << lines[i];
				i++;
			}
			fout << endl;
		}
    } 
  
    // Close the File 
    fout.close(); 
}

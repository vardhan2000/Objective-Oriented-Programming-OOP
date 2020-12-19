package baseClasses;

import java.util.ArrayList;

public class Lab {
	// is a parent class of BioChemLab and PathLab
	//  --------------------------------------------

	// stores list of tests
	private ArrayList<LabTest> tests = new ArrayList<>();

	public Lab(){ // Constructor

	}
	
	// getter of "tests" field
	public ArrayList<LabTest> getTests() {
		 return tests; 
	}
	
}
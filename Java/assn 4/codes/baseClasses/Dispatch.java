package baseClasses;

import java.util.ArrayList;

public class Dispatch {
	// Is given tests to be sent to customers
	// Keeps track of tests that have been given to it
	// -------------------------------------------------

	// stores test results
	private ArrayList<String> allResults = new ArrayList<>();

	public Dispatch(){ // Constructor

	}
	
	// stores the result of each test in the following format:-
	// <patientID> <testID> <testResult>
	public void processReport(LabTest test) {
		this.allResults.add(test.getPatientID() + " " + test.getTestID() + " " + test.getResult()); 
	}   // called by individual labs 

	
	// getter for "allResults" field
	public ArrayList<String> getAllResults() {
		return allResults;
	}
	
}
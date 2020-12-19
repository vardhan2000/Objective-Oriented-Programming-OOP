package derivedClasses;

import baseClasses.Lab;
import baseClasses.Dispatch; 

public class PathLab extends Lab {
	// generates its own TestID which is a string consisting of “B”,
	// “followed by a unique integer. Each lab starts with integer 1, and 
	// increments it for each new test. 
	// ------------------------------------------------------

	private static int cost = 1000; // stores the pathlab test price
	private static int pathTestCount = 1; // stores the number of path tests 
	
	private Dispatch dispatch = new Dispatch();

	public PathLab(Dispatch newDispatch){ // Constructor

		// to pass by reference the dispatch object created in
		// main method, so that we can send the test results for dispatch,
		// from the corresponding pathlab
		this.dispatch = newDispatch;
	}

	// getter for "pathTestCount"
	public static int getPathTestCount() {
		return PathLab.pathTestCount;
	}

	// getter for "cost" field
	public static int getCost() {
		return cost;
	}

	
	// generates the report, 
	// and then sends it to Dispatch using processReport
    public void addTest(PathLabTest test) {   
		
		// generating test report
		if(PathLab.pathTestCount % 3 == 0){
			test.setResult("malignant");
		} else {
			test.setResult("benign");
		}
		
		super.getTests().add(test); // adding the test to the lab record
		dispatch.processReport(test); // sending the test for dispatch
		
		PathLab.pathTestCount++;	
	}
}
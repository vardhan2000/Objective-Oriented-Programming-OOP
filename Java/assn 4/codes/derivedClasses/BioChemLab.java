package derivedClasses;

import baseClasses.Lab;
import baseClasses.Dispatch;

public class BioChemLab extends Lab {

	// generates its own TestID which is a string consisting of “B”,
	// “followed by a unique integer. Each lab starts with integer 1, and 
	// increments it for each new test. 
	// ------------------------------------------------------

	private static int cost = 400; // stores price of bioChemTest
	private static int bioTestCount = 1; // stores the number of bioChem tests done
	
	private Dispatch dispatch = new Dispatch();

	public BioChemLab(Dispatch newDispatch){ // Constructor 

		// to pass by reference the dispatch object created in
		// main method, so that we can send the test results for dispatch,
		// from the corresponding bioChemlab
		this.dispatch = newDispatch;
	}

	// getter "bioTestCount" field
	public static int getBioTestCount() {
		return BioChemLab.bioTestCount;
	}

	// getter for "cost" field
	public static int getCost() {
		return cost;
	}
	
	// generates the report, 
	// and then sends it to Dispatch using processReport
	public void addTest(BioChemTest test) {   
		
		// assigning the test result
		test.setResult(Integer.toString(99 + BioChemLab.bioTestCount));
		
		BioChemLab.bioTestCount++; // updating bioTestCount
		super.getTests().add(test); // adding the test to the lab records 
		dispatch.processReport(test); // sending the test to dispatch
	}

}
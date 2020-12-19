package baseClasses;

import java.util.ArrayList;

public class Reception {
	// Gets requests.
	// Generates a new ID for each test. These are sequential integers starting at 1
	// each day
	// Looks at the type (String - either Bio, Path) and creates an instance of an
	// appropriate subtype of the test
	// sends it to billing for the information to be recorded
	// sends the test (subtype instance) to the appropriate lab (It should be able to get
	// the reference to each type of lab from the Lab4B class through static methods)
	// -----------------------------------------------------------------------

	// stores the record for each patient(patient name, patientID, test etc.) 
	private ArrayList<ReceptionHelper> hospitalRecords = new ArrayList<ReceptionHelper>();
	
	// stores the info of the current patient
	private ReceptionHelper record;
	private Billing billing;

	public Reception(Billing newBilling){ // Constructor
		
		// to pass by reference the billing object in
		// main method, so that we can send a test for billing,
		// from reception
		this.billing = newBilling;
	}

	// getter for "record" field
	public ReceptionHelper getRecord() {
		return record;
	}


	// creates the appropriate sub-type of LabTest, 
	// adds that to Billing and 
	// then to the specific lab, after generating a patient ID
	public boolean addRequest(String testType, String patientName) { 
		
		// if testType is invalid 
		if(!testType.equals("Bio") && !testType.equals("Path")){
			return false;
		}
		
		record = new ReceptionHelper(testType, patientName);
		
		// adding patient info to hospital records
		hospitalRecords.add(record);
		
		// sending the new test for billing
		if(record.getBioTest() != null){
			this.billing.billTest(record.getBioTest());
		} else {
			this.billing.billTest(record.getPathTest());
		}

		return true;
		 	
	}
}
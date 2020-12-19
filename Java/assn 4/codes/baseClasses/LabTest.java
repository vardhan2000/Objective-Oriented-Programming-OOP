package baseClasses;

public class LabTest {
	// parent of BioChemTest and PathLabTest classes
	// -----------------------------------------

	private String patientID, testID, result;
	private int price;

	public LabTest(String ID) { // Constructor
		this.patientID = ID;
	}   // note that this should never get called explicitly
	
	// getter for "patientID" field
	public String getPatientID() {
		return patientID;
	}

	// setter for "testID" field
	public void setTestID(String testID) {
		this.testID = testID;
	}

	// setter for "price" field
	public void setPrice(int price) {
		this.price = price;
	}

	// getter for "testID" field
	public String getTestID() {
		return testID;
	}

	// getter for "result" field
	public String getResult(){
		return result;
	}

	// setter for "result" field
	public void setResult(String result) {
		this.result = result;
	}

	// getter for "price" field
	public int getPrice() {
		return price;
	}
}
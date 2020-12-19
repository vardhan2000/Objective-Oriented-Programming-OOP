package baseClasses;

import java.util.ArrayList;

public class Billing {
	// Is given tests to be billed
	// Keeps track of the tests that have been billed
	// --------------------------------------------

	// one string for each test
	// each string has testId and billed amount, separated by a space
	private ArrayList<String> bills = new ArrayList<>();
	
	private static int billingAmount = 0;

	public Billing(){ // Constructor

	}
	
	// updates the billingAmount by adding the price of the recent test
	// adds the billed test to its record(bills)
	void billTest(LabTest test) {
		Billing.billingAmount += test.getPrice();
		this.bills.add(test.getTestID() + " " + test.getPrice());

	}  // called by Reception
	
	// getter for "bills" field
	public ArrayList<String> getBills() {
		return bills; 
	} 

	// getter for "billingAmount" field
	public int getBillingAmount() {
		return Billing.billingAmount;
	}
	
}
import java.util.ArrayList;
import java.util.Scanner;

import baseClasses.Reception;
import baseClasses.Billing;
import baseClasses.Dispatch;
import baseClasses.LabTest;

import derivedClasses.BioChemLab;
import derivedClasses.PathLab;

public class Lab4B {

	public static void main(String[] args) {
		
		// create instance of Reception, Billing, Dispatch, BioChemLab, PathLab
		Billing billing = new Billing();
		Reception reception = new Reception(billing);
		Dispatch dispatch = new Dispatch();
		BioChemLab bioChemLab = new BioChemLab(dispatch);
		PathLab pathLab = new PathLab(dispatch);
		
		// stores bills of all tests, done in a day
		ArrayList<String> bills = new ArrayList<>();
		
		// stores the test reults of all tests, done in a day
		ArrayList<String> results = new ArrayList<>();

		// stores the list of all the tests of corresponding types,
		// done in a day
		ArrayList<LabTest> bioTests = new ArrayList<>();
		ArrayList<LabTest> pathTests = new ArrayList<>();

		Scanner myObj = new Scanner(System.in);
		int i; // iterative variable
		String test; // stores the string input for the test type

		
		// read in the input for test requests, and send to Reception (addRequest)
		int nextLines = myObj.nextInt();
		for(i = 0; i < nextLines; i++){
			test = myObj.next();
			reception.addRequest(test, null);
			if(test.equals("Bio")){
				Lab4B.sendToBioLab(reception, bioChemLab);
			} else if(test.equals("Path")) {
				Lab4B.sendToPathLab(reception, pathLab);
			}
		} myObj.close();
		
		// get all bills from Billing and print out the total for the day
		bills = billing.getBills();
		System.out.println("Total billed: " + billing.getBillingAmount());
		
		// get all reports from Dispatch and print out one line at a time
		// Each line will have: Patient ID, Test ID, result string
		results = dispatch.getAllResults();
		System.out.println("Reports:");
		for(String result: results){
			System.out.println(result);
		}
		
		// get list of tests from each lab, and print out total tests per lab
		bioTests = bioChemLab.getTests();
		pathTests = pathLab.getTests();
		System.out.println("Total tests:");
		System.out.println("BioChem: " + (BioChemLab.getBioTestCount()-1));
		System.out.println("Path: " + (PathLab.getPathTestCount()-1));
	}

	// sends a BioChemTest to BioChemLab, from reception
	public static void sendToBioLab(Reception counter, BioChemLab bioLab){
		bioLab.addTest(counter.getRecord().getBioTest());
	}

	// sends a PathLabTest to PathLab, from reception
	public static void sendToPathLab(Reception counter, PathLab pLab){
		pLab.addTest(counter.getRecord().getPathTest());
	}
	

}

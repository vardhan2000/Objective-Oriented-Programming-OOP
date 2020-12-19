package baseClasses;

import derivedClasses.BioChemTest;
import derivedClasses.PathLabTest;

public class ReceptionHelper {
    // It's just a helper class for the Reception class as
    // in the reception class has a field of type "ReceptionHelper"
    // ------------------------------------------------

    private String name; // stores patient's name
    
    // stores the test neede by the patient. If a certain test is 
    // NOT needed then test = null
    private BioChemTest bioTest = null;
    private PathLabTest pathTest = null;
    
    // stores the number of patients and is needed to
    // generate patientID
    private static int patientCount = 1;
    
    ReceptionHelper(String test, String patientName){ // Constructor
        this.name = patientName;
        
        // creating the specific type of 'test'(bioChemTest or pathTest)
        if(test.equals("Bio")){
            this.bioTest = new BioChemTest(Integer.toString(patientCount));
        } else {
            this.pathTest = new PathLabTest(Integer.toString(patientCount));
        }

        // updating the patient count
        ReceptionHelper.patientCount++;
    }

    // getter for "name" field
    public String getName() {
        return name;
    }

    // getter for "bioTest" field 
    public BioChemTest getBioTest() {
        return bioTest;
    }

    // getter for "pathTest" field
    public PathLabTest getPathTest() {
        return pathTest;
    }
}
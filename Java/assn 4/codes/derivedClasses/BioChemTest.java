package derivedClasses;

import baseClasses.LabTest;

public class BioChemTest extends LabTest {
     // used for generating specific type of test i.e. BioChemTest
     // ------------------------------------------

     // Constructor
	public BioChemTest(String patientId /* and any other arguments needed */) {
          super(patientId);

          // assigning test price and test ID
          super.setPrice(BioChemLab.getCost());
          super.setTestID("B" + Integer.toString(BioChemLab.getBioTestCount()));
     }
}
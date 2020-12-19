package derivedClasses;

import baseClasses.LabTest;

public class PathLabTest extends LabTest {
     // used for generating specific type of test i.e. BioChemTest
     // ------------------------------------------

     // Constructor
	public PathLabTest(String patientId /* and any other arguments needed */) {
          super(patientId);

          // assigning test price and test ID
          super.setPrice(PathLab.getCost());
          super.setTestID("P" + Integer.toString(PathLab.getPathTestCount()));
     }
}
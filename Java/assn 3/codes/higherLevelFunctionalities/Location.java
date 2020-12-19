package higherLevelFunctionalities;

// importing the Point class from "lowerLevelFunctionalities" package
import lowerLevelFunctionalities.Point;

public class Location {
    // Has a String locationName and an instance of Point that contains the coordinates.
    //                  ------------------------------------
    
    private String locationName; // stores the name of the location
    private Point p; // stores the coordinates of the location

    public Location(String Name, double x, double y){ // Constructor
        this.locationName = Name;
        this.p = new Point(x, y);  
    }

    // getter for "locationName" field
    public String getLocationName() {
        return locationName;
    }

    // getter for "p" field 
    public Point getP() {
        return p;
    }
}
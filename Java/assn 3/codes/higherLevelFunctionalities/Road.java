package higherLevelFunctionalities;

// importing Line class from "lowerLevelFuncionalities" package
import lowerLevelFunctionalities.Line;

public class Road {
    // builds on Line, is constructed with Locations as its end 
    // points, and also contains roadName (string), width (double). Obviously, 
    // no vehicle wider than “width” can use this road.
    //                 ------------------------

    private Line line; // stores the line on which the road is built 

    // "location1" and "location2" stores the 2 endpoints.
    // "endLocation" of a road depends on the route taken. The same
    // road in 2 differnet routes can have 2 differnet "endLocation" 
    private Location location1, location2, endLocation;
    
    private String roadName; // stores the name of the road
    private double width; // stores road's width

    public Road(Location loc1, Location loc2, String name, double Width){ // Constructor
        this.location1 = loc1;
        this.location2 = loc2;
        this.roadName = name;
        this.width = Width;
        this.line = new Line(loc1.getP(), loc2.getP());
    }

    // getter for "endLocation" field
    public Location getEndLocation() {
        return endLocation;
    }

    // setter for "endLocation" field
    public void setEndLocation(Location newEndLocation) {
        this.endLocation = newEndLocation;
    }

    // getter for "location1" field
    public Location getLocation1() {
        return location1;
    }
    
    // getter for "location2" field
    public Location getLocation2() {
        return location2;
    }

    // getter for "roadName" field
    public String getRoadName() {
        return roadName;
    }

    // getter for "width" field
    public double getWidth() {
        return width;
    }

    // getter for "line" field
    public Line getLine() {
        return line;
    }
}
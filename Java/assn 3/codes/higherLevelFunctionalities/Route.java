package higherLevelFunctionalities;

import java.util.ArrayList;
import lowerLevelFunctionalities.Line;

public class Route {
    // modelled as a list of Roads. We can assume that the roads of
    // a Route connect up end-to-end. That is, the end location of a road
    // in a route is the same as the start location of the next road in
    // the route. It also has a method that will return the length of the
    // Route, but we do not want this method to directly perform geometry
    // operations. It should rely on the “geometry” classes in the first
    // package to help with this. The class also has a static method
    // boolean isConnected(<list of Roads>)that checks if the roads form a
    // connected path, where the end location of a road is the same as
    // the start location of the next road in the list.
    //              ---------------------------------------

    // stores the list of rodes for a route, either connected
    // or disconnected
    private ArrayList<Road> roads = new ArrayList<>();
    
    // stores the list of lines on which the corresponding roads are built
    private ArrayList<Line> lines = new ArrayList<>();
    
    // stores the max width for a car that can traverse the route i.e.
    // it is minimum of all the widths of the roads in the route
    private double max_width;

    // stores the staring point(location) for a route
    private Location initialLocation;

    // maxWidth gets updated whenever a new road with the least width 
    // at that instant is added to a route. maxWidth is reset to -1 when
    // a new route starts
    private static double maxWidth = -1;

    public Route(){ // Constructor

    }

    // getter for "initialLocation" field
    public Location getInitialLocation() {
        return initialLocation;
    }
    
    // sets the initialLocation for a route. Is called once the 
    // "endLocation" of each of the roads in the route has been computed
    public void fixInitialLocation(){

        // if the intersection occurs at location1 then initialLocation
        // is location2, else initialLocation is location1
        if(this.roads.get(0).getLocation1().equals(this.roads.get(0).getEndLocation())){
            this.initialLocation = roads.get(0).getLocation2();
        } else {
            this.initialLocation = roads.get(0).getLocation1();
        }
    }

    // setter for "max_width" field
    public void setMax_width() {
        this.max_width = Route.maxWidth;
    }

    // getter for "max_width" field
    public double getMax_width() {
        return max_width;
    }

    // setter for "maxWidth", to reset it to -1 for every new route 
    public void setMaxWidth(double newMaxWidth) {
        Route.maxWidth = newMaxWidth;
    }

    // adds a new road to a route
    public void addRoad(Road newRoad){
        this.roads.add(newRoad);
        this.lines.add(newRoad.getLine());

        if(Route.maxWidth == -1 || Route.maxWidth > newRoad.getWidth()){
            Route.maxWidth = newRoad.getWidth();
        }
    }

    // getter for "roads" field
    public ArrayList<Road> getRoads() {
        return roads;
    }

    // returns the total length of a route using the totalLength()
    // method in Line class
    public double routeLength(){
        return Line.totalLength(this.lines);
    }

    // 1. sets the endLocation attribute for each road in a route.
    // 2. returns true if the route is connected else false
    public static boolean isConnected(ArrayList<Road> Roads){
        int i;
        for(i = 0; i < Roads.size()-1; i++){
            if(i == 0){
                if(Roads.get(i).getLocation1().equals(Roads.get(i+1).getLocation1())){
                    Roads.get(i).setEndLocation(Roads.get(i).getLocation1());
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation2());

                } else if(Roads.get(i).getLocation1().equals(Roads.get(i+1).getLocation2())) {
                    Roads.get(i).setEndLocation(Roads.get(i).getLocation1());
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation1());

                } else if(Roads.get(i).getLocation2().equals(Roads.get(i+1).getLocation1())) {
                    Roads.get(i).setEndLocation(Roads.get(i).getLocation2());
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation2());

                } else if(Roads.get(i).getLocation2().equals(Roads.get(i+1).getLocation2())) {
                    Roads.get(i).setEndLocation(Roads.get(i).getLocation2());
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation1());

                } else {
                    break;
                }
            } else {
                if(Roads.get(i).getEndLocation().equals(Roads.get(i+1).getLocation1())){
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation2());

                } else if(Roads.get(i).getEndLocation().equals(Roads.get(i+1).getLocation2())) {
                    Roads.get(i+1).setEndLocation(Roads.get(i+1).getLocation1());

                } else {
                    break;
                }
            }

        }

        if(i == Roads.size()-1){
            return true;
        }
        return false;
    }
}

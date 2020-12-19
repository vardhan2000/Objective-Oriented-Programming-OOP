// importing all the classes from package "higherLevelFunctionalities"
import higherLevelFunctionalities.*;

import java.util.ArrayList;
import java.util.Scanner;
import java.lang.Math;

public class TestClass{

    public static void main(String args[]){
        
        // stores the list of input locations
        ArrayList<Location> locations = new ArrayList<>();
        
        // stores the list of input roads
        ArrayList<Road> roads = new ArrayList<>();

        // stores the list of input routes(connected or not)
        ArrayList<Route> routes = new ArrayList<>();

        int i; // iterative variable

        // stores the number of next lines while inputting a list
        // of locations or roads or routes
        int nextLines = 0;
        Scanner myObj = new Scanner(System.in);

        
        nextLines = myObj.nextInt();

        int x, y;
        String name;
        
        // taking list of locations as input
        for(i = 0; i < nextLines; i++){
            x = myObj.nextInt();
            y = myObj.nextInt();
            name = myObj.next();

            // adding each location to the list of locations
            locations.add(new Location(name, x, y));
        }

        nextLines = myObj.nextInt();
        int index1, index2, width;

        // taking a list of roads as input 
        for(i = 0; i < nextLines; i++){
            index1 = myObj.nextInt();
            index2 = myObj.nextInt();
            name = myObj.next();
            width = myObj.nextInt();

            // generating a road object, with locations at index1 and index2 in 
            // the list of locations, as the road's end points and then adding this
            // road object to the list of roads
            roads.add(new Road(locations.get(index1), locations.get(index2), name, width));
        }

        nextLines = myObj.nextInt();
        int nextIndices, j; // j is just an iterative variable

        // taking list of routes as input
        for(i = 0; i < nextLines; i++){
            nextIndices = myObj.nextInt();
            routes.add(new Route());
            for(j = 0; j < nextIndices; j++){
                index1 = myObj.nextInt();
                routes.get(i).addRoad(roads.get(index1));
            }
    
            routes.get(i).setMax_width();
            routes.get(i).setMaxWidth(-1);
        }

        double length, breadth;
        for(i = 0; i < routes.size(); i++){
            boolean flag = Route.isConnected(routes.get(i).getRoads());
            
            if(flag){
                routes.get(i).fixInitialLocation(); 

                // storing the length and max width of the route to 2 decimal places
                // in "length" and "breadth"
                length = (double)Math.round(routes.get(i).routeLength() * 100) / 100;
                breadth = (double)Math.round(routes.get(i).getMax_width() * 100) / 100;
                
                // printing the output
                System.out.printf("Route %d: Length %.2f, max width %.2f", (i+1), length, breadth);
                System.out.print(": Start at " + routes.get(i).getInitialLocation().getLocationName() + ". ");
                
                for(j = 0; j < routes.get(i).getRoads().size(); j++){
                    System.out.print("Follow " + routes.get(i).getRoads().get(j).getRoadName());
                    System.out.print(" to " + routes.get(i).getRoads().get(j).getEndLocation().getLocationName() + ". ");
                }
                System.out.print("\n");
            
            // printing "Invalid route" in case route is NOT connected
            } else {
                j = i+1;
                System.out.println("Route " + (i+1) + ": Invalid route");
            }
        }

        myObj.close(); // closing the Scanner object
    }
}
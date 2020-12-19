package demo19003;
import java.util.ArrayList;

import base.*;

public class NetworkDemo extends Network {
    
    public NetworkDemo(){
        super();
        hubs = new ArrayList<>();
        highways = new ArrayList<>();
        trucks = new ArrayList<>();
    }

    @Override
    public void add(Hub hub) {
        hubs.add(hub);
    }

    @Override
    public void add(Highway hwy) {
        highways.add(hwy);
    }

    @Override
    public void add(Truck truck) {
        trucks.add(truck);
    }

    @Override
    protected Hub findNearestHubForLoc(Location loc) {
        int distanceSquare, temp;
        temp = distanceSquare = hubs.get(0).getLoc().distSqrd(loc);
        Hub nearestHub = hubs.get(0);
        for(Hub hub: hubs){
            temp = loc.distSqrd(hub.getLoc()); 
            if(distanceSquare > temp){
                distanceSquare = temp;
                nearestHub = hub;
            }
        } return nearestHub;
    }

    
    // calls draw method for each hub, highway and truck
    @Override
    public void redisplay(Display disp) {
        for(Hub hub: hubs){
            hub.draw(disp);
        }

        for(Highway highway: highways){
            highway.draw(disp);
        }

        for(Truck truck: trucks){
            truck.draw(disp);
        }
    }

    // calls start method for each hub and truck
    @Override
    public void start() {
        for(Hub hub: hubs){
            hub.start();
        }

        for(Truck truck: trucks){
            truck.start();
        }
    }

    private ArrayList<Hub> hubs;
    private ArrayList<Highway> highways;
    private ArrayList<Truck> trucks; 
}
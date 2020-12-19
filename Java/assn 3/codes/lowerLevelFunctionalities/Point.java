package lowerLevelFunctionalities;

import java.lang.Math;

public class Point {
    // defined by two double values – the x,y coordinates of the point. 
    // It provides methods to set and get the coordinate values, and 
    // get the distance to another point
    //                  -------------------------------

    // these fields store the corresponding x and y coordinates
    double x, y;

    public Point(double x_coord, double y_coord){ // Constructor
        this.x = x_coord;
        this.y = y_coord;
    }

    // calculates distance of current point from a given point
    public double distance(Point p){
        double dist = Math.pow((Math.pow(p.getX()-this.x, 2) 
                              + Math.pow(p.getY()-this.y, 2)), 0.5);
        return dist;
    }

    // setter for field x
    public void setX(double newX) {
        this.x = newX;
    }

    // getter for field x
    public double getX() {
        return x;
    }

    // setter for field y
    public void setY(double newY) {
        this.y = newY;
    }

    // getter for field y
    public double getY() {
        return y;
    }
}
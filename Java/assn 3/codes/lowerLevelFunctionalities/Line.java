package lowerLevelFunctionalities;

import java.util.ArrayList;

public class Line {
    // defined by two Point objects. It provides a method to return the 
    // length (double) of the Line object. It also has a static method 
    // that returns the total length of a list of Line objects.Thus, apart from
    //  constructors/destructors and access/update methods, 
    // the class Line has the following methods:
    // double length(); // returns length of the Line
    // static double totalLength(ArrayList<Line> lines) ; // returns total length of list of Lines
    //                 ---------------------------------------

    // line is defined by the corresponding end points(p, q)
    Point p, q;
    
    // stores the length of the line
    double len;

    public Line(Point p1, Point p2){ // Constructor
        this.p = p1;
        this.q = p2;
        this.len = this.length();
    }

    // getter for "len" field
    public double getLen() {
        return len;
    }

    // returns length of the line, using the distance
    //  method in the Point class
    private double length(){
        return this.p.distance(q);
    }

    // returns total length of list of Lines, using the "len" field
    public static double totalLength(ArrayList<Line> lines){
        double lengthSum = 0;
        int i;
        for(i = 0; i < lines.size(); i++){
            lengthSum += lines.get(i).getLen();
        }

        return lengthSum;
    }
}
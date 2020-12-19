package display;

import java.util.ArrayList;

import widgets.*;

public class Display {

	public Display(){

	}

	public void set(Panel p, int x0, int y0) {
		// add a Panel at location x0,y0
		p.setPos(new Location(x0, y0));
		this.panels.add(p);
	}
	
	public void redisplay() {
		// invokes draw of panels
		for(Panel panel: panels){
			panel.draw();
		}
	}
	
	public void registerClickable(Clickable c) {
		// maintains list of Clickables that have been registered. These will
		// be notified when processClick is invoked
		clickables.add(c);
	}
	
	public void processClick(int x, int y) {  // x,y in global coordinates of Display
		// passes on to all Clickables registerd
		for(Clickable clickable: clickables){
			clickable.onClick(new Location(x, y));
		}

		// invokes redisplay after each click
		this.redisplay();
	}
	
	
	// methods used by other classes to actually draw on the display
	public static void drawBox(int x0, int y0, int x1, int y1) {
		// draw a line from lower left x0,y0 to upper right x1, y1
		// for purposes of this exercise print to System.out:
		// Box from <x0>, <y0> to <x1>, <y1>
		System.out.println("Box from " + x0 + ", " + y0 + " to " + x1 + ", " + y1);
	}
	
	public static void drawText(int x0, int y0, String s) {
		// display a string starting at position x0, y0
		// for purposes of this exercise, print to System.out:
		// Text at <x0>, <y0> : <input string s>
		System.out.println("Text at " + x0 + ", " + y0 + " : " + s);
		
	}
	
	public static void drawCircle(int cx, int cy, int radius) {
		// draw a circle with given parameters
		// for purposes of this exercise, print to System.out:
		// Circle at <cx>, <cy> : radius <radius>
		System.out.println("Circle at " + cx + ", " + cy + " : radius " + radius);
	}
	
	private ArrayList<Panel> panels = new ArrayList<>();
	private ArrayList<Clickable> clickables = new ArrayList<>();
	
}

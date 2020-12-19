package widgets;

public abstract class Widget {
	Widget(int width, int height) {
		this.width = width;
		this.height = height;
	}
	
	public void setPos(Location p) {    // what is appropriate access specifier here?
		// position of lower left corner of widget in global coordinates of Display
		this.pos = p;
	}
	
	public Location getPos() {   // what is the appropriate access specifier here?
		return this.pos;
	}

	abstract protected void draw(); // widget uses methods of Display to draw an outline
					      // and any text within the outline
	// widgets should redraw themselves only if they have changed since last 
	// draw 
	

	// getter and setter for statusUpdate
	public boolean getStatusUpdate(){
		return statusUpdate;
	}

	public void setStatusUpdate(boolean statusUpdate) {
		this.statusUpdate = statusUpdate;
	}

	// returns the coordinates of the two corners of the widget
	// which are needed, when we make the "drawBox()" method call 
	protected int[] getCornerCoord(){
		int x0, y0, x1, y1;
			
		x0 = this.pos.getX();
		y0 = this.pos.getY();
		x1 = x0 + this.width;
		y1 = y0 + this.height;

		int[] arr = {x0, y0, x1, y1};
		return arr;
	}
	
	// add other protected/public methods as needed
	private int width, height;
	private Location pos;
	private boolean statusUpdate = true; // is used to check if a change is made in 
										 // a widget. A widget will be redrawn only if a change 
										 // has been made in the widget i.e. is its statusUpdate
										 // is set to true.
}

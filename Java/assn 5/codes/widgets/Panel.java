package widgets;

import java.util.ArrayList;
import display.Display;

public class Panel extends Widget {

	public Panel(int width, int height){ // Constructor
		super(width, height);
	}
	
	
	public void addWidget(Widget w, Location loc) {
		// add a child widget
		// position of lower left of child is at loc in Panel coordinates
		int newX, newY;
		newX = this.getPos().getX() + loc.getX();
		newY = this.getPos().getY() + loc.getY();

		w.setPos(new Location(newX, newY));
		this.widgets.add(w);
	}
	
	// implements/overrides draw. Draws a box corresponding to its size and
	// calls draw on each child widget
	
	@Override
	public void draw(){
		if(super.getStatusUpdate()){
			int[] cornerCoord = super.getCornerCoord();
			Display.drawBox(cornerCoord[0], cornerCoord[1], cornerCoord[2], cornerCoord[3]);
			
			super.setStatusUpdate(false);
		}

		for(Widget w: widgets){
			w.draw();
		}
	}
	
	private ArrayList<Widget> widgets = new ArrayList<>();
}

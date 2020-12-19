package countingApp;

import display.Display;
import widgets.Button;

public class Toggle extends Button {

	Toggle(int width, int height, String text){ // Constructor
		super(width, height);
		super.setText(text);

		if(text.equals("Up")){
			Toggle.upFlag = true;
		} else {
			Toggle.upFlag = false;
		}
	}
	
	// redefines draw so that it draws a circular outline 
	// (instead of the default rectangular outline of Button)
	// "position" of Toggle is defined as the lower left corner of the
	// box that would enclose the circle
	public void draw() {
		if(super.getStatusUpdate()){
			int cx, cy, radius;
			int[] cornerCoord = super.getCornerCoord();
			
			cx = (cornerCoord[0] + cornerCoord[2]) / 2;
			cy = (cornerCoord[1] + cornerCoord[3]) / 2;
			radius = (cornerCoord[2] - cornerCoord[0]) / 2;

			Display.drawCircle(cx, cy, radius);
			Display.drawText(cornerCoord[0], cornerCoord[1], super.getText());
			super.setStatusUpdate(false);
		}
	}
	
	
	// Toggles its state on each click. 
	// Displays the text "Up" or "Down" accordingly
	@Override
	protected void handleClick() {
		super.setStatusUpdate(true);
		
		if(upFlag){
			super.setText("Down");
			Toggle.upFlag = false;
		} else {
			super.setText("Up");;
			Toggle.upFlag = true;
		}
	}

	// has a method to get its current state
	public boolean get_upFlag_status(){
		return Toggle.upFlag;
	}
	
	private static boolean upFlag; 
}

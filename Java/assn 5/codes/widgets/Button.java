package widgets;

import display.Display;

public class Button extends Widget implements Clickable {
	
	public Button(int width, int height){ // Constructor
		super(width, height);
	}
	
	// methods to get & set text
	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}
	
	// implements/overrides draw to draw a box at the correct position and size
	// and displays the text of the button
	@Override
	protected void draw(){
		if(super.getStatusUpdate()){
			int[] cornerCoord = super.getCornerCoord();
			
			Display.drawBox(cornerCoord[0], cornerCoord[1], cornerCoord[2], cornerCoord[3]);
			Display.drawText(cornerCoord[0], cornerCoord[1], text);
			super.setStatusUpdate(false);
		}
	}
	
	// implement the onClick method to check if the click is within its bounds
	// and if so, invokes protected method handleClick
	public void onClick(Location p){
		int[] cornerCoord = super.getCornerCoord();
		
		if( (cornerCoord[0] < p.getX() && p.getX() < cornerCoord[2]) 
							&& (cornerCoord[1] < p.getY() && p.getY() < cornerCoord[3]) ){
			
			handleClick();
		}
	}
	
	protected void handleClick() {   // should we make this abstract?
									// No need. We can just override this method in the
									// child classes of "Button".
	}
	
	private String text;
}

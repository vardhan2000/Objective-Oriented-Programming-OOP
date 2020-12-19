package widgets;

import display.Display;

public class Label extends Widget {
	// has a text string as data - which is provided at create time
	// width and height are determined from this
	// assume each character is 5 units wide and 10 units high
	public Label(String text){
		super(text.length() * 5, 10);
		this.text = text;
	}

	public void draw(){
		if(super.getStatusUpdate()){
			int[] cornerCoord = super.getCornerCoord();
			
			Display.drawText(cornerCoord[0], cornerCoord[1], this.text);
			super.setStatusUpdate(false);
		}
	}

	// does not react to mouse events
	
	// provides methods to get text
	public String getText() {
		return text;
	}
	
	private String text;
}

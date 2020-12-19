package countingApp;

import widgets.Button;

public class Counter extends Button {

	Counter(int width, int height, Toggle newToggle, String text){ // Constructor
		super(width, height);
		this.toggle = newToggle;
		super.setText(text);
	} // has a reference to an instance of Toggle button
	
	
	 // Everytime it is clicked, it increments or decrements counter by 1
	// depending on state of the Toggle instance
	@Override
	protected void handleClick() {
		super.setStatusUpdate(true);

		int voteCount = Integer.parseInt(super.getText()); 

		if(toggle.get_upFlag_status()){
			super.setText(Integer.toString(voteCount+1));
		} else {
			super.setText(Integer.toString(voteCount-1));
		}
	}

	// to get the status of toggle by passing its reference	
	private Toggle toggle;	
}

package countingApp;


import display.Display;
import widgets.*;


public class CountingApp {
	public CountingApp(Display d) {
		// Display object made available at construction. Cannot be changed
		disp = d;
	}
	
	public void init() {
		// sets up widgets
		// create a Panel with location 50,50 and width 400, height 200
		Panel panel = new Panel(400,200);
		disp.set(panel, 50, 50);
		
		// creates the following widgets, which are added as children of this panel
		// Note locations are relative to Panel
		// - Toggle button:   location 100, 60 with respect to panel, size 50, 50
		// - Counter button:  location 200, 60, size 100, 40
		// - Label: location  150, 150, text: "Vote up or down"

		Toggle toggle = new Toggle(50, 50, "Up");
		panel.addWidget(toggle, new Location(100, 60));

		Counter counter = new Counter(100, 40, toggle, "0");
		panel.addWidget(counter, new Location(200, 60));

		Label label = new Label("Vote up or down");
		panel.addWidget(label, new Location(150, 150));
		
		// registers those widgets that are Clickable with Display
		disp.registerClickable(toggle);
		disp.registerClickable(counter);
		
		disp.redisplay();
	}
	
	private Display disp;
}

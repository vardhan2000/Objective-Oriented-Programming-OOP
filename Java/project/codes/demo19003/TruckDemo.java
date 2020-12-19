package demo19003;

import base.Highway;
import base.Truck;
import base.Hub;
import base.Location;
import java.lang.Math;

class TruckDemo extends Truck {

	public TruckDemo(){
		truckName = "Truck19003";
	}

	// getter for lastHub
	@Override
	public Hub getLastHub() {
		return lastHub;
	}

	@Override
	protected void update(int deltaT) {
		actualTime += deltaT; // updating the actualTime each time update is called
		destHub = NetworkDemo.getNearestHub(super.getDest()); // storing the destination hub for the truck

		// if journey is NOT complete and actualTime is more than start time of truck
		if(!hasReached && actualTime >= super.getStartTime()){
			if(!journeyStarted){ // if journey has NOT started yet
				//if(actualTime-deltaT < super.getStartTime() && actualTime > super.getStartTime()){
					srcHub = NetworkDemo.getNearestHub(super.getSource());			
				//}

				if(srcHub.add(this)){ // adding the truck to the its source hub
					journeyStarted = true; // start the journey
					currentHub = srcHub; // updating the current hub
					super.setLoc(currentHub.getLoc()); // update the current location of the truck
				} return;
			}

			if(hwyFlag){ // if truck is on a highway
				int x1, y1, x_inTruck, y_inTruck, x_finalTruck, y_finalTruck, x_Hub, y_Hub;
				x1 = highway.getStart().getLoc().getX(); // x coordinate of the start hub of the highway
				y1 = highway.getStart().getLoc().getY(); // y coordinate of the start hub of the highway
				x_Hub = highway.getEnd().getLoc().getX(); // x coordinate of the end hub of the highway
				y_Hub = highway.getEnd().getLoc().getY(); // y coordinate of the end hub of the highway
				x_inTruck = super.getLoc().getX();// initial x coordinate of truck
				y_inTruck = super.getLoc().getY(); // initial y coordinate of truck

				if(x_Hub-x1 == 0){ // if highway is vertical (i.e. slope is infinity)
					x_finalTruck = x_inTruck; // final x coordinate of truck remains unchanged
					if(y_Hub > y1){ // if highway is from down to up
						y_finalTruck = y_inTruck + (int)(this.highway.getMaxSpeed() * (deltaT * 0.004));

					} else { // if highway is from up to down
						y_finalTruck = y_inTruck - (int)(this.highway.getMaxSpeed() * (deltaT * 0.004));
					}

					// if the truck's tentative final y coord and truck's initial 
					// y coordinate lie on opposite side of hub, it implies the truck is stored in hub(if it is NOT a dest hub)  
					if((y_finalTruck >= y_Hub && y_inTruck < y_Hub) ||
						(y_finalTruck <= y_Hub && y_inTruck > y_Hub)){
						
						// if end hub of the highway is the same as the dest hub of the truck
						if(highway.getEnd().equals(this.destHub)){
							
							// update the corresponding data memeber values
							this.hasReached = true;
							super.setLoc(super.getDest()); // directly update the location of the truck
														   // to be the dest loc of the truck
							this.lastHub = highway.getEnd();
							this.nextHub = null;
							this.highway.remove(this); // remove the truck from the highway
							this.currentHub = null;
							this.hwyFlag = false;
							this.highway = null; 

						// if end hub of highway is NOT the dest hub of the truck
						} else {
							if(!highway.getEnd().add(this)) {return;} // if the end hub does NOT have enough capacity then return
							else{

								// update the corresponding data memeber values
								this.currentHub = highway.getEnd();
								this.lastHub = highway.getStart();
								this.nextHub = null;
								super.setLoc(highway.getEnd().getLoc()); // set location of truck to be the same as
																		 // location of end hub of the highway
								this.highway.remove(this);
								this.hwyFlag = false;
								this.highway = null;
							}
						}
						return;
					}
				
				} else { // if highway is NOT vertical
					double theta = Math.atan(Math.abs((double)(y_Hub-y1)/(x_Hub-x1))); // calculate angle in radians using slope
					double v_x, v_y;
					if(x_Hub > x1){ // if truck moving from left to right
						v_x = this.highway.getMaxSpeed() * Math.cos(theta); // v_x > 0
					} else { // if truck moving from right to left
						v_x = this.highway.getMaxSpeed() * Math.cos(theta) * (-1); // v_x < 0
					}
					
					if(y_Hub > y1){ // if truck moving from down to up
						v_y = this.highway.getMaxSpeed() * Math.sin(theta); // v_y > 0
					} else {
						v_y = this.highway.getMaxSpeed() * Math.sin(theta) * (-1); // v_y < 0
					}

					y_finalTruck = (int) Math.round(y_inTruck + (v_y * deltaT * 0.004)); // y_final = y_initial + (v_y * time)
					x_finalTruck = (int) Math.round(x_inTruck + (v_x * deltaT * 0.004)); // similarly

					// if the truck's tentative final x coord and truck's initial 
					// x coordinate lie on opposite side of hub, it implies the truck is stored in hub(if it is NOT a dest hub)
					if((x_Hub > x_inTruck && x_Hub <= x_finalTruck) || 
						(x_Hub < x_inTruck && x_Hub >= x_finalTruck)){
						
						// if end hub of the highway is the same as the dest hub of the truck
						if(highway.getEnd().equals(this.destHub)){
							
							// update the corresponding data memeber values
							this.hasReached = true;
							super.setLoc(super.getDest());// directly update the location of the truck
														  // to be the dest loc of the truck
							this.lastHub = highway.getEnd();
							this.nextHub = null;
							this.highway.remove(this); // remove the truck from the highway
							this.currentHub = null;
							this.hwyFlag = false;
							this.highway = null;
						
						// if end hub of highway is NOT the dest hub of the truck
						} else {
							if(!highway.getEnd().add(this)) {return;} // if the end hub does NOT have enough capacity then return
							else{
								// update the corresponding data memeber values
								this.currentHub = highway.getEnd();
								this.lastHub = highway.getStart();
								this.nextHub = null;
								super.setLoc(highway.getEnd().getLoc());// set location of truck to be the same as
																		// location of end hub of the highway
								this.highway.remove(this);
								this.hwyFlag = false;
								this.highway = null;
							}
						}
						return;
					}		
				}

				// if the truck is NOT added to a hub then update its location on the highway
				super.setLoc(new Location(x_finalTruck, y_finalTruck));
			}
		}
	}

	// getter for truckName
	@Override
	public String getTruckName() {
		return truckName;
	}

	// passes the information of the next highway to be entered(by the truck), to the truck
	@Override
	public void enter(Highway hwy) {
		highway = hwy;
		lastHub = currentHub;
		currentHub = null;
		nextHub = hwy.getEnd();
		hwyFlag = true;
	}

	private Highway highway;
	private int actualTime = 0;
	private Hub lastHub = null, currentHub = null, nextHub = null, destHub = null; // destHub should be exlusively used in truckDemo only
	private boolean hwyFlag = false, hasReached = false;
	private Hub srcHub;
	private boolean journeyStarted = false; // if true then partyy { ☆:. o(≧▽≦)o .:☆ }. Our journey has started(Yooo Hooo)
	private String truckName;
}

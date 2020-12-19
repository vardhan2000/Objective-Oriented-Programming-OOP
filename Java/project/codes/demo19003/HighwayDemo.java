package demo19003;

import java.util.ArrayList;

import base.Highway;
import base.Truck;

class HighwayDemo extends Highway {

	public HighwayDemo() {
		super();
		trucks = new ArrayList<>();
	}


	// checks if the highway has enough capacity to let another truck get added to it
	@Override
	public synchronized boolean hasCapacity() { 
		if(super.getCapacity() > trucks.size()){
			return true;
		}
		return false;
	}


	// adds the truck to the highway if the highway has enough capacity
	@Override
	public synchronized boolean add(Truck truck) {
		boolean flag = this.hasCapacity();
		if(flag){
			trucks.add(truck);
		}
		return flag;
	}

	// removes the truck from the highway
	@Override
	public synchronized void remove(Truck truck) {
		trucks.remove(truck);
	}

	private ArrayList<Truck> trucks; // stores the list of trucks on a highway

}

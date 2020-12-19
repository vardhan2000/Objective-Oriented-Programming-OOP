package demo19003;

import base.Highway;
import base.Hub;
import base.Location;
import base.Truck;

import java.util.ArrayList;
import java.util.Stack;
import java.util.HashMap;

class HubDemo extends Hub {

	public HubDemo(Location loc) {
		super(loc);
		trucks = new ArrayList<>();
	}

	@Override
	public synchronized boolean add(Truck truck) {
		Hub h = NetworkDemo.getNearestHub(truck.getDest()); // finding the source hub
		if(!this.equals(h)){ // if current hub is NOT equal to the destination hub
			if(super.getCapacity() > trucks.size()){ // check if the hub is at full capacity
				trucks.add(truck); // add the corresponding truck to the list
				return true; 
			} else { 
				return false;
			}
		} else { // if current hub is equal to the destination hub
			return true;
		}
	}

	@Override
	public synchronized void remove(Truck truck) { // remove the truck from the list of trucks
		trucks.remove(truck);
	}


	// computes the next highway at each node(hub) using the DFS
	/** Note: for DFS code I've taken help from the C code that "Murali Sir" provided in the 2nd sem **/
	@Override
	public Highway getNextHighway(Hub from, Hub dest) {
		// we'll use iterative DFS so we need to maintain a stack explicitly
		Stack<Hub> stack = new Stack<Hub>();

		// to avoid the error encoutered due to multithreading:

		// each function call would deal with a different parentHub hashmap(Phi[] array) 
		HashMap<Hub, Hub> parentHub = new HashMap<Hub, Hub>();
		// each function call would deal with a different flags hashmap(V[] array)
		HashMap<Hub, Boolean> flags = new HashMap<Hub, Boolean>();
		stack.push(this); // push the current hub(source node) onto the stack
		parentHub.put(this, null); // map this source node to its parent i.e. null
		flags.put(this, false); // map this source node to its boolean value i.e. false
		Hub h = null; // temporary variable

		while(!stack.empty()){
			h = stack.peek(); // look at top element of the stack
			
			if(!flags.get(h)){
				flags.replace(h, true); // change its boolean mapping to true
				ArrayList<Highway> highways = h.getHighways(); // get the list of outgoing highways of node h
				
				if(!highways.isEmpty()){// if the hub has some outgoing highways and hence some outgoing nodes
					for(Highway hwy: highways){
						
						// if the corresponding key(hub) is NOT there or
						// if the hub is mapped to a false boolean
						if(!flags.containsKey(hwy.getEnd()) || !flags.get(hwy.getEnd())){
							stack.push(hwy.getEnd()); // push the corresponding outgoing node(hub)
							parentHub.put(hwy.getEnd(), h); // map this outgoing node(hub) to the parent node(hub)  
						}
						flags.putIfAbsent(hwy.getEnd(), false);	// map this outgoing node(hub) to the boolean value(false) 
																// if the key node is NOT there
					}
				} else { // hub with NO outgoing highways(even though it won't happen). It is just a condition for DFS
					stack.pop(); 
				}
			} else { // hub with boolean mapping to be true
				stack.pop();
			}
		} // DFS ends.

		
		// Now using the DFS tree we can know the whole lineage(list of parents) for a given node.
		// So given the destination node(hub) here, we'll find its parent node just next to the source or 
		// root node(hub) in terms of superiority; which is indeed the next hub to which the truck is to be sent   
		Hub currentHub, prevHub = null;
		currentHub = dest;
		while(parentHub.get(currentHub) != null){
			prevHub = currentHub;
			currentHub = parentHub.get(currentHub);
		}
		
		// Computing the highway corresponding to the abouve found(next node i.e. hub)
		for(Highway highway: super.getHighways()){
			if(highway.getEnd().equals(prevHub)){
				return highway;
			}
		} return null;
	} 


	// notifies each truck(queued at a hub) for its correspondingly computed highway
	@Override
	protected synchronized void processQ(int deltaT) { // deltaT parameter has NOT been used
		ArrayList<Truck> removedTrucks = new ArrayList<>();// temporary arraylist to store each truck that are to be added to its 
														   // corresponding highway, which are later removed from the hub 
		
	   // we'll pass the info of the next highway to each corresponding truck using truck.enter()
	    Highway h = null;
		for(Truck truck: trucks){
			h = this.getNextHighway(truck.getLastHub(), NetworkDemo.getNearestHub(truck.getDest()));
			if(h.add(truck)){
				truck.enter(h);
				removedTrucks.add(truck);
			}
		}

		// removing the trucks from hub
		for(Truck truck: removedTrucks){
			this.remove(truck);
		}
		
	}

	private ArrayList<Truck> trucks; // stores the list of trucks for a hub
}

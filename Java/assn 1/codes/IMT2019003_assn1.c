#include<stdio.h>
#include<stdlib.h>

// Creating 2 seperate structures to store the attributes of diesel and electric car.
struct diesel_cars{
	int car_num;
	float fuel_efficiency, current_fuel_level;
};

struct electric_cars{
	int car_num;
	float fuel_efficiency, current_fuel_level;
};

// struct to store range of each car with the corresponding car number
struct range_of_cars{
	float range;
	int car_num;
};

int main(){
	int n, i; // i is just an iterative variable
	float temp_fuel_efficiency, temp_current_fuel_level;
	
	scanf("%d", &n);

	// array that stores car type i.e. diesel(1) or electric(2)
	int car_type[n];
	
	// allocating a dynamic array of type "diesel_cars" and "electric_cars"
	struct diesel_cars *ptr1 = (struct diesel_cars *)calloc(n, sizeof(struct diesel_cars));
	struct electric_cars *ptr2 = (struct electric_cars *)calloc(n, sizeof(struct electric_cars));

	// allocating a dynamic array of type "range_of_cars" to store the ranges
	struct range_of_cars *ranges = (struct range_of_cars *)calloc(n, sizeof(struct range_of_cars));	
	
	// taking and storing the inputs
	for(i = 0; i < n; i++){
			scanf("%d %f %f", &car_type[i], &temp_fuel_efficiency, &temp_current_fuel_level);

			// if car_type is diesel then store the inputs in the dynamic array of type "diesel_cars" 
			if(car_type[i] == 1){
				ptr1[i].car_num = i+1;
				ptr1[i].fuel_efficiency = temp_fuel_efficiency;
				ptr1[i].current_fuel_level = temp_current_fuel_level;
			}

			// else store the inputs in the dynamic array of type "electric_cars"
			else{
				ptr2[i].car_num = i+1;
				ptr2[i].fuel_efficiency = temp_fuel_efficiency;
				ptr2[i].current_fuel_level = temp_current_fuel_level;	
			}

	}

	for(i = n - 1; i >= 0; i--){

		// Calculating range if car is a diesel car
		if(car_type[i] == 1){
			ranges[i].range = ptr1[i].fuel_efficiency * ptr1[i].current_fuel_level;
			ranges[i].car_num = i+1;
		}

		
		// Calculating range if car is an electric car
		else{

			ranges[i].car_num = i+1;

			// (fuel_efficiency = 0) will be an invalid input as it will result in division by zero error
			// This code will output (range = 0) in this case
			if(ptr2[i].fuel_efficiency != 0)
				ranges[i].range = (ptr2[i].current_fuel_level * 1000) / ptr2[i].fuel_efficiency;
		}
		
		// printing the result
		printf("Car %d: range = %.2f\n", ranges[i].car_num, ranges[i].range);
	}
	
	/* Answers of extra questions given after the original question */

	// Ans 1)
	// If we want to add some more attributes for each car, we can easily do so
	// by adding those itmes to their respective structures.

	// Ans 2)
	// If we want to sort the list of cars in decreasing order of their ranges, 
	// we can do a merge sort on the "ranges" array on the basis of its range attribute.  
}

import java.util.Scanner;

class TestClass{
    // Contains the main method. This is the class which is to be compiled

    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int year, count = 0;
        int prevYear = 0;
        double costPrice;
        String temp;
        Store store = new Store();
        
        // loop runs until we've got "0 0" as inputs, twice
        while(count < 2){
            // reading inputs from the console
            year = myObj.nextInt();
            temp = myObj.next();
            
            // updating the iterative variable
            if(year == 0){
                count++;
                continue;
                
            // handling purchase info until the 1st "0 0" input is received
            } else if(count < 1) {
                costPrice = Integer.parseInt(temp);
                
                // resetting sequence number to 1 when year changes
                if(year != prevYear){
                    store.getPurchase().setSeqNum(1);
                }

                // keeping track of purchased books through Purchasing dept
                store.getPurchase().addPurchasedBook(year, costPrice);

                prevYear = year; // updating previous year
                
            // handling Sales info until the 2nd "0 0" input is received
            } else {

                // keeping track of sold books through Sales dept
                store.getSales().add_update_SoldBook(year, temp);
            }
        }

        // printing the output
        store.getSales().printSales();
        myObj.close();        
    }
}
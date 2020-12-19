import java.util.ArrayList;
import java.util.Collections;

/* Data members of a class should not be directly accessible by other classes. These
   should be manipulated only through appropriate methods provided by the class. */

class Sales{
    // records the id of the book and when it was sold. 
    
    // keeps track of the total revenue for books that were bought in that year, books bought
    // the previous year, books bought 2 years earlier etc. (It can find the year of
    // purchase of the book from the book id).
    //                                --------------------------
    
    private ArrayList<Book> purchased_book_list; // stores list of info about purchased books
    private ArrayList<SalesHelper> sold_book_list = new ArrayList<>(); // stores list of info about sold books
    private ArrayList<Integer> years = new ArrayList<>(); // stores the list of years in which any book was sold 
    
    
    // the following 2d array stores the revenues corresponding to say, year1  
    // at the index "year1" in the corresponding sub-array in the following format:
    // totalRevenue[year1][0] = <revenue from books bought in year1>
    // totalRevenue[year1][1] = <revenue from books bought in previous year>
    // totalRevenue[year1][2] = <revenue from books bought 2 years back>
    private double[][] totalRevenue = new double[3000][3]; 

    
    /* Never use "public void" or anything like that before a constructor */
    /* we do pass by reference for the arraylist in Store class so that we can 
       easily update the list of purchased books initialised in Store class, through 
       Sales class */
    Sales(ArrayList<Book> purchased_book_list){ // Constructor
        this.purchased_book_list = purchased_book_list;
        int i,j;
        for(i = 0; i < 3000; i++){
            for(j = 0; j < 3; j++){
                this.totalRevenue[i][j] = 0;
            }
        }
    }

    
    public void add_update_SoldBook(int year, String book_ID){ // add_update_SoldBook starts
        
        // 1. adding the newly sold book to the list of sold books
        this.sold_book_list.add(new SalesHelper(year, book_ID));
        
        // 2. maintaing the list of years in which any book was sold 
        if(!this.years.contains(year)){
            this.years.add(year);
        }
        
        // 3. updating the list of purchased books, i.e. removing the corresponding
        // sold book from the list
        int limit = this.purchased_book_list.size();
        int i;
        Book book = null;
        for(i=0; i<limit; i++){
            if((this.purchased_book_list.get(i).getBook_ID()).equals(book_ID)){
                book =  this.purchased_book_list.get(i);
                break;
            }
        }

        // 4. updating the revenues for the corresponding year
        int temp_yr = Integer.parseInt(book_ID.substring(0, 4));
        if(year - 2 <= temp_yr && temp_yr <= year){
            this.totalRevenue[year][year - temp_yr] += book.getBook_SP();
        }

        this.purchased_book_list.remove(i);

    } // add_update_SoldBook ends

    
    // printSales prints out the revenues of an year in the following format:
    // year1 <revenue from books bought in year1> <revenue from books bought in
    // previous year> <revenue from books bought 2 years back>
    // year2 <revenue from books bought in year2> <revenue from books bought in
    // previous year> <revenue from books bought 2 years back>
    // etc
    public void printSales(){
        int i, limit, index;
        limit = this.years.size();
        
        Collections.sort(this.years); // sorting the list of years in ascending order
        
        for(i = 0; i < limit; i++){
            index = this.years.get(i);
            System.out.println(index + " " + Math.round(totalRevenue[index][0]) + " "
            + Math.round(totalRevenue[index][1]) + " " + Math.round(totalRevenue[index][2]));
        }
    }
    
}
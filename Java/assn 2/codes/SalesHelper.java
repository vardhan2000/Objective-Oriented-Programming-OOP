/* Data members of a class should not be directly accessible by other classes. These
   should be manipulated only through appropriate methods provided by the class. */

public class SalesHelper {
    // is just a helper class of Sales class to store the 
    // info of sold books
    //                 --------------------------

    private String ID; // stores the unique id of a book
    private int sellingYear; // stores the year in which a book is sold
    
    SalesHelper(int yr, String book_ID){ // Constructor
        this.sellingYear = yr;
        this.ID = book_ID;
    }

    // Getter for sellingYear field
    public int getSellingYear() {
        return sellingYear;
    }

    // Getter for ID field
    public String getID() {
        return ID;
    }
}
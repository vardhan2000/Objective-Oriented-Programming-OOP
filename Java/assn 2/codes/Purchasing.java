import java.util.ArrayList;

/* Data members of a class should not be directly accessible by other classes. These
   should be manipulated only through appropriate methods provided by the class. */
class Purchasing{
    // Has a method to add a new book, passing in the year and the purchasing price. It
    // assigns a selling price to the book, which is 1.5 times the cost of the book. (this
    // should be set up so that the factor can be changed easily by the Store)
    //                   -----------------------------------------------


    private ArrayList<Book> purchased_book_list; // stores the list of info about purchased books 
    
    // seqNum stores sequence number for each book purchased in an year
    // is reset to one when the year changes
    private static int seqNum = 1; 
    
    private double factor = 1.5; // selling_price = factor * cost_price 

    /* Never use "public void" or anything like that before a constructor */
    /* we do pass by reference for the arraylist in Store class so that we can 
       easily update the list of purchased books initialised in Store class, through 
       Purchasing class */
    Purchasing(ArrayList<Book> purchased_book_list){ // Constructor
        this.purchased_book_list = purchased_book_list;
    }

    // Getter for factor field
    public double getFactor() {
        return this.factor;
    }

    // Setter for factor field
    public void setFactor(double newFactor){
        this.factor = newFactor;
    }

    // Getter for seqNum field
    public int getSeqNum() {
        return seqNum;
    }

    // Setter for seqNum field
    public void setSeqNum(int newSeqNum) {
        Purchasing.seqNum = newSeqNum;
    }

    // method to add the newly purchased books to the list of purchased books 
    public void addPurchasedBook(int purchasing_year, double CP){
        double temp_SP = this.factor * CP;
        this.purchased_book_list.add(new Book(purchasing_year, Purchasing.seqNum, temp_SP));  

        // notice how a static data member is accessed (Purchasing.seqNum NOT this.seqNum).  
        // Since, static data members are specific to a class, NOT to an object
        Purchasing.seqNum += 1; 
    }

    // method to return the "book" at index "index" in the list of purchased books
    public Book getBook(int index){
        return this.purchased_book_list.get(index);
    }

    // Returns the length of list of purchased books.
    // Was created just for testing purposes.    
    public int len(){
        return this.purchased_book_list.size();
    }
}
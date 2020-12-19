 import java.util.ArrayList;

 /* Data members of a class should not be directly accessible by other classes. These
   should be manipulated only through appropriate methods provided by the class. */
class Store{
    // has a Purchasing and Sales dept. Created when the Store is constructed
    // Maintains the list of all Books ever purchased
    //                      ----------------------------------------
    
    private ArrayList<Book> purchased_book_list = new ArrayList<>(); // // stores the list of info about purchased books 
    
    // declarations for purchasing and sales departments 
    private Purchasing purchase;
    private Sales sales;

    /* Never use "public void" or "public int" anything like that before a constructor */
    Store(){
        purchase = new Purchasing(purchased_book_list);
        sales = new Sales(purchased_book_list);
    }

    // Getter for purchase field
    public Purchasing getPurchase(){
        return purchase;
    }
    
    // Getter for sales field
    public Sales getSales() {
        return sales;
    }

    
}
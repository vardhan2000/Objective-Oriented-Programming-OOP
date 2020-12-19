/* Data members of a class should not be directly accessible by other classes. These
   should be manipulated only through appropriate methods provided by the class. */
    
class Book{
    // keeps track of the unique IDs for each book and also its corresponding selling price
    // the selling price is assigned by the Purchasing department
    //                             ---------------------------
    
    private String book_ID;
    private double book_SP; // stores selling price of book

    /* Never use "public void" or "public int" or anything like that before a constructor */

    // Constructor
    Book(int purchasing_year, int seq_num, double SP){
        this.book_SP = SP;

        // generating a unique id using "purchasing_year" and "seq_num"
        // and assigning that unique id to book_ID field      
        this.book_ID = this.generateBook_id(purchasing_year, seq_num);
    }

    // generates a unique id using "purchasing_year" and "seq_num"
    private String generateBook_id(int purchasing_year, int seq_num){
        String sequenceNum = Integer.toString(seq_num);
        String temp = "-00000";
        int len = sequenceNum.length();
            
        return Integer.toString(purchasing_year) + temp.substring(0, 7-len) + Integer.toString(seq_num);
    }
    
    // Getter for field book_ID
    public String getBook_ID(){
        return book_ID;
    }

    // Getter for field book_SP
    public double getBook_SP(){
        return book_SP;
    }    
     
}
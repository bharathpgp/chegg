public class Book {

    int bookID;
    String title, ISBN;
    int pageCount;
    String authorName, coAuthorName;
    static int numberOfBooksCheckedOut, numberOfBooksOnReserve;
    static String checked = "This Book is Checked Out";
    static String notChecked = "This Book is Available";
    boolean isCheckedOut, isOnReserve;

    Book() {
        isCheckedOut = false;
        isOnReserve = false;
        numberOfBooksCheckedOut = 0;
    }

    Book(String title, String ISBN, int pageCount, String authorName, String coAuthorName) {
        this.title = title;
        this.ISBN = ISBN;
        this.pageCount = pageCount;
        this.authorName = authorName;
        this.coAuthorName = coAuthorName;
        isCheckedOut = false;
        isOnReserve = false;
        numberOfBooksCheckedOut = 0;
    }

    Book(String title, String ISBN, int pageCount, String authorName) {
        this.title = title;
        this.ISBN = ISBN;
        this.pageCount = pageCount;
        this.authorName = authorName;
        this.coAuthorName = "";
        isCheckedOut = false;
        isOnReserve = false;
        numberOfBooksCheckedOut = 0;
    }

    void writeOutput() {

        System.out.println("Title: " + title);
        System.out.println("ISBN: " + ISBN);
        System.out.println("Pages: " + pageCount);
        System.out.println("Author: " + authorName);

        if (false == coAuthorName.isEmpty())
            System.out.println("Co Author: " + coAuthorName);

        if (true == isCheckedOut) {
            System.out.println(" --- book is checked out");
        } else {
            System.out.println(" --- book is available to check out");
        }
    }

    static void CheckBookOut(Book book) {
        book.isCheckedOut = true;
        numberOfBooksCheckedOut++;
    }

    static void CheckBookIn(Book book) {
        book.isCheckedOut = false;
        numberOfBooksCheckedOut--;
    }

    static void NumberOfBooksCheckedOut() {
        System.out.println("Total Number of books checked out : " + numberOfBooksCheckedOut);
    }

    static void OnReserve(Book book) {
        book.isOnReserve = true;
    }
}
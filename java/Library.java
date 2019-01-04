import java.util.*;

class Library {

    public static void main(String[] args) {

        Book[] books = new Book[] { new Book("C Programming", "1234128765123", 120, "Dennis Ritchi", "Kerning"),
                new Book("Fundamentals of Wavelets", "3411234128765", 228, "Goswami", "Jaideva"),
                new Book("God Created the Integers", "8931234128765", 197, "Stephen, Hawking"),
                new Book("Econometric Analysis", "6541234128765", 242, "Greene, W. H."),
                new Book("Angels & Demons", "9781593154899", 178, "Dan Brown"),
                new Book("Let Us C", "9788176566216", 213, "Yashwant Kanetkar") };

        Scanner input = new Scanner(System.in);
        int choice;
        String isbn;

        do {

            dispMenu();
            choice = input.nextInt();

            switch (choice) {

            case 0:
                break;

            case 1:
                showBooks(books);
                break;

            case 2:
                System.out.println("Enter ISBN of Book to be Checked Out.");
                isbn = input.next();
                checkOutBook(books, isbn);
                break;

            case 3:
                System.out.println("Enter ISBN of Book to be Checked In.");
                isbn = input.next();
                checkInBook(books, isbn);
                break;

            case 4:
                System.out.println("Enter ISBN of Book to Reserve.");
                isbn = input.next();
                reserveBook(books, isbn);
                break;

            default:
                System.out.println("Choice should be between 0 TO 3.");
            }

        } while (choice != 0);

        Book.NumberOfBooksCheckedOut();
    }

    static void dispMenu() {
        System.out.println(
                "----------------------------------------------------------------------------------------------------------");
        System.out.println("0 to Exit.");
        System.out.println("1 to Show All Books.");
        System.out.println("2 to Check Out Book. ");
        System.out.println("3 to Check In Book.");
        System.out.println("4 to Reserve Book.");
        System.out.println(
                "----------------------------------------------------------------------------------------------------------");
    }

    static void showBooks(Book[] books) {
        System.out.println("----------- Books List -----------");
        for (int i = 0; i < books.length; i++)
            books[i].writeOutput();
    }

    static void checkOutBook(Book[] books, String isbn) {
        for (int i = 0; i < books.length; i++) {
            if (books[i].ISBN.equalsIgnoreCase(isbn)) {
                if (false == books[i].isCheckedOut || false == books[i].isOnReserve) {
                    Book.CheckBookOut(books[i]);
                } else {
                    System.out.println("Can't check Out !!!");
                }
            }
        }
    }

    static void checkInBook(Book[] books, String isbn) {
        for (int i = 0; i < books.length; i++) {
            if (books[i].ISBN.equalsIgnoreCase(isbn)) {
                if (true == books[i].isCheckedOut) {
                    Book.CheckBookIn(books[i]);
                } else {
                    System.out.println("Can't check In !!!");
                }
            }
        }
    }

    static void reserveBook(Book[] books, String isbn) {
        for (int i = 0; i < books.length; i++) {
            if (books[i].ISBN.equalsIgnoreCase(isbn)) {
                if (false == books[i].isCheckedOut && false == books[i].isOnReserve) {
                    Book.OnReserve(books[i]);
                } else {
                    System.out.println("Can't reserve !!!");
                }
            }
        }
    }
}

import java.text.NumberFormat;

public class VideoGame {
    private String title, publisher, platform;
    private int year;
    private double price;
    private boolean status;

    public VideoGame(String title, String publisher, String platform, int year, double price, boolean status) {
        this.title = title;
        this.publisher = publisher;
        this.platform = platform;
        this.year = year;
        this.price = price;
        this.status = status;
    }

    public String toString() {
        NumberFormat fmt = NumberFormat.getCurrencyInstance();
        String description;
        description = fmt.format(price) + "\t" + year + "\t";
        description += title + "\t" + publisher;
        if (status)
            description += "\t" + "Finished!";
        return description;
    }
}
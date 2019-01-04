
import java.text.NumberFormat;

public class GameCollection {
    private VideoGame[] collection;
    private int count;
    private double totalCost;

    public GameCollection() {
        collection = new VideoGame[100];
        count = 0;
        totalCost = 0.0;
    }

    public void addGame(String title, String publisher, String platform, int year, double price, boolean status) {
        if (count == collection.length)
            increaseSize();
        collection[count] = new VideoGame(title, publisher, platform, year, price, status);
        totalCost += price;
        count++;
    }

    public String toString() {
        NumberFormat fmt = NumberFormat.getCurrencyInstance();
        String report = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        report += "My Video Game Collection\n\n";
        report += "Number of Games: " + count + "\n";
        report += "Total cost: " + fmt.format(totalCost) + "\n";
        report += "Average cost: " + fmt.format(totalCost / count);
        report += "\n\nVideo Game List:\n\n";
        for (int game = 0; game < count; game++)
            report += collection[game].toString() + "\n";
        return report;
    }

    private void increaseSize() {
        VideoGame[] temp = new VideoGame[collection.length * 2];
        for (int game = 0; game < collection.length; game++)
            temp[game] = collection[game];
        collection = temp;
    }
}
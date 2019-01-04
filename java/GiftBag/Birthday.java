
/**
 * Birthday.java
 */

import java.util.ArrayList;

public class Birthday {
    public static void main(String[] args) {
        ArrayList<GiftBag> gifts = new ArrayList<GiftBag>(); // using the raw type

        Phone iphone = new Phone("iPhone", "7", 150.99);
        GiftBag<Phone> gift1 = new GiftBag<>(iphone);
        gifts.add(gift1);

        MilkyWay midnight = new MilkyWay();
        midnight.setSize("MINI");
        midnight.setFlavor("MIDNIGHT");
        midnight.addIngredient("SEMISWEET CHOCOLATE");
        midnight.addIngredient("CORN SYRUP");
        midnight.addIngredient("SUGAR");
        midnight.addIngredient("HYDROGENATED PALM KERNEL OIL");
        midnight.addIngredient("SKIM MILK");
        midnight.setNumCalories(38);
        GiftBag<MilkyWay> gift2 = new GiftBag<>(midnight);
        gifts.add(gift2);

        GiftBag<String> gift3 = new GiftBag<>("Confetti!");
        gifts.add(gift3);

        System.out.println("Happy birthday!\n\nYour gifts:");
        for (GiftBag g : gifts) {
            System.out.println(g.getGift().toString() + "\n");
        }
    }
}
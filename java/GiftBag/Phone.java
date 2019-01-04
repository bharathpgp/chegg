
/**
 * Phone.java
 */

public class Phone {
    private String brand;
    private String model;
    private double price;

    /** Constructor(s) */

    public Phone() {
        this("Unknown brand", "Unknown model", 0.0);
    }

    public Phone(String theBrand, String theModel, double thePrice) {
        brand = theBrand;
        model = theModel;
        price = thePrice;
    }

    public void makeCall() {
        System.out.println("Making call from Phone.");
    }

    @Override
    public String toString() {
        return "Brand: " + brand + "\nModel: " + model + "\nPrice: " + price;
    }
}
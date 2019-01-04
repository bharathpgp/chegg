
/**
 * MilkyWay.java
 */
public class MilkyWay extends Candy {

    private String size;
    private String flavor;

    public MilkyWay() {
        super();
        size = "unknown size";
        flavor = "unknown flavor";
    }

    public String getSize() {
        return size;
    }

    public String getFlavor() {
        return flavor;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public void setFlavor(String flavor) {
        this.flavor = flavor;
    }

    public void printCandyGreeting() {
        System.out.println("Welcome to the Milky Way " + flavor + "!");
    }

    @Override
    public String toString() {
        return "Flavor: " + flavor + "\nSize: " + size + "\n" + super.toString();
    }
}
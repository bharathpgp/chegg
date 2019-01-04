
/**
 * GiftBag.java
 */
public class GiftBag<T> {

    private T gift;
    private boolean open;

    public GiftBag() {
        this.gift = null;
        this.open = false;
    }

    public GiftBag(T gift) {
        this.gift = gift;
    }

    public T getGift() {
        return this.gift;
    }

    public boolean isOpen() {
        return this.open;
    }

    public void openGift(boolean open) {
        this.open = open;
    }

    public String toString() {
        return gift.toString();
    }

}
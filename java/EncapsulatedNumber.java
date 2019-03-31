
class EncapsulatedNumber {

    private int number;
    private boolean stat;

    public EncapsulatedNumber() {
        this.number = 0;
        this.stat = false;
    }

    public void addSeven() {
        if (number < 100)
            this.number += 7;
        else
            this.stat = true;
    }

    public void subtractTwo() {
        if (number > 1)
            this.number -= 2;
        else
            this.stat = true;
    }

    public boolean getStatus() {
        return this.stat;
    }

    public static void main(String[] args) {

        EncapsulatedNumber number = new EncapsulatedNumber();

        while (true) {

            number.addSeven();
            number.subtractTwo();

            if (true == number.getStatus())
                break;
        }
    }
}
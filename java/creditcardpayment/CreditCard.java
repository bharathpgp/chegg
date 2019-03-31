
//package ccPaymentSchedule;

import java.text.NumberFormat;

public class CreditCard {

    private String firstName = "Joe";
    private String lastName = "Smith";
    private int accountNum = 5;
    private double curBal = 100;
    private double percentToPay = 10;

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getAccountNum() {
        return accountNum;
    }

    public void setAccountNum(int accountNum) {
        this.accountNum = accountNum;
    }

    public double getCurBal() {
        return curBal;
    }

    public void setCurBal(double curBal) {
        this.curBal = curBal;
    }

    public double getPercentToPay() {
        return percentToPay;
    }

    public void setPercentToPay(double percentToPay) {
        this.percentToPay = percentToPay;
    }

    public String printSchedule() {
        String masterString = "";
        //
        double curBal = getCurBal();
        int month = 1;
        double interest;
        double payment;
        double initial_monthly_payment = (getPercentToPay() * curBal) / 100;

        System.out.printf(" %5s %10s %10s %10s", "Month", "Interest", "Payment", "Balance");

        while (curBal > 0.00) {

            interest = (1.5 * curBal) / 100;

            if (curBal < initial_monthly_payment) {

                payment = curBal + interest;

                curBal = 0;

            } else {

                payment = ((curBal + interest) * getPercentToPay()) / 100;

                curBal = curBal + interest - payment;
            }

            System.out.printf(" %5s %10s %10s %10s", NumberFormat.getInstance().format(month),

                    NumberFormat.getCurrencyInstance().format(interest)

                    , NumberFormat.getCurrencyInstance().format(payment),

                    NumberFormat.getCurrencyInstance().format(curBal));

            month++;
        }
        return masterString;
    }
}
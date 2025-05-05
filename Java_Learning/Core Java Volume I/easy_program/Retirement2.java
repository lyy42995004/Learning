import java.util.*;

public class Retirement2 {
    public static void main(String[] args) {
        // read inputs
        Scanner in = new java.util.Scanner(System.in);

        System.out.print("How much money will you contribute every year? ");
        double payment = in.nextDouble();

        System.out.print("Interest rate in %: ");
        double interestRate = in.nextDouble();

        double balance = 0;
        int years = 0;

        String input;

        // update account balance while user isn't ready to retire
        do {
            // add this year's payment and interest
            balance += payment;
            double interest = balance * interestRate / 100;
            balance += interest;
            years++;

            // print current balance
            System.out.printf("After year %d, your balance is %,.2f%n", years, balance);

            // ask if ready to retire and get input
            System.out.print("Ready to retire? (Y/N) ");
            input = in.next();
        } while (input.equals("N"));

        System.out.println("You can retire in " + years + " years.");
    }
}

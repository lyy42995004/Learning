import java.util.Arrays;
import javax.swing.JOptionPane;

public class LambdaTest {
    public static void main(String[] args) {
        var planets = new String[] { "Mercury", "Venus", "Earth", "Mars", 
                                     "Jupiter", "Saturn", "Uranus", "Neptune" };
        System.out.println(Arrays.toString(planets));
        System.out.println("Sorted in dictionary order:");
        Arrays.sort(planets);
        System.out.println(Arrays.toString(planets));
        System.out.println("Sorted by length:");
        Arrays.sort(planets, (first, second) -> first.length() - second.length());
        System.out.println(Arrays.toString(planets));

        var timer = new javax.swing.Timer(1000, event -> {
            System.out.println("The time is " + new java.util.Date());
        });
        timer.start();

        JOptionPane.showMessageDialog(null, "Quit program?");
        System.exit(0);
    } 
}

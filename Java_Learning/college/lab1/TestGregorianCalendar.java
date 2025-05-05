import java.util.GregorianCalendar;

public class TestGregorianCalendar {
    public static void main(String[] args) {
        GregorianCalendar currentCalendar = new GregorianCalendar();

        // 显示当前的年、月和日
        int currentYear = currentCalendar.get(GregorianCalendar.YEAR);
        int currentMonth = currentCalendar.get(GregorianCalendar.MONTH) + 1;
        int currentDay = currentCalendar.get(GregorianCalendar.DAY_OF_MONTH);
        System.out.println("The current date: " + currentYear + " year " + currentMonth + " month " + currentDay + " day");

        GregorianCalendar particularCalendar = new GregorianCalendar();
        particularCalendar.setTimeInMillis(1234567898765L);

        int specificYear = particularCalendar.get(GregorianCalendar.YEAR);
        int specificMonth = particularCalendar.get(GregorianCalendar.MONTH) + 1;
        int specificDay = particularCalendar.get(GregorianCalendar.DAY_OF_MONTH);
        System.out.println("The current date: " + specificYear + " year " + specificMonth + " month " + specificDay + " day");
    }
}
import java.util.GregorianCalendar;

public class MyDate {
    private int Year;
    private int Month;
    private int Day;

    // 无参构造方法
    public MyDate() {
        this(GregorianCalendar.YEAR, GregorianCalendar.MONTH, GregorianCalendar.DAY_OF_MONTH);
    }

    public void setDate(long elapsedTime) {
        GregorianCalendar calendar = new GregorianCalendar();
        calendar.setTimeInMillis(elapsedTime);
        setDate(calendar);
    }

    private void setDate(GregorianCalendar calendar) {
        this.Year = calendar.get(GregorianCalendar.YEAR);
        this.Month = calendar.get(GregorianCalendar.MONTH);
        this.Day = calendar.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(long elapsedTime) {
        setDate(elapsedTime);
    }

    public MyDate(int year, int month, int day) {
        this.Year = year;
        this.Month = month;
        this.Day = day;
    }

    // 获取年份
    public int getYear() {
        return Year;
    }

    // 获取月份
    public int getMonth() {
        return Month;
    }

    // 获取日期
    public int getDay() {
        return Day;
    }

    public static void main(String[] args) {
        MyDate date1 = new MyDate();
        MyDate date2 = new MyDate(34355555133101L);

        System.out.println("The first date: " + date1.getYear() + " year " + (date1.getMonth() + 1) + " month " + date1.getDay() + " day");
        System.out.println("The second date: " + date2.getYear() + " year " + (date2.getMonth() + 1) + " month " + date2.getDay() + " day");
    }
}
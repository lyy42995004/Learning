class Rectangle{
    private double width;
    private double height;

    public Rectangle() {
        this.width = 1;
        this.height = 1;
    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return 2 * (width + height);
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }

    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle(4, 40);
        Rectangle rect2 = new Rectangle(3.5, 35.9);
        
        System.out.println("Width: " + rect1.getWidth() +
                ", Height: " + rect1.getHeight() +
                ", Area: " + rect1.getArea() +
                ", Perimeter: " + rect1.getPerimeter());

        System.out.println("Width: " + rect2.getWidth() +
                ", Height: " + rect2.getHeight() +
                ", Area: " + rect2.getArea() +
                ", Perimeter: " + rect2.getPerimeter());
    }
}
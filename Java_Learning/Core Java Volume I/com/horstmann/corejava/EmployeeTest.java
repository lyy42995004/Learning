package com.horstmann.corejava;
// the Employee class is defined in that package

import static java.lang.System.*;

public class EmployeeTest {
    public static void main(String[] args) {
        // because of the static import statement, we don't have to use
        // com.horstmann.corejava.Employee here
        var harry = new Employee("Harry Hacker", 50000, 1989, 10, 1);

        harry.raiseSalary(5);

        // because of the static import statement, we don't have to use System.out here
        out.println("name=" + harry.getName() + ",salary=" + harry.getSalary());
    }
}

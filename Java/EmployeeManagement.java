package Other;

import java.util.*;

class Employee {
    private String firstName;
    private double salary;

    public Employee(String firstName, double salary) {
        this.firstName = firstName;
        this.salary = salary;
    }

    public void display() {
        System.out.println("DISPLAYING DETAILS:-");
        System.out.println("firstName : " + this.firstName);
        System.out.println("Salary : " + this.salary);
        try {
            if (this.salary < 2000) {
                throw new EmployeeException();
            }
        } catch (EmployeeException e) {
            System.out.println(e.getMessage());
        }
    }
}

class EmployeeException extends Exception {
    public String getMessage() {
        return "Salary is below 2000";
    }
}

// Main class
public class EmployeeManagement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("first name: ");
        String firstName = scanner.nextLine();
        System.out.print("salary: ");
        double salary = scanner.nextDouble();

        Employee emp = new Employee(firstName, salary);
        emp.display();
        scanner.close();
    }
}
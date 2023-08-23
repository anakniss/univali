public class EmployeeTest {
    public static void main(String[] args) {
        Employee employee1 = new Employee("Joana", "Souza", 1200);
        Employee employee2 = new Employee("João", "Goncalves", 1200);
        System.out.printf(employee1.toString());

        employee1.increaseSalary(10);
        System.out.printf(employee1.toString());

        employee1.setSalary(1500);
        System.out.printf(employee1.toString());

        System.out.printf(employee2.toString());
        employee2.increaseSalary(60);
        System.out.printf(employee2.toString());
    }
}
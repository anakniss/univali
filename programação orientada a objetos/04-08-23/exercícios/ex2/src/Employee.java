public class Employee {
    private String firstName;
    private String lastName;
    private double salary;

    public Employee(String firstName, String lastName, double salary){
        this.firstName = firstName;
        this.lastName = lastName;
        if(salary > 0.0)
            this.salary = salary;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getFirstName(){
        return this.firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public void setSalary(double salary) {
        if(salary > 0.0)
            this.salary = salary;
    }

    public double getSalary() {
        return this.salary;
    }

    public void increaseSalary(int percent){
        salary = salary * (1 + percent/100.0);
    }

    public String toString(){
        return "Employee\n" +
                "Name: " + firstName + " " + lastName + "\n" +
                "Salary: " + salary + "\n";
    }
}

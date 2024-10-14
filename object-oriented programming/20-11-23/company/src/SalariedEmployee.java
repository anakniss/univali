public class SalariedEmployee extends Employee {
    private double weeklySalary;

    public SalariedEmployee(String first, String last, String ssn, double salary){
        super(first, last, ssn);
    }

    public double getWeeklySalary() {
        return weeklySalary;
    }

    public void setWeeklySalary(double salary) {
        this.weeklySalary = Math.max(salary, 0.0);
    }

    public double getPaymentAmount() {
        return getWeeklySalary();
    }

    public String toString(){
        return String.format("Salaried employee: %s\n" +
                "Weekly salary: %s",
                super.toString(),
                getWeeklySalary());
    }
}

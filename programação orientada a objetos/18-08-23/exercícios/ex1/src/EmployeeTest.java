public class EmployeeTest {
    public static void main(String[] args) {
        CommissionEmployee e = new CommissionEmployee("Ana", "Kniss", "224", 1000, 0.10);
        HourlyEmployees e2 = new HourlyEmployees("Lucas", "Souza", "454", 5, 10);

        System.out.print(e2.toString());
    }
}
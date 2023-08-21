import java.util.Scanner;

public class InvoiceTest {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        Invoice invoice1 = new Invoice("123532", "first", 2, 1000);

        System.out.printf("number: %s%n", invoice1.getNumber());
        System.out.printf("description: %s%n", invoice1.getDescription());
        System.out.printf("quantity: %s%n", invoice1.getQuantity());
        System.out.printf("price: %s%n", invoice1.getPrice());
        System.out.printf("total: %s%n", invoice1.getInvoiceAmount(invoice1.getQuantity(), invoice1.getPrice()));

        System.out.println("Altered information");

        System.out.println("Enter a new number value: ");
        String newValue = input.nextLine();
        invoice1.setNumber(newValue);

        System.out.println("Enter a new description value: ");
        newValue = input.nextLine();
        invoice1.setDescription(newValue);

        System.out.println("Enter a new quantity value: ");
        int newQuantity = input.nextInt();
        invoice1.setQuantity(newQuantity);

        System.out.println("Enter a new quantity value: ");
        double newPrice = input.nextDouble();
        invoice1.setPrice(newPrice);

        System.out.printf("number: %s%n", invoice1.getNumber());
        System.out.printf("description: %s%n", invoice1.getDescription());
        System.out.printf("quantity: %s%n", invoice1.getQuantity());
        System.out.printf("price: %s%n", invoice1.getPrice());
        System.out.printf("total: %s%n", invoice1.getInvoiceAmount(invoice1.getQuantity(), invoice1.getPrice()));
    }
}
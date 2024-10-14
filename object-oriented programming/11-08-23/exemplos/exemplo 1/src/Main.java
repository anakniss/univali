import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        //Cria um scanner para obter a entrada a partir da janela de comando
        Scanner input = new Scanner(System.in);

        int number1;
        int number2;
        int sum;

        System.out.print("Enter first integer: ");
        number1 = input.nextInt(); //Lê primeiro número fornecido pelo usuário

        System.out.print("Enter second integer: ");
        number2 = input.nextInt();

        sum = number1 + number2;

        System.out.printf("Sum is %d%n", sum);
    }
}
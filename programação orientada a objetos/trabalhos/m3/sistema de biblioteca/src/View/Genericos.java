package View;

import Controller.Biblioteca;
import Model.Livro;

import java.util.Scanner;

public class Genericos {

    public int solicitarNumero() {
        Scanner scanner = new Scanner(System.in);
        int numero;

        while (!scanner.hasNextInt()) {
            scanner.next();
            System.out.println("Valor inválido. Digite um número inteiro:");
        }
        numero = scanner.nextInt();
        return numero;
    }

    public static Livro buscarLivroPorISBN(Biblioteca biblioteca, String isbn) {
        for (Livro livro : biblioteca.getCatalogoLivros()) {
            if (livro.getIsbn().equals(isbn)) {
                return livro;
            }
        }
        return null;
    }
}

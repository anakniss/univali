package View;

import Controller.BibliotecaSingleton;
import Model.Livro;

import java.util.Scanner;

import static View.Genericos.buscarLivroPorISBN;

public class RegistrarDevolução {
    public void registrarDevolucao(Scanner scanner){
        System.out.print("Digite o ISBN do livro para devolver: ");
        String isbnDevolucao = scanner.nextLine();

        Livro livroDevolucao = buscarLivroPorISBN(BibliotecaSingleton.getInstance(), isbnDevolucao);
        if (livroDevolucao != null) {
            BibliotecaSingleton.getInstance().registrarDevolucao(livroDevolucao);
        } else {
            System.out.println("Livro não encontrado nos empréstimos.");
        }
    }
}

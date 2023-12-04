package View;

import Controller.BibliotecaSingleton;
import Model.Livro;
import Model.Usuario;

import java.util.Scanner;

import static View.Genericos.buscarLivroPorISBN;

public class EmprestarLivroView {
    public void emprestarLivro(Scanner scanner, Genericos numeroScanner){
        System.out.print("Digite o ISBN do livro para emprestar: ");
        String isbnEmprestimo = scanner.nextLine();
        System.out.print("Digite o nome do usuário: ");
        String nomeUsuario = scanner.nextLine();
        System.out.print("Digite o CPF do usuário: ");
        int cpfUsuario = numeroScanner.solicitarNumero();
        System.out.print("Digite o e-mail do usuário: ");
        String emailUsuario = scanner.nextLine();

        Livro livroEmprestimo = buscarLivroPorISBN(BibliotecaSingleton.getInstance(), isbnEmprestimo);
        if (livroEmprestimo != null) {
            Usuario usuario = new Usuario(nomeUsuario, cpfUsuario, emailUsuario);
            BibliotecaSingleton.getInstance().emprestarLivro(livroEmprestimo, usuario);
        } else {
            System.out.println("Livro não encontrado no catálogo.");
        }
    }
}

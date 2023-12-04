package View;

import Controller.BibliotecaSingleton;
import Model.Livro;

import java.util.Scanner;

public class CadastrarLivrosView {
    public void cadastrarLivro(Scanner scanner){
        System.out.print("Digite o ISBN do livro: ");
        String isbn = scanner.nextLine();
        System.out.print("Digite o título do livro: ");
        String titulo = scanner.nextLine();
        System.out.print("Digite o autor do livro: ");
        String autor = scanner.nextLine();

        Livro novoLivro = new Livro(isbn, titulo, autor);
        BibliotecaSingleton.getInstance().adicionarLivro(novoLivro);
        System.out.println("Livro adicionado com sucesso!");
    }
}

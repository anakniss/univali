package View;

import Controller.BibliotecaSingleton;
import Model.Emprestimo;

public class MostrarEmprestimosView {
    public void mostrarEmprestimos(){
        System.out.println("Empréstimos realizados:");
        for (Emprestimo emprestimo : BibliotecaSingleton.getInstance().getEmprestimos()) {
            System.out.println("Livro: " + emprestimo.getLivro().getTitulo() +
                    " | Usuário: " + emprestimo.getUsuario().getNome() +
                    " | Data de Empréstimo: " + emprestimo.getDataEmprestimo() +
                    " | Data de Devolução: " + emprestimo.getDataDevolucao());
        }
    }
}

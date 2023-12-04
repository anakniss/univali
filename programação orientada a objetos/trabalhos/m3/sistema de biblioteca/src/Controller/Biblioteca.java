package Controller;

import Model.Emprestimo;
import Model.Livro;
import Model.Usuario;

import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
    private List<Livro> catalogoLivros;
    private List<Emprestimo> emprestimos;

    public Biblioteca() {
        this.catalogoLivros = new ArrayList<>();
        this.emprestimos = new ArrayList<>();
    }

    public void adicionarLivro(Livro livro) {
        catalogoLivros.add(livro);
    }

    public void emprestarLivro(Livro livro, Usuario usuario) {
        if (verificarDisponibilidade(livro)) {
            Emprestimo emprestimo = new Emprestimo(livro, usuario);
            emprestimos.add(emprestimo);
            System.out.println("Livro emprestado com sucesso para " + usuario.getNome());
        } else {
            System.out.println("Livro indisponível para empréstimo no momento.");
        }
    }

    private boolean verificarDisponibilidade(Livro livro) {
        for (Emprestimo emprestimo : emprestimos) {
            if (emprestimo.getLivro().equals(livro) && emprestimo.getDataDevolucao() == null) {
                return false;
            }
        }
        return true;
    }

    public void registrarDevolucao(Livro livro) {
        for (Emprestimo emprestimo : emprestimos) {
            if (emprestimo.getLivro().equals(livro) && emprestimo.getDataDevolucao() == null) {
                emprestimo.registrarDevolucao();
                System.out.println("Livro devolvido com sucesso");
                return;
            }
        }
        System.out.println("Livro não encontrado para devolução");
    }
    public List<Livro> getCatalogoLivros() {
        return catalogoLivros;
    }

    public List<Emprestimo> getEmprestimos() {
        return emprestimos;
    }
}

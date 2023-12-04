package View;

import Controller.BibliotecaSingleton;
import Model.Livro;

public class MostrarCatalogoLivrosView {
    public void mostrarCatalogo(){
        System.out.println("Catálogo de livros:");
        for (Livro livro : BibliotecaSingleton.getInstance().getCatalogoLivros()) {
            System.out.println(livro);
        }
    }
}

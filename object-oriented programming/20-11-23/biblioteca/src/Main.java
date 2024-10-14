import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Livro livro1 = new Livro("A trança da mulher careca", "Ilda");
        Livro livro2 = new Livro("A volta dos que não foram", "Joao");
        Livro livro3 = new Livro("A volta dos que não foram 2", "Maria");

        List<Livro> acervo = new ArrayList<>();

        acervo.add(livro1);
        acervo.add(livro2);
        acervo.add(livro3);

        Biblioteca bi = new Biblioteca(acervo);

        System.out.println(bi.toString());
    }
}
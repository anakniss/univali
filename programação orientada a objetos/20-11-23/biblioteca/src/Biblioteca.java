import java.util.List;

public class Biblioteca {
    private List<Livro> acervo;

    public Biblioteca(List<Livro> acervo){
        this.acervo = acervo;
    }

    public void addLivro(Livro livro){
        acervo.add(livro);
    }

    public List<Livro> getAcervo() {
        return acervo;
    }

    @Override
    public String toString(){
        int i = 1;
        String mensagem = "";
        for(Livro livro : acervo){
            mensagem += i + ". " + livro.getTitulo() + "\n";
            mensagem += "Autor: " + livro.getAutor() + "\n";
            i++;
        }
        return String.format("ACERVO\n%s", mensagem);
    }
}

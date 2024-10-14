import java.util.ArrayList;
import java.util.List;

public class Professor extends Pessoa {
    private String matricula, titulacao;
    private int quantidadeAlunos;
    private List<Orientacao> orientacoes;

    public Professor(String nome, String matricula, String titulacao){
        super(nome);
        this.matricula = matricula;
        this.titulacao = titulacao;
        quantidadeAlunos = 0;
        orientacoes = new ArrayList<>();
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula){
        this.matricula = matricula;
    }

    public String getTitulacao() {
        return titulacao;
    }

    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }

    public void addOrientacao(Orientacao o){
        this.orientacoes.add(o);
        quantidadeAlunos++;
    }

    public void removeOrientacao(Orientacao o){
        for(Orientacao orientacao : orientacoes){
            if(orientacao.equals(o)){
                orientacoes.remove(o);
                o.getOrientando().removeOrientacao();
                quantidadeAlunos--;
                break;
            }
        }
    }

    @Override
    public String toString(){
        int i = 1;
        String msg = "";

        for(Orientacao o : orientacoes){
            msg += "1. " + o + "\n";
        }

        return String.format("PROFESSOR\n" +
                "Nome: %s\n" +
                "Matrícula: %s\n" +
                "Titulação: %s\n" +
                "Quantidade de Orientações: %s\n" +
                "Orientações: %s\n",
                getNome(),
                getMatricula(),
                getTitulacao(),
                quantidadeAlunos,
                msg);
    }
}

public class Aluno extends Pessoa {
    private final String matricula, curso;

    private Orientacao orientacao;

    public Aluno(String nome, String matricula, String curso){
        super(nome);
        this.matricula = matricula;
        this.curso = curso;
        orientacao = null;
    }

    public String getMatricula(){
        return this.matricula;
    }

    public String getCurso() {
        return curso;
    }

    public void setOrientacao(Orientacao orientacao){
        if(this.orientacao == null){
            this.orientacao = orientacao;
        }
    }

    public void removeOrientacao(){
        this.orientacao = null;
    }
}

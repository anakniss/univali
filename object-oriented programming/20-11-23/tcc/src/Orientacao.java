public class Orientacao {
    private Aluno orientando;
    private Professor orientador;
    private String titulo;

    public Orientacao(String titulo, Aluno a, Professor p){
        this.titulo = titulo;
        setOrientando(a);
        setOrientador(p);
        a.setOrientacao(this);
        p.addOrientacao(this);
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public Aluno getOrientando() {
        return orientando;
    }

    public void setOrientando(Aluno orientando) {
        this.orientando = orientando;
    }


    public Professor getOrientador() {
        return orientador;
    }

    public void setOrientador(Professor orientador) {
        this.orientador = orientador;
    }

    @Override
    public String toString(){
        return String.format("ORIENTACAO\n" +
                "Orientando: %s\n" +
                "Orientador: %s\n" +
                "Título do TCC: %s\n",
                orientando.getNome(),
                orientador.getNome(),
                getTitulo());
    }
}

package br.univali.poo.cinema;

public class Cliente {
    private String nome;
    private Ingresso ingresso;
    public Cliente(String nome){
        this.nome = nome;
    }

    public String getNome() { return nome; }

    public Ingresso getIngresso() {
        return ingresso;
    }

    public void setIngresso(Ingresso ingresso) {
        this.ingresso = ingresso;
    }

    @Override
    public String toString()
    {
        return String.format("CLIENTE\n" +
                "Nome: %s\n" +
                "Ingresso: %s\n",
                getNome(),
                getIngresso().toString());
    }
}

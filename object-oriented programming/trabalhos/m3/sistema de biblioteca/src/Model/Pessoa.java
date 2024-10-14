package Model;

public class Pessoa {
    final private String nome;
    final private int cpf;

    public Pessoa(String nome, int cpf){
        this.nome = nome;
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public int getCpf() {
        return cpf;
    }
}

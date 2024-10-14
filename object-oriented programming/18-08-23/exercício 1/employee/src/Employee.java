import java.lang.Exception;

public class Employee {
    final String firstName;
    final String lastName;
    final String socialSecurityNumber;


    public Employee(String nome, String cpf){
        this.nome = nome;

        if(cpf.length() != 11){
            throw new NumberFormatException("Número de CPF inválido");
        }
        this.cpf = cpf;
    }

    public String getNome(){
        return nome;
    }
    public String getCpf(){
        return cpf;
    }
}

package Model;

public class Usuario extends Pessoa {
    private String email;

    public Usuario(String nome, int cpf, String email) {
        super(nome, cpf);
        this.email = email;
    }

    public String getEmail() {
        return email;
    }

    public void setNome(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Usuario{" +
                "E-mail='" + email + '\'' +
                '}';
    }
}

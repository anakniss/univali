public class Main {
    public static void main(String[] args) {
        Pessoa membro1 = new Pessoa("Ana");
        Pessoa membro2 = new Pessoa("Fernando");

        Familia familia = new Familia();

        familia.adicionaMembro(membro1);
        familia.adicionaMembro(membro2);

        System.out.println(familia.toString());
    }
}
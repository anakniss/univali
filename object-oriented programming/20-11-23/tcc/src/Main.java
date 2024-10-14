public class Main {
    public static void main(String[] args) {
        Professor p = new Professor("Carlos", "123", "Especialista");
        Aluno a = new Aluno("Ana", "321", "Ciência da Computação");
        Aluno b = new Aluno("Fernando", "432", "Filosofia");

        /*System.out.println(p.toString());
        System.out.println(a.toString());
        System.out.println(b.toString());*/

        Orientacao tccA = new Orientacao("Jogo da Vida", a, p);
        Orientacao tccB = new Orientacao("Jogo da Morte", b, p);

        System.out.println(p.toString());

        p.removeOrientacao(tccB);

        System.out.println(p.toString());
    }
}
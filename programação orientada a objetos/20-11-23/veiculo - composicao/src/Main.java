public class Main {
    public static void main(String[] args) {
        Veiculo veiculo = new Veiculo(
                "marca 1",
                "modelo 1",
                2012,
                500,
                "marca pneu 1",
                "modelo pneu 1");

        System.out.println(veiculo.toString());

    }
}
public class HeartRatesTest {
    public static void main(String[] args) {
        var heart = new HeartRates("Luana", "Souza", 24, 04, 1989);

        System.out.println(heart.toString());
        System.out.printf("Frequência cardíaca máxima: %s \n", heart.calculateMaxHeartRate());
        heart.calculateTargetHeartRate();
    }
}
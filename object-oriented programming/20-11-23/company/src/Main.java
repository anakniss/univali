public class Main {
    public static void main(String[] args) {
        Payable payableObjects[] = new Payable[4];

        payableObjects[0] = new Invoice("1234", "oi", 3, 345.67);
        payableObjects[1] = new Invoice("4321", "tudo bom?", 1, 542.2);
        payableObjects[2] = new SalariedEmployee("John", "Smith", "333-21-3432", 800.0);
        payableObjects[3] = new SalariedEmployee("Joana", "Souza", "433-21-3461", 1300.0);

        for(Payable currentPayable : payableObjects){
            System.out.println(currentPayable.toString());
        }
    }
}
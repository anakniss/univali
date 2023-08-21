public class HeartRates {
    private String firstName;
    private String lastName;
    private int day;
    private int month;
    private int year;

    public HeartRates(String firstName, String lastName, int day, int month, int year){
        this.firstName = firstName;
        this.lastName = lastName;

        if(month <= 0 || month > 31)
            throw new IllegalArgumentException("Mês inválido");

        switch(month){
            case 1, 3, 5, 7, 8, 10, 12:
                if(day < 1 || day > 31)
                    throw new IllegalArgumentException("Dia inválido");
                break;

            case 2:
                if(day < 1 || day > 29)
                    throw new IllegalArgumentException("Dia inválido");

                if(day == 29 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
                    throw new IllegalArgumentException("Dia inválido");
                break;
        }

        this.day = day;
        this.month = month;
        this.year = year;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getFirstName(){
        return this.firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getDay() {
        return day;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getMonth() {
        return month;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getYear() {
        return year;
    }

    public int calculateYear(){
        return 2023 - getYear();
    }

    public double calculateMaxHeartRate(){
        return 220 - calculateYear();
    }

    public void calculateTargetHeartRate(){
        double per50 = calculateMaxHeartRate() * 0.50;
        double per85 = calculateMaxHeartRate() * 0.85;

        System.out.printf("A frequência cardíaca alvo está entre %s e %s", per50, per85);
    }

    public String toString(){
        return "\nNome: " + firstName + " " + lastName + "\n" +
                "Data de Nascimento: " + day + "/" + month + "/" + year;
    }
}

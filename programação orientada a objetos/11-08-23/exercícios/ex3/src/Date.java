import java.lang.Exception;
public class Date {
    private int day;
    private int month;
    private int year;

    public Date(int day, int month, int year){
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

    public String toString(){
        return String.format("%02d/%02d/%d", day, month, year);
    }
}

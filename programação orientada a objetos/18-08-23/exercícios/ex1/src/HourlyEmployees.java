public class HourlyEmployees extends Employee {
    private double hours;
    private double wage;

    public HourlyEmployees(String firstName,
                           String lastName,
                           String socialSecurityNumber,
                           double hours,
                           double wage){
        super(firstName, lastName, socialSecurityNumber);

        if(hours < 0 || hours > 168){
            throw new IllegalArgumentException("Hours must be >= 0 and <= 168");
        }

        if(wage < 0.0){
            throw new IllegalArgumentException("Wage must be >= 0.0");
        }

        this.hours = hours;
        this.wage = wage;
    }

    public double getHours(){
        return hours;
    }

    public void setHours(double hours) {
        if (hours < 0 || hours > 168) {
            this.hours = hours;
        }
    }

    public double getWage(){
        return wage;
    }

    public void setWage(double wage){
        if(wage >= 0 && wage <= 168){
            this.wage = wage;
        }
    }

    public double earnings(){
        return getHours() * getWage();
    }

    @Override
    public String toString(){
        return String.format("%s\nHours: %s\nWage: %s\nEarnings: %s", super.toString(), getHours(), getWage(), earnings());
    }
}

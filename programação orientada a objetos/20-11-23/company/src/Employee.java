public abstract class Employee implements Payable {
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;

    public Employee(String first, String last, String ssn){
        firstName = first;
        lastName = last;
        socialSecurityNumber = ssn;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String first){
        firstName = first;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getSocialSecurityNumber() {
        return socialSecurityNumber;
    }

    public void setSocialSecurityNumber(String socialSecurityNumber) {
        this.socialSecurityNumber = socialSecurityNumber;
    }

    public String toString(){
        return String.format("Primeiro nome: %s\n" +
                "Sobrenome: %s\n" +
                "SSN: %s",
                getFirstName(),
                getLastName(),
                getPaymentAmount());
    }
}

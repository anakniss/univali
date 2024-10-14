public class Invoice implements Payable {
    private String partNumber;
    private String partDescription;
    private int quantity;
    private double pricePerItem;

    public Invoice(String part, String description, int count, double price){
        partNumber = part;
        partDescription = description;
    }

    public String getPartNumber() {
        return partNumber;
    }

    public void setPartNumber(String partNumber) {
        this.partNumber = partNumber;
    }

    public String getPartDescription() {
        return partDescription;
    }

    public void setPartDescription(String partDescription) {
        this.partDescription = partDescription;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        if(quantity < 0){ quantity = 0; }
        else { this.quantity = quantity; }
    }

    public double getPricePerItem() {
        return pricePerItem;
    }

    public void setPricePerItem(double pricePerItem) {
        this.pricePerItem = pricePerItem;
    }

    @Override
    public double getPaymentAmount() {
        return getQuantity() * getPricePerItem();
    }

    public String toString(){
        return String.format("Part number: %s\n" +
                "Part description: %s\n" +
                "Quantity: %s\n" +
                "Price per item: %s\n",
                getPartNumber(),
                getPartDescription(),
                getQuantity(),
                getPricePerItem());
    }
}

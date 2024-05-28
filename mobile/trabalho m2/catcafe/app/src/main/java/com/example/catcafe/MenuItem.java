package com.example.catcafe;

public class MenuItem {
    private String name;
    private double price;
    private String imageResourceName;
    private int imageDrawable;

    public MenuItem(String name, double price, String imageResourceName, int imageDrawable) {
        this.name = name;
        this.price = price;
        this.imageResourceName = imageResourceName;
        this.imageDrawable = imageDrawable;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public String getImageResourceName() {
        return imageResourceName;
    }

    public int getImageDrawable() {
        return imageDrawable;
    }
}

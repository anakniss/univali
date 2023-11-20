public class SmartHouseLight {
    private String name;
    private boolean isOn;
    private int intensity;
    public SmartHouseLight(String name){
        this.name = name;
        this.isOn = false;
        this.intensity = 50;
    }

    public String getName() {
        return name;
    }

    public String getPowerStatus(){
        return this.isOn ? "ON" : "OFF";
    }

    public boolean on(){
        this.isOn = true;
        System.out.println(getName() + " agora está " + getPowerStatus());
        return this.isOn;
    }

    public boolean off(){
        this.isOn = false;
        System.out.println(getName() + " agora está " + getPowerStatus());
        return this.isOn;
    }

    public int increaseIntensity(){
        if(this.intensity >= 100){
            return this.intensity;
        }
        return this.intensity += 1;
    }

    public int decreaseIntensity(){
        if(this.intensity <= 0){
            return this.intensity;
        }
        return this.intensity -= 1;
    }

    public int getIntensity() {
        return intensity;
    }
}

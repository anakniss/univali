public class LightIntensityCommand implements ISmartHouseCommand{
    private SmartHouseLight light;
    public LightIntensityCommand(SmartHouseLight light){
        this.light = light;
    }

    @Override
    public void execute() {
        this.light.increaseIntensity();
        System.out.println("Intensidade de " + light.getName() + ": " + light.getIntensity());
    }

    @Override
    public void undo() {
        this.light.decreaseIntensity();
        System.out.println("Intensidade de " + light.getName() + ": " + light.getIntensity());
    }
}
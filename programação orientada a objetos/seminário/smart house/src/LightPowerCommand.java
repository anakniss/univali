public class LightPowerCommand implements ISmartHouseCommand{
    private SmartHouseLight light;
    public LightPowerCommand(SmartHouseLight light){
        this.light = light;
    }

    @Override
    public void execute() {
        light.on();
    }

    @Override
    public void undo() {
        light.off();
    }
}

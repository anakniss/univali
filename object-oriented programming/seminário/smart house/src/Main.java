public class Main {
    public static void main(String[] args) {

        // Receiver
        var bedroomLight = new SmartHouseLight("Luz do quarto");
        var bathroomLight = new SmartHouseLight("Luz do banheiro");

        // Command
        var bedroomlightPowerCommand = new LightPowerCommand(bedroomLight);
        var bathroomlightPowerCommand = new LightPowerCommand(bathroomLight);
        var bedroomIntensityCommand = new LightIntensityCommand(bedroomLight);

        // Sem Invoker
        /*lightPowerCommand.execute();
        lightPowerCommand.undo();*/

        // Controle - Invoker
        var smartHouseApp = new SmartHouseApp();
        smartHouseApp.addCommand("btn-1", bedroomlightPowerCommand);
        smartHouseApp.executeCommand("btn-1");
        smartHouseApp.undoCommand("btn-1");

        smartHouseApp.addCommand("btn-2", bathroomlightPowerCommand);
        smartHouseApp.executeCommand("btn-2");
        smartHouseApp.undoCommand("btn-2");

        smartHouseApp.addCommand("btn-3", bedroomIntensityCommand);
        smartHouseApp.executeCommand("btn-3");
        smartHouseApp.undoCommand("btn-3");
    }
}
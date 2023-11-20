import java.util.Dictionary;
import java.util.HashMap;

public class SmartHouseApp {
    // HashMap == Dictionary
    private HashMap<String, ISmartHouseCommand> commands;

    public SmartHouseApp() {
        commands = new HashMap<>();
    }

    public void addCommand(String key, ISmartHouseCommand command) {
        this.commands.put(key, command);
    }

    public void executeCommand(String key){
        this.commands.get(key).execute();
    }

    public void undoCommand(String key){
        this.commands.get(key).undo();
    }
}

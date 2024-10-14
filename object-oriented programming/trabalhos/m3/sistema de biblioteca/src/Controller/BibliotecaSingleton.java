package Controller;

public class BibliotecaSingleton {
    private static Biblioteca biblioteca;
    public static Biblioteca getInstance(){
        if(biblioteca == null){
            biblioteca = new Biblioteca();
        }
        return biblioteca;
    }
}

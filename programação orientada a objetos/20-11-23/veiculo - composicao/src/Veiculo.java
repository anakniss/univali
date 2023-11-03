import java.util.ArrayList;
import java.util.List;

public class Veiculo {
    private String marca;
    private String modelo;
    private int ano, quilometros;
    private ArrayList<Pneu> rodas;

    public Veiculo(String marca, String modelo, int ano, int quilometros, String marcaPneu, String modeloPneu){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.quilometros = quilometros;
        this.rodas = new ArrayList<>(List.of(new Pneu(marcaPneu, modeloPneu), new Pneu(marcaPneu, modeloPneu), new Pneu(marcaPneu, modeloPneu), new Pneu(marcaPneu, modeloPneu)));
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getAno() {
        return ano;
    }

    public int getQuilometros() {
        return quilometros;
    }

    public void setQuilometros(int quilometros) {
        this.quilometros = quilometros;
    }

    @Override
    public String toString(){
        String msg = "";
        int i = 1;
        for(Pneu roda : rodas){
            msg += i + ". " + roda.getMarca() + " ";
            msg += roda.getModelo() + "\n";
            i++;
        }

        return String.format("Marca: %s\nModelo: %s\nAno: %s\nKM: %s\nRodas: %s",
                getMarca(),
                getModelo(),
                getAno(),
                getQuilometros(),
                msg);
    }
}

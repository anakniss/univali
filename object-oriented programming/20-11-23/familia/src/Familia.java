import java.util.ArrayList;

public class Familia {
    private ArrayList<Pessoa> membros;

    public Familia(){
        this.membros = new ArrayList<>();
    }

    public void adicionaMembro(Pessoa a){
        membros.add(a);
    }

    public int tamanho(){
        return membros.size();
    }

    @Override
    public String toString(){
        if(tamanho() == 0) { return ("Família inexistente"); }

        String nomes = "";
        int i = 1;
        for(Pessoa membro : membros){
            nomes += i + ". " + membro.getNome() + "\n";
            i++;
        }

        return String.format("Nomes: %s \nTamanho: %s", nomes, tamanho());
    }
}

package br.univali.poo.cinema;

public class Sala {
    private int nAssentos;
    private String tipoTela;
    private String localizacao;

    public Sala(int nAssentos, String tipoTela, String localizacao) {
        if(nAssentos <= 0)
            throw new IllegalArgumentException("O número de assentos não pode ser negativo");
        this.nAssentos = nAssentos;
        this.tipoTela = tipoTela;
        this.localizacao = localizacao;
    }

    public int getnAssentos() {
        return nAssentos;
    }
    public void setnAssentos(int nAssentos) {
        if(nAssentos <= 0)
            throw new IllegalArgumentException("O número de assentos não pode ser negativo");
        this.nAssentos = nAssentos;
    }
    public String getTipoTela() { return tipoTela; }
    public String getLocalizacao() { return localizacao; }

    @Override
    public String toString() {
        return String.format("Assentos: %s\n" +
                "Tipo de tela: %s\n" +
                "Localização: %s\n",
                getnAssentos(),
                getTipoTela(),
                getLocalizacao());
    }
}

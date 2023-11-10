package br.univali.poo.cinema;

public class Ingresso {
    private EnumTipoIngresso tipo;
    private EnumCategoriaIngresso categoria;

    public Ingresso(EnumTipoIngresso tipo, EnumCategoriaIngresso categoria) {
        this.tipo = tipo;
        this.categoria = categoria;
    }
    public EnumTipoIngresso getTipo() { return tipo; }
    public EnumCategoriaIngresso getCategoria() { return categoria; }

    @Override
    public String toString()
    {
        return String.format("INGRESSO\n" +
                "Tipo: %s\n" +
                "Categoria: %s\n",
                getTipo(),
                getCategoria());
    }
}

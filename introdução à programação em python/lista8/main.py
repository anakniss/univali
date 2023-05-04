import lista8 as m1
import exibeLista as m2

m1.cadastro("Joao", "joao@univali.br", "wifi não conecta")
m1.cadastro("Arthur", "arthur@univali.br", "sem email")
m1.cadastro("Pedro", "pedro@univali.br", "sem email")


resultadoBusca = m1.buscaChamadosPorStatus(m1.situacoes[1], m1.lista)
m2.exibeListaChamados(resultadoBusca)

m1.fechaChamado(1)



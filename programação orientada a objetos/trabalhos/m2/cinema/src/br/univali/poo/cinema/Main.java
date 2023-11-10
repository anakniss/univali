package br.univali.poo.cinema;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Funcionario f = new Funcionario();

        NumeroScanner verificaNum = new NumeroScanner();

        String nome, genero, nomeFilme, tipoTela, localizacao, op = "1";
        int ingresso, categoria, idFilme, horario, n, numAssentos, duracao, resp, i;
        EnumTipoIngresso tipoIngresso = null;
        EnumCategoriaIngresso categoriaIngresso = null;

        while (!op.equals("6")) {

            System.out.println("1. Atender cliente");
            System.out.println("2. Ver sessões");
            System.out.println("3. Incluir sessão");
            System.out.println("4. Iniciar sessão");
            System.out.println("5. Encerrar sessão");
            System.out.println("6. Sair");
            System.out.println("Informe a opção desejada: ");

            op = input.nextLine();

            try {
                switch (op) {
                    case "1":
                        if (f.numSessoes() == 0)
                        {
                            System.out.println("Nenhuma sessão disponível.");
                            break;
                        }
                        System.out.println("FILMES EM CARTAZ\n");

                        i = 0;

                        for (Sessao s : f.getSessoes()) {
                            System.out.printf("%s. %s%n", ++i, s.getFilme());
                        }

                        System.out.println("Infome seu nome: ");
                        nome = input.nextLine();

                        System.out.println("Informe o Tipo Ingresso (Inteiro 1, Meio 2): ");
                        ingresso = verificaNum.solicitarNumero();

                        System.out.println("Informe a Categoria (Físico 1, Online 2): ");
                        categoria = verificaNum.solicitarNumero();

                        System.out.println("Informe o ID do Filme desejado: ");
                        idFilme = verificaNum.solicitarNumero();

                        switch (ingresso)
                        {
                            case 1:
                                tipoIngresso = EnumTipoIngresso.INGRESSOINTEIRO;
                            case 2:
                                tipoIngresso = EnumTipoIngresso.MEIOINGRESSO;
                        }
                        switch (categoria)
                        {
                            case 1:
                                categoriaIngresso = EnumCategoriaIngresso.INGRESSOFISICO;
                            case 2:
                                categoriaIngresso = EnumCategoriaIngresso.INGRESSOONLINE;
                        }

                        Cliente c = new Cliente(nome);
                        c.setIngresso(f.vendaIngresso(tipoIngresso, categoriaIngresso, f.getSessoes().get(idFilme - 1)));
                        System.out.println("Compra finalizada.");

                        break;
                    case "2":
                        if (f.getSessoes().isEmpty()) {
                            System.out.println("Nenhuma sessão disponível.");
                            break;
                        }

                        for (Sessao s : f.getSessoes()) {
                            System.out.println(s.toString());
                        }

                        break;
                    case "3":
                        System.out.println("Nome do filme: ");
                        nomeFilme = input.nextLine();
                        System.out.println("Gênero do filme: ");
                        genero = input.nextLine().toUpperCase();
                        System.out.println("Duração do filme: ");
                        duracao = verificaNum.solicitarNumero();
                        System.out.println("Horário: ");
                        horario = input.nextInt();
                        input.nextLine();

                        Filme filme = new Filme(nomeFilme, duracao, EnumGeneroFilme.valueOf(genero));
                        Sessao sessao = new Sessao(filme, horario);

                        n = 0;

                        while (n <= 0)
                        {
                            System.out.println("Quantas salas possui a sessão?");
                            n = verificaNum.solicitarNumero();
                        }

                        for (int j = 0; j < n; j++)
                        {
                            System.out.printf("Sala %s%n", j + 1);
                            System.out.println("Número de assentos:");
                            numAssentos = verificaNum.solicitarNumero();
                            System.out.println("Tipo de tela:");
                            tipoTela = input.nextLine();
                            System.out.println("Localização:");
                            localizacao = input.nextLine();

                            Sala sala = new Sala(numAssentos, tipoTela, localizacao);
                            sessao.addSala(sala);
                        }
                        f.addSessao(sessao);
                        break;

                    case "4":
                        if (f.getSessoes().isEmpty())
                        {
                            System.out.println("Nenhuma sessão disponível.");
                            break;
                        }

                        System.out.println("Qual sessão deseja iniciar?");
                        i = 0;

                        for (Sessao s : f.getSessoes())
                        {
                            if (!s.isEstadoDaSessao())
                                System.out.printf("%s. %s", ++i, s);
                        }
                        System.out.println("Informe o número da sessão que deseja iniciar:");
                        resp = verificaNum.solicitarNumero();

                        f.getSessoes().get(resp - 1).setEstadoDaSessao(true);
                        System.out.println("Sessão em andamento...");
                        break;
                    case "5":
                        if (f.getSessoes().isEmpty())
                        {
                            System.out.println("Nenhuma sessão em andamento.");
                            break;
                        }

                        System.out.println("Qual sessão deseja encerrar?");

                        i = 0;

                        for (Sessao s : f.getSessoes())
                        {
                            System.out.printf("%s. %s", ++i, s);
                        }

                        System.out.println("Informe o número da sessão que deseja encerrar:");
                        resp = input.nextInt();

                        input.nextLine();

                        f.getSessoes().remove(resp - 1);

                        System.out.println("Sessão encerrada.");

                        break;
                    case "6":
                        return;
                    default:
                        System.out.println("Opção inválida");
                        break;
                }
            }
            catch (Exception e)
            {
                System.err.println(e);
            }
        }
    }
}
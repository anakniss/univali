package View;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Genericos generico = new Genericos();
        CadastrarLivrosView cadastrarLivrosView = new CadastrarLivrosView();
        EmprestarLivroView emprestarLivroView = new EmprestarLivroView();
        RegistrarDevolução registrarDevolução = new RegistrarDevolução();
        MostrarCatalogoLivrosView mostrarCatalogoLivrosView = new MostrarCatalogoLivrosView();
        MostrarEmprestimosView mostrarEmprestimosView = new MostrarEmprestimosView();

        boolean executando = true;
        while (executando) {
            System.out.println("Escolha uma opção:");
            System.out.println("1 - Adicionar livro");
            System.out.println("2 - Emprestar livro");
            System.out.println("3 - Registrar devolução");
            System.out.println("4 - Mostrar catálogo de livros");
            System.out.println("5 - Mostrar empréstimos");
            System.out.println("0 - Sair");
            System.out.print("Opção: ");

            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    cadastrarLivrosView.cadastrarLivro(scanner);
                    break;
                case 2:
                    emprestarLivroView.emprestarLivro(scanner, generico);
                    break;
                case 3:
                    registrarDevolução.registrarDevolucao(scanner);
                    break;
                case 4:
                    mostrarCatalogoLivrosView.mostrarCatalogo();
                    break;
                case 5:
                    mostrarEmprestimosView.mostrarEmprestimos();
                    break;
                case 0:
                    executando = false;
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }
        }
        System.out.println("Encerrando o programa.");
        scanner.close();
    }


}

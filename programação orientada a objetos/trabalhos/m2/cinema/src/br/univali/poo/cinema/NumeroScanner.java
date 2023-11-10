package br.univali.poo.cinema;

import java.util.Scanner;

public class NumeroScanner {

    public int solicitarNumero() {
        Scanner scanner = new Scanner(System.in);
        int numero;

        while (!scanner.hasNextInt()) {
            scanner.next();
            System.out.println("Valor inválido. Digite um número inteiro:");
        }
        numero = scanner.nextInt();
        return numero;
    }
}
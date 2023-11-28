package com.gerenciador;

import com.itextpdf.kernel.pdf.PdfDocument;
import com.itextpdf.kernel.pdf.PdfWriter;
import com.itextpdf.layout.element.Paragraph;

import java.util.Date;
import com.itextpdf.layout.Document;

import javax.xml.crypto.Data;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Scanner;
import java.io.ByteArrayOutputStream;

public class App 
{
        public static void main(String[] args) {
            Scanner input = new Scanner(System.in);
            NumeroScanner numeroScanner = new NumeroScanner();
            String opcao = "1";
            int idPagador, idUnidade, idPagamento, ano, mes;

            while(opcao != "6")
            {
                System.out.println("1. Inserir novo registro de pagamento");
                System.out.println("2. Listar todos os registros");
                System.out.println("3. Excluir um registro");
                System.out.println("4. Imprimir comprovante");
                System.out.println("5. Sair");
                System.out.println("Informe a opção desejada: ");

                opcao = input.nextLine();

                try {
                    Connection c = conectaBD();
                    switch(opcao)
                    {
                        case "1":
                            System.out.println("Informe o ID do Pagador: ");
                            idPagador = numeroScanner.solicitarNumero();
                            System.out.println("Informe o ano de referência: ");
                            ano = numeroScanner.solicitarNumero();
                            System.out.println("Informe o mês de referência: ");
                            mes = numeroScanner.solicitarNumero();
                            System.out.println("Informe o ID da Unidade");
                            idUnidade = numeroScanner.solicitarNumero();

                            byte[] comprovante = gerarComprovante(idPagador, idUnidade);
                            String sqlInsert = "CALL insere_pagamento(?, ?, ?, ?, ?);";
                            PreparedStatement s = c.prepareStatement(sqlInsert);
                            s.setInt(1, idPagador);
                            s.setBytes(2, comprovante);
                            s.setInt(3, ano);
                            s.setInt(4, mes);
                            s.setInt(5, idUnidade);
                            ResultSet r1 = s.executeQuery();

                            break;
                        case "2":
                            String sql = "SELECT \n" +
                                    "    pc.*, \n" +
                                    "    p.nome_completo,\n" +
                                    "    p.email_contato,\n" +
                                    "    p.num_documento_identificacao,\n" +
                                    "    p.telefone_contato,\n" +
                                    "    u.numero_identificador,\n" +
                                    "    u.localizacao\n" +
                                    "FROM \n" +
                                    "    PagamentoCondominio pc\n" +
                                    "JOIN \n" +
                                    "    Pagador p ON pc.id_pagador = p.id_pagador\n" +
                                    "JOIN \n" +
                                    "    Unidade u ON pc.id_unidade = u.id_unidade\n" +
                                    "ORDER BY \n" +
                                    "    pc.ano_referencia ASC,\n" +
                                    "    pc.mes_referencia ASC;";
                            PreparedStatement ps = c.prepareStatement(sql);
                            ResultSet rs = ps.executeQuery();

                            while (rs.next()) {
                                int idPag = rs.getInt("id_pagamento");
                                String nome = rs.getString("nome_completo");
                                java.sql.Date data = rs.getDate("data_pagamento");
                                int mesRef = rs.getInt("mes_referencia");
                                int anoRef = rs.getInt("ano_referencia");
                                String email = rs.getString("email_contato");
                                String localizacao = rs.getString("localizacao");

                                System.out.println("INFORMAÇÕES DE PAGAMENTO");
                                System.out.println("ID Pagamento: " + idPag);
                                System.out.println("Nome: " + nome);
                                System.out.println("Referência: " + mesRef + "/" + anoRef);
                                System.out.println("Data do pagamento: " + data);
                                System.out.println("E-mail: " + email);
                                System.out.println("Localização: " + localizacao + "\n");
                            }
                            break;
                        case "3":
                            System.out.println("Informe o ID do Pagamento: ");
                            idPagamento = numeroScanner.solicitarNumero();

                            String sqlDelete = "CALL exclui_pagamento(?);";
                            PreparedStatement p = c.prepareStatement(sqlDelete);
                            p.setInt(1, idPagamento);
                            ResultSet resultSet = p.executeQuery();
                            break;
                        case "4":
                            System.out.println("Informe o ID de Pagamento: ");
                            idPagamento = numeroScanner.solicitarNumero();
                            downloadPdf(idPagamento);
                            break;
                        case "5":
                            return;
                        default:
                            System.out.println("Opção inválida");
                            break;
                    }
                }
                catch(Exception e)
                {
                    System.err.println(e);
                }
            }
        }
        public static Connection conectaBD() throws SQLException, ClassNotFoundException {
            String url ="jdbc:mysql://localhost:3306/condominio?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true";
            String user ="root";
            String passwd = "130198pi";
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, user, passwd);
            return con ;
        }

    public static byte[] gerarComprovante(int idPagador, int idUnidade) {
        LocalDate dataSistema = LocalDate.now();
        try {
            // Criar um novo documento PDF
            ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
            PdfWriter writer = new PdfWriter(byteArrayOutputStream);
            PdfDocument pdf = new PdfDocument(writer);
            Document document = new Document(pdf);

            // Adicionar informações ao documento
            document.add(new Paragraph("Comprovante de Pagamento"));
            document.add(new Paragraph("Emissão do Comprovante: " + dataSistema));
            document.add(new Paragraph("ID do Pagador: " + idPagador));
            document.add(new Paragraph("ID da Unidade: " + idUnidade));

            // Fechar o documento
            document.close();
            System.out.println("PDF do Comprovante de Pagamento criado com sucesso!");

            return byteArrayOutputStream.toByteArray();

        } catch (Exception e) {
            System.err.println("Erro: Arquivo não encontrado - " + e.getMessage());
        }

        return null;
    }

    public static void downloadPdf(int idPagamento) {

        try {
            Connection cc = conectaBD();
            // Consulta SQL para selecionar o Blob do PDF com base no ID
            String sql = "SELECT comprovante FROM PagamentoCondominio WHERE id_pagamento = ?";
            PreparedStatement pstmt = cc.prepareStatement(sql);
            pstmt.setInt(1, idPagamento);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                // Lendo o Blob do ResultSet
                Blob pdfBlob = rs.getBlob("comprovante");

                // Obtendo os bytes do Blob
                byte[] pdfBytes = pdfBlob.getBytes(1, (int) pdfBlob.length());
                SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd_HHmmss");
                String timestamp = sdf.format(new Date());

                // Salvando o Blob como um arquivo PDF
                String nomeArquivo = "Comprovante_" + timestamp + ".pdf"; // Nome do arquivo de saída
                try (OutputStream outputStream = new FileOutputStream(nomeArquivo)) {
                    outputStream.write(pdfBytes);
                    System.out.println("Arquivo PDF recuperado com sucesso como " + nomeArquivo);
                }
            } else {
                System.out.println("Nenhum arquivo PDF encontrado para o ID fornecido.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


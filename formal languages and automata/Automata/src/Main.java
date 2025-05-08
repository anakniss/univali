import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {

    private JTextArea campoA;
    private JTextArea campoB;
    private JButton analisarButton;
    private JButton limparButton;

    public Main() {
        setTitle("Reconhecedor de Linguagem Regular");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        JPanel panelCampos = new JPanel(new GridLayout(2, 1, 10, 10));

        campoA = new JTextArea(10, 50);
        campoA.setLineWrap(true);
        campoA.setWrapStyleWord(true);
        JScrollPane scrollA = new JScrollPane(campoA);
        scrollA.setBorder(BorderFactory.createTitledBorder("Campo A"));
        panelCampos.add(scrollA);

        campoB = new JTextArea(15, 50);
        campoB.setLineWrap(true);
        campoB.setWrapStyleWord(true);
        campoB.setEditable(false);
        JScrollPane scrollB = new JScrollPane(campoB);
        scrollB.setBorder(BorderFactory.createTitledBorder("Campo B"));
        panelCampos.add(scrollB);

        JPanel panelBotoes = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        analisarButton = new JButton("✔ Analisar");
        limparButton = new JButton("🧹 Limpar");
        panelBotoes.add(analisarButton);
        panelBotoes.add(limparButton);

        add(panelCampos, BorderLayout.CENTER);
        add(panelBotoes, BorderLayout.SOUTH);

        analisarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analisar();
            }
        });

        limparButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                campoA.setText("");
                campoB.setText("");
            }
        });
    }

    private void analisar() {
        String input = campoA.getText().trim();
        campoB.setText("");

        if (input.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Por favor, digite uma sequência no Campo A.", "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        String resultado = processarAutomato(input);
        campoB.setText(resultado);
    }

    private String processarAutomato(String input) {
        int[][] tabela = {
                {6, 9, 5, 2, 7, 9},
                {9, 9, 5, 2, 7, 9},
                {9, 9, 9, 2, 7, 9},
                {9, 9, 9, 9, 7, 9},
                {8, 9, 1, 9, 9, 9},
                {9, 9, 1, 9, 9, 9},
                {9, 4, 9, 9, 9, 9},
                {9, 9, 9, 9, 3, 9},
                {9, 0, 9, 9, 9, 9},
                {9, 9, 9, 9, 9, 9}
        };
        boolean[] estadosFinais = {true, true, true, true, false, false, false, false, false, false};

        // Divide por espaços, quebras de linha ou operadores
        String[] partes = input.split("\\s+");

        StringBuilder resultado = new StringBuilder();

        for (String parte : partes) {
            // Se a parte contém operadores, quebra mais ainda:
            String[] tokens = parte.split("(?=[+\\-*/])|(?<=[+\\-*/])");
            for (String token : tokens) {
                token = token.trim();
                if (token.isEmpty()) continue;

                if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                    resultado.append("operador aritmético: ").append(token).append("\n");
                } else if (temSimboloInvalido(token)) {
                    resultado.append("ERRO: símbolo(s) inválido(s): ").append(token).append("\n");
                } else if (reconheceSentenca(tabela, estadosFinais, token)) {
                    resultado.append("sentença válida: ").append(token).append("\n");
                } else {
                    resultado.append("ERRO: sentença inválida: ").append(token).append("\n");
                }
            }
        }

        return resultado.toString();
    }

    private boolean reconheceSentenca(int[][] tabela, boolean[] ef, String sentenca) {
        int estado = 4; // estado inicial
        for (char simbolo : sentenca.toCharArray()) {
            int coluna = getColuna(simbolo);
            estado = tabela[estado][coluna];
        }
        return ef[estado];
    }

    private int getColuna(char simbolo) {
        switch (simbolo) {
            case 'a': return 0;
            case 'b': return 1;
            case 'c': return 2;
            case 'd': return 3;
            case 'e': return 4;
            default: return 5; // COLUNA_ERRO
        }
    }

    private boolean temSimboloInvalido(String s) {
        for (char c : s.toCharArray()) {
            if ("abcde".indexOf(c) == -1 && "+-*/".indexOf(c) == -1) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Main().setVisible(true));
    }
}

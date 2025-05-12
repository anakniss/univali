import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {

    private JTextArea textAreaA;
    private JTextArea textAreaB;
    private JButton analyzeButton;
    private JButton clearButton;

    public Main() {
        setTitle("Reconhecedor de Linguagem Regular");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        JPanel fieldsPanel = new JPanel(new GridLayout(2, 1, 10, 10));

        textAreaA = new JTextArea(10, 50);
        textAreaA.setLineWrap(true);
        textAreaA.setWrapStyleWord(true);
        JScrollPane scrollA = new JScrollPane(textAreaA);
        scrollA.setBorder(BorderFactory.createTitledBorder("Campo A"));
        fieldsPanel.add(scrollA);

        textAreaB = new JTextArea(15, 50);
        textAreaB.setLineWrap(true);
        textAreaB.setWrapStyleWord(true);
        textAreaB.setEditable(false);
        JScrollPane scrollB = new JScrollPane(textAreaB);
        scrollB.setBorder(BorderFactory.createTitledBorder("Campo B"));
        fieldsPanel.add(scrollB);

        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        analyzeButton = new JButton("Analisar");
        clearButton = new JButton("Limpar");
        buttonsPanel.add(analyzeButton);
        buttonsPanel.add(clearButton);

        add(fieldsPanel, BorderLayout.CENTER);
        add(buttonsPanel, BorderLayout.SOUTH);

        analyzeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                analyze();
            }
        });

        clearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textAreaA.setText("");
                textAreaB.setText("");
            }
        });
    }

    private void analyze() {
        String input = textAreaA.getText().trim();
        textAreaB.setText("");

        if (input.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Por favor, digite uma sequência no Campo A.", "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        String result = processAutomaton(input);
        textAreaB.setText(result);
    }

    private String processAutomaton(String input) {
        int[][] table = {
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
        boolean[] finalStates = {true, true, true, true, false, false, false, false, false, false};

        String[] parts = input.split("\\s+");
        StringBuilder result = new StringBuilder();

        for (String part : parts) {
            String[] tokens = part.split("(?=[+\\-*/])|(?<=[+\\-*/])");
            for (String token : tokens) {
                token = token.trim();
                if (token.isEmpty()) continue;

                if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                    result.append("operador aritmético: ").append(token).append("\n");
                } else if (hasInvalidSymbol(token)) {
                    result.append("ERRO: símbolo(s) inválido(s): ").append(token).append("\n");
                } else if (recognizeSentence(table, finalStates, token)) {
                    result.append("sentença válida: ").append(token).append("\n");
                } else {
                    result.append("ERRO: sentença inválida: ").append(token).append("\n");
                }
            }
        }

        return result.toString();
    }

    private boolean recognizeSentence(int[][] table, boolean[] finalStates, String sentence) {
        int state = 4;
        for (char symbol : sentence.toCharArray()) {
            int column = getColumn(symbol);
            state = table[state][column];
        }
        return finalStates[state];
    }

    private int getColumn(char symbol) {
        switch (symbol) {
            case 'a': return 0;
            case 'b': return 1;
            case 'c': return 2;
            case 'd': return 3;
            case 'e': return 4;
            default: return 5;
        }
    }

    private boolean hasInvalidSymbol(String s) {
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

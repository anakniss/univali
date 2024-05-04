package com.example.pandaapp;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    private LinearLayout layoutHorasTrabalhadas;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lancamento_horas);

        layoutHorasTrabalhadas = findViewById(R.id.layout_horas_trabalhadas);

        TextView textMatricula = findViewById(R.id.text_matricula);
        TextView textNomeCompleto = findViewById(R.id.text_nome_completo);
        TextView textLotacao = findViewById(R.id.text_lotacao);
        TextView textFuncao = findViewById(R.id.text_funcao);

        textMatricula.setText("123456");
        textNomeCompleto.setText("Ana Kniss");
        textLotacao.setText("Departamento de Engenharia");
        textFuncao.setText("Engenheiro");
    }

    @Override
    protected void onResume() {
        super.onResume();
        // Atualizar os campos dinamicamente ao retornar do segundo plano
        atualizarCamposDinamicamente();
    }

    private void atualizarCamposDinamicamente() {
        layoutHorasTrabalhadas.removeAllViews(); // Limpa todos os campos existentes

        Calendar calendar = Calendar.getInstance();
        int horaAtual = calendar.get(Calendar.HOUR_OF_DAY);
        int quantidadeCampos = calcularQuantidadeCampos(horaAtual);

        for (int i = 0; i < quantidadeCampos; i++) {
            EditText editText = new EditText(this);
            editText.setHint("Horas trabalhadas " + (i + 1));
            layoutHorasTrabalhadas.addView(editText);
        }
    }

    private int calcularQuantidadeCampos(int horaAtual) {
        if (horaAtual < 8 || horaAtual >= 18) {
            return 0;
        } else {
            int quantidadeHoras = horaAtual - 8; // Desconta as horas iniciais
            if (horaAtual >= 13) {
                quantidadeHoras--; // Desconta a hora do almoço
            }
            return quantidadeHoras;
        }
    }
}


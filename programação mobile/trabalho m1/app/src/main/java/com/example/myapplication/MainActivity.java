package com.example.myapplication;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {
    private LinearLayout layoutHorasTrabalhadas;
    private ArrayList<String> horasTrabalhadas = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lancamento_horas);

        layoutHorasTrabalhadas = findViewById(R.id.layout_horas_trabalhadas);

        TextView textMatricula = findViewById(R.id.text_matricula);
        TextView textNomeCompleto = findViewById(R.id.text_nome_completo);
        TextView textLotacao = findViewById(R.id.text_lotacao);
        TextView textFuncao = findViewById(R.id.text_funcao);

        textMatricula.setText("Matrícula: 434232");
        textNomeCompleto.setText("Nome: Ana Clara Kniss");
        textLotacao.setText("Departamento: Desenvolvimento");
        textFuncao.setText("Cargo: Desenvolvedora");

        if (savedInstanceState != null) {
            horasTrabalhadas = savedInstanceState.getStringArrayList("horasTrabalhadas");
            for (String hora : horasTrabalhadas) {
                EditText editText = new EditText(this);
                editText.setText(hora);
                layoutHorasTrabalhadas.addView(editText);
            }
        } else {
            adicionarCamposDinamicamente();
        }
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        for (int i = 0; i < layoutHorasTrabalhadas.getChildCount(); i++) {
            EditText editText = (EditText) layoutHorasTrabalhadas.getChildAt(i);
            horasTrabalhadas.add(editText.getText().toString());
        }
        outState.putStringArrayList("horasTrabalhadas", horasTrabalhadas);
    }

    private void adicionarCamposDinamicamente() {
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
            int quantidadeHoras = horaAtual - 8;
            if (horaAtual >= 13) {
                quantidadeHoras--;
            }
            return quantidadeHoras;
        }
    }
}


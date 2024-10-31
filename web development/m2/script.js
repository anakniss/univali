function validarFormulario() {
    const nomeObra = document.getElementById('nomeObra');
    const autor = document.getElementById('autor');
    const ano = document.getElementById('ano');
    const periodo = document.getElementById('periodo');
    const tipo = document.getElementById('tipo');
    const mensagensErro = document.getElementById('mensagensErro');
    mensagensErro.innerHTML = '';
    let erros = [];

    // Reset de bordas
    [nomeObra, autor, ano, periodo, tipo].forEach(campo => campo.classList.remove('borda-vermelha'));

    // Validações
    if (nomeObra.value.length < 6) {
        erros.push('Nome da obra deve ter no mínimo 6 caracteres.');
        nomeObra.classList.add('borda-vermelha');
    }

    if (autor.value.length < 10) {
        erros.push('Autor deve ter no mínimo 10 caracteres.');
        autor.classList.add('borda-vermelha');
    }

    if (!/^\d{1,4}$/.test(ano.value)) {
        erros.push('Ano deve ser um número válido de até 4 dígitos.');
        ano.classList.add('borda-vermelha');
    }

    if (periodo.value === '') {
        erros.push('Selecione um período.');
        periodo.classList.add('borda-vermelha');
    }

    if (tipo.value === '') {
        erros.push('Selecione um tipo.');
        tipo.classList.add('borda-vermelha');
    }

    if (erros.length > 0) {
        erros.forEach(erro => {
            const li = document.createElement('li');
            li.textContent = erro;
            mensagensErro.appendChild(li);
        });
    } else {
        adicionarLinha(nomeObra.value, autor.value, ano.value, periodo.value, tipo.value);
        document.getElementById('formCadastro').reset();
    }
}

function adicionarLinha(nomeObra, autor, ano, periodo, tipo) {
    const tabela = document.getElementById('tabelaObras').getElementsByTagName('tbody')[0];
    const linha = tabela.insertRow();
    linha.innerHTML = `
        <td>${nomeObra}</td>
        <td>${autor}</td>
        <td>${ano}</td>
        <td>${periodo}</td>
        <td>${tipo}</td>
        <td><button onclick="excluirLinha(this)">Excluir</button></td>
    `;
}

function excluirLinha(botao) {
    if (confirm('Tem certeza de que deseja excluir esta linha?')) {
        botao.parentNode.parentNode.remove();
    }
}

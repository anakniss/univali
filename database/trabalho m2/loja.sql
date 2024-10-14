CREATE TABLE Unidade (
	cidade VARCHAR(40) PRIMARY KEY
);

CREATE TABLE Produto (
	descricao VARCHAR(50),
  	preco FLOAT,
  	PRIMARY KEY (descricao)
);

CREATE TABLE Vendedor (
	nome VARCHAR(60),
  	matricula INT PRIMARY KEY
);

CREATE TABLE Venda (
	unidade VARCHAR(40),
  	produto VARCHAR(50),
  	quantidade FLOAT,
  	vendedor INT,
  	data DATE,
  	FOREIGN KEY (unidade) REFERENCES Unidade(cidade),
  	FOREIGN KEY (produto) REFERENCES Produto(descricao),
  	FOREIGN KEY (vendedor) REFERENCES Vendedor(matricula)
);

INSERT INTO Unidade (cidade) VALUES ('Florianópolis');
INSERT INTO Unidade (cidade) VALUES ('São Paulo');
INSERT INTO Unidade (cidade) VALUES ('Rio de Janeiro');
INSERT INTO Unidade (cidade) VALUES ('Belo Horizonte');
INSERT INTO Unidade (cidade) VALUES ('Curitiba');
INSERT INTO Unidade (cidade) VALUES ('Porto Alegre');
INSERT INTO Unidade (cidade) VALUES ('São José');
INSERT INTO Unidade (cidade) VALUES ('Palhoça');

INSERT INTO Produto (descricao, preco) VALUES ('Produto A', 100.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto B', 200.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto C', 300.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto D', 400.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto E', 500.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto F', 600.0);

INSERT INTO Produto (descricao, preco) VALUES ('Produto G', 700.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto H', 800.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto I', 900.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto J', 1000.0);
INSERT INTO Produto (descricao, preco) VALUES ('Produto K', 1100.0);

INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 1', 12345);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 2', 67890);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 3', 11121);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 4', 22224);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 5', 33335);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 6', 44446);

INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 7', 77777);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 8', 88888);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 9', 99999);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 10', 10101);
INSERT INTO Vendedor (nome, matricula) VALUES ('Vendedor 11', 11111);

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Florianópolis', 'Produto A', 10.0, 12345, '2020-10-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Florianópolis', 'Produto A', 10.0, 12345, '2023-10-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São Paulo', 'Produto B', 20.0, 67890, '2019-11-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Rio de Janeiro', 'Produto C', 30.0, 11121, '2023-12-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Belo Horizonte', 'Produto D', 40.0, 22224, '2024-01-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Curitiba', 'Produto E', 1.0, 33335, '2024-02-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Porto Alegre', 'Produto F', 60.0, 44446, '2024-03-22');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Porto Alegre', 'Produto A', 30.0, 12345, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('Curitiba', 'Produto A', 10.0, 12345, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto C', 5.0, 12345, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto A', 5.0, 44446, '2021-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto B', 5.0, 12345, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto C', 10.0, 33335, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto D', 10.0, 67890, '2023-10-21');

INSERT INTO Venda (unidade, produto, quantidade, vendedor, data) 
VALUES ('São José', 'Produto E', 5.0, 44446, '2023-10-21');
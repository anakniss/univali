-- a) Retorne todas as vendas de determinado produto, exibindo detalhes das unidades que realizaram a venda.
SELECT Venda.*, Unidade.*
FROM Venda
JOIN Unidade ON Venda.unidade = Unidade.cidade
WHERE Venda.produto = 'Produto A';

-- b) Retorne todas as vendas de determinado vendedor, exibindo os detalhes da venda, das unidades, e do vendedor.
SELECT Venda.*, Vendedor.*
FROM Venda
JOIN Vendedor ON Venda.vendedor = Vendedor.matricula
WHERE Vendedor.matricula = 11121;

-- c) Retorne todas as vendas de determinada unidade, realizadas nos últimos 2 anos.
SELECT Venda.*, Vendedor.*
FROM Venda
JOIN Vendedor ON Venda.vendedor = Vendedor.matricula
WHERE Venda.data >= DATE_SUB(CURDATE(), INTERVAL 2 YEAR);

-- d)  Retorne todos os produtos que não tiveram vendas realizadas no último mês.
SELECT Produto.*
FROM Produto
LEFT JOIN Venda ON Produto.descricao = Venda.produto
	AND Venda.data >= DATE_SUB(CURDATE(), INTERVAL 1 MONTH)
WHERE  Venda.data IS NULL;

-- e) Retorne todos os vendedores que não realizaram nenhuma venda nos últimos 20 dias.
SELECT Vendedor.*
FROM Vendedor
LEFT JOIN Venda ON Vendedor.matricula = Venda.vendedor
    AND Venda.data >= DATE_SUB(CURDATE(), INTERVAL 20 DAY)
WHERE Venda.data IS NULL;

-- f) Retorne a quantidade de vendas de determinado produto e o valor total destas vendas.
SELECT Produto.descricao, SUM(Venda.quantidade) AS quantidade_total,
SUM(Venda.quantidade * Produto.preco) AS valor_total
FROM Venda
JOIN Produto ON Venda.produto = Produto.descricao
WHERE Produto.descricao = 'Produto A'
GROUP BY Produto.descricao;

-- g) Retorne a quantidade de vendas de determinado vendedor, exibindo o valor total destas vendas e a média dos valores das vendas.
SELECT Vendedor.nome, COUNT(*) AS quantidade_vendas,
SUM(Venda.quantidade * Produto.preco) AS valor_total, 
AVG(Venda.quantidade * Produto.preco) AS media_valor
FROM Venda
JOIN Produto ON Venda.produto = Produto.descricao
JOIN Vendedor ON Venda.vendedor = Vendedor.matricula
WHERE Vendedor.nome = 'Vendedor 1'
GROUP BY Vendedor.nome;

-- h) Retorne todas as unidades que tiveram o valor total de vendas superior a 100.000 no último ano.
SELECT Unidade.cidade, SUM(Venda.quantidade * Produto.preco) AS valor_total
FROM Venda
JOIN Produto ON Venda.produto = Produto.descricao
JOIN Unidade ON Venda.unidade = Unidade.cidade
WHERE Venda.data BETWEEN DATE_SUB(CURDATE(), INTERVAL 1 YEAR) AND CURDATE()
GROUP BY Unidade.cidade
HAVING valor_total > 100000;

-- i) Retorne todos os produtos que tiveram total de vendas nos últimos 3 meses inferior a 20 unidades.
SELECT Produto.descricao, SUM(Venda.quantidade) AS quantidade_total
FROM Produto
LEFT JOIN Venda ON Produto.descricao = Venda.produto
    AND Venda.data BETWEEN DATE_SUB(CURDATE(), INTERVAL 3 MONTH) AND CURDATE()
GROUP BY Produto.descricao
HAVING quantidade_total < 20 OR quantidade_total IS NULL;

-- j) Retorne todos os vendedores que no último ano tiveram valor de vendas acumulado acima da média das vendas de todos os vendedores.
SELECT Vendedor.nome, soma FROM (
    SELECT Venda.vendedor as vendedor, SUM(Venda.quantidade * Produto.preco) as soma 
    FROM loja.venda 
    JOIN Produto ON Venda.produto = Produto.descricao
    WHERE Venda.data >= DATE_SUB(CURDATE(), INTERVAL 1 YEAR)
    GROUP BY Venda.vendedor
) as medias 
JOIN Vendedor ON medias.vendedor = Vendedor.matricula
HAVING soma > (
    SELECT AVG(soma2) FROM (
        SELECT SUM(Venda.quantidade * Produto.preco) as soma2 
        FROM loja.venda 
        JOIN Produto ON Venda.produto = Produto.descricao
        WHERE Venda.data >= DATE_SUB(CURDATE(), INTERVAL 1 YEAR)
        GROUP BY Venda.vendedor
    ) a
);
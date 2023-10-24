-- índice para a consulta D
CREATE INDEX idx_venda_produto ON Venda(produto);

-- índice para a consulta E
CREATE INDEX idx_venda_vendedor ON Venda(vendedor);

-- índice para a consulta H
CREATE INDEX idx_venda_unidade ON Venda(unidade);

-- índice para a consulta I
CREATE INDEX idx_venda_data ON Venda(data);

-- índice para a consulta J
CREATE INDEX idx_produto_descricao ON Produto(descricao);

EXPLAIN ANALYZE SELECT Produto.*
FROM Produto
LEFT JOIN Venda ON Produto.descricao = Venda.produto
	AND Venda.data >= DATE_SUB(CURDATE(), INTERVAL 1 MONTH)
WHERE  Venda.data IS NULL;

EXPLAIN ANALYZE SELECT Vendedor.*
FROM Vendedor
LEFT JOIN Venda ON Vendedor.matricula = Venda.vendedor
    AND Venda.data >= DATE_SUB(CURDATE(), INTERVAL 20 DAY)
WHERE Venda.data IS NULL;

EXPLAIN ANALYZE SELECT Unidade.cidade, SUM(Venda.quantidade * Produto.preco) AS valor_total
FROM Venda
JOIN Produto ON Venda.produto = Produto.descricao
JOIN Unidade ON Venda.unidade = Unidade.cidade
WHERE Venda.data BETWEEN DATE_SUB(CURDATE(), INTERVAL 1 YEAR) AND CURDATE()
GROUP BY Unidade.cidade
HAVING valor_total > 100000;

EXPLAIN ANALYZE SELECT Produto.descricao, SUM(Venda.quantidade) AS quantidade_total
FROM Produto
LEFT JOIN Venda ON Produto.descricao = Venda.produto
    AND Venda.data BETWEEN DATE_SUB(CURDATE(), INTERVAL 3 MONTH) AND CURDATE()
GROUP BY Produto.descricao
HAVING quantidade_total < 20 OR quantidade_total IS NULL;

EXPLAIN ANALYZE SELECT Vendedor.nome, soma FROM (
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
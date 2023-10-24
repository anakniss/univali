CREATE USER 'app1'@'localhost' IDENTIFIED BY 'senha_segura';

GRANT SELECT ON loja.Produto TO 'app1'@'localhost';
GRANT SELECT ON loja.Venda TO 'app1'@'localhost';
GRANT SELECT ON loja.Vendedor TO 'app1'@'localhost';
GRANT SELECT ON loja.Unidade TO 'app1'@'localhost';
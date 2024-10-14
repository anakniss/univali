const mysql = require('mysql');
const { Client } = require('cassandra-driver');

// Configuração do MySQL
const mysqlConnection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '141592Pi!',
    database: 'employees' // Nome do seu banco de dados MySQL
});

// Configuração do Cassandra
const cassandraClient = new Client({
    contactPoints: ['localhost'],
    localDataCenter: 'datacenter1',
    keyspace: 'employee_data' // Nome do seu keyspace no Cassandra
});

// Conectar ao MySQL
mysqlConnection.connect();

// Conectar ao Cassandra
cassandraClient.connect()
    .then(() => console.log('Conectado ao Cassandra'))
    .catch(err => console.error('Erro ao conectar ao Cassandra', err));

// Query para selecionar todos os employees do MySQL
const mysqlQuery = 'SELECT * FROM employees';

// Função para inserir dados no Cassandra
function insertDataIntoCassandra(row) {
    const query = 'INSERT INTO employees (emp_no, birth_date, first_name, last_name, gender, hire_date) VALUES (?, ?, ?, ?, ?, ?)';
    const params = [row.emp_no, row.birth_date, row.first_name, row.last_name, row.gender, row.hire_date];
    return cassandraClient.execute(query, params, { prepare: true });
}

// Executar a query no MySQL e inserir os dados no Cassandra
mysqlConnection.query(mysqlQuery, (error, results) => {
    if (error) throw error;
    results.forEach(row => {
        insertDataIntoCassandra(row)
            .then(() => console.log(`Inserido emp_no ${row.emp_no} no Cassandra`))
            .catch(err => console.error('Erro ao inserir no Cassandra', err));
    });
});

// Fechar conexões
mysqlConnection.end();
cassandraClient.shutdown();

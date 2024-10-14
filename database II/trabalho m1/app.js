const { Sequelize, DataTypes } = require("sequelize");
const MYSQL_IP = "localhost";
const MYSQL_LOGIN = "root";
const MYSQL_PASSWORD = "141592Pi!";
const DATABASE = "sakila";
const sequelize = new Sequelize(DATABASE, MYSQL_LOGIN, MYSQL_PASSWORD, {
  host: MYSQL_IP,
  dialect: "mysql",
  logging: false,
});

const prompt = require("prompt-sync")();

const Customer = sequelize.define(
  "Customer",
  {
    customer_id: {
      type: DataTypes.INTEGER,
      autoIncrement: true,
      primaryKey: true,
    },
    store_id: { type: DataTypes.INTEGER },
    first_name: { type: DataTypes.STRING, allowNull: false },
    last_name: { type: DataTypes.STRING, allowNull: false },
    email: { type: DataTypes.STRING },
    address_id: { type: DataTypes.INTEGER },
  },
  { tableName: "customer", timestamps: false }
);
const Address = sequelize.define(
  "Address",
  {
    address_id: {
      type: DataTypes.INTEGER,
      autoIncrement: true,
      primaryKey: true,
    },
    address: { type: DataTypes.STRING },
    postal_code: { type: DataTypes.STRING, allowNull: false },
    district: { type: DataTypes.STRING },
    city_id: { type: DataTypes.INTEGER },
    phone: { type: DataTypes.STRING },
    location: { type: DataTypes.GEOMETRY },
  },
  { tableName: "address", timestamps: false }
);

const City = sequelize.define(
  "City",
  {
    city_id: {
      type: DataTypes.INTEGER,

      autoIncrement: true,
      primaryKey: true,
    },
    city: { type: DataTypes.STRING },
    country_id: { type: DataTypes.INTEGER },
  },
  { tableName: "city", timestamps: false }
);

Customer.belongsTo(Address, { foreignKey: "address_id" });
City.hasMany(Address, { foreignKey: "city_id" });

async function listCustomers() {
  let customers = await Customer.findAll({
    include: Address,
  });

  customers.forEach((customer) => {
    console.log(
      `Cliente: ${customer.first_name} ${customer.last_name} | Endereço: ${customer.dataValues.Address.dataValues.address}`
    );
  });
}

async function listAddresses() {
  let addresses = await Address.findAll();

  addresses.forEach(async (address) => {
    let city = await City.findByPk(address.city_id);
    console.log(`Endereço: ${address.address} - ${city.dataValues.city}`);
  });
}

async function listIdCities() {
  let cities = await City.findAll();

  cities.forEach(async (city) => {
    console.log(`City ID: ${city.city_id}`);
  });
}

async function addAddress() {
  try {
    const address2 = prompt("Informe o endereço do cliente: ");
    const postalCode = prompt("Informe o código postal do cliente: ");
    const district2 = prompt("Informe o distrito do cliente: ");
    const cityId = prompt("Informe o ID da cidade do cliente: ");
    const phoneNumber = prompt("Informe o telefone do cliente: ");
    const point = { type: "Point", coordinates: [-76.984722, 39.807222] };

    let address = {
      address: address2,
      postal_code: postalCode,
      district: district2,
      city_id: cityId,
      phone: phoneNumber,
      location: point,
    };

    let returnObject = await Address.create(address);
    console.log(returnObject.address_id);
  } catch (error) {
    console.error("Error log", error);
  }
}

async function addCity() {
  try {
    const city2 = prompt("Informe o nome da cidade: ");
    const countryId = prompt("Informe o ID do país da cidade informada: ");

    let city = {
      city: city2,
      country_id: countryId,
    };

    let returnObject = await City.create(city);
    console.log(returnObject.city_id);
  } catch (error) {
    console.error("Error log", error);
  }
}

async function mainMenu() {
  while (true) {
    console.log("1. Listar clientes");
    console.log("2. Listar endereços");
    console.log("3. Listar os IDs das cidades cadastradas");
    console.log("4. Adicionar cliente");
    console.log("5. Adicionar endereço");
    console.log("6. Adicionar cidade");
    console.log("7. Sair");

    const choice = parseInt(prompt("Escolha uma opção: "));

    switch (choice) {
      case 1:
        await listCustomers();
        break;
      case 2:
        await listAddresses();
        break;
      case 3:
        await listIdCities();
        break;
      case 4:
        await addCustomer();
        break;
      case 5:
        await addAddress();
        break;
      case 6:
        await addCity();
        break;
      case 7:
        console.log("Saindo...");
        process.exit(0);
      default:
        console.log("Opção inválida. Por favor, escolha .");
        break;
    }
  }
}

mainMenu();

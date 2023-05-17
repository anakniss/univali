nome = []
sobrenome = []
telefone = []
celular = []
email = []
endereco = []
detalhes = []

contatos = [nome, sobrenome, telefone, celular, email, endereco, detalhes]

def cadastraUsuario():
    contatos[0].append(input("Nome:"))
    contatos[1].append(input("Sobrenome: "))
    contatos[2].append(input("Telefone: "))
    contatos[3].append(input("Celular: "))
    contatos[4].append(input("E-mail: "))
    contatos[5].append(input("Endereço: "))
    contatos[6].append(input("Detalhes: "))

def menu():
    print("1 - Cadastrar novo usuário")
    print("2 - Listar todos os usuários cadastrados na agenda")
    print("3 - Excluir usuário da agenda")
    print("4 - Editar dados de um usuário")
    print("5 - Sair")
i = 0
j = 0
def listarUsuarios(contatos):
    for i in contatos:
        for j in i:
            print(nome[j])
            print(sobrenome[j])
            print(nome[j])
            print(nome[j])
            print(nome[j])

opcao = ''

while opcao != '5':
    menu()
    opcao = input("Informe a opção desejada: ")
    if opcao == '1':
        cadastraUsuario()
    elif opcao == '2':
        listarUsuarios(contatos)




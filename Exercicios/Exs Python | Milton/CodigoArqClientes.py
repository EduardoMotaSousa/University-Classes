# Lista telefonica - v1.0

arqClientes = open("c:\\temp\\arqClientes.txt", "w")

nomeCliente    = input("Nome          : ")
telefone       = input("Telefone      : ")
documento      = input("DOC           : ")
endLogradouro  = input("Rua/Avenida/..: ")
endNumero      = input("Número        : ")
endComplemento = input("Complemento   : ")
endBairro      = input("Bairro        : ")
endCidade      = input("Cidade        : ")
endUF          = input("Siglas Estados: ")
endCEP         = input("CEP           : ")

registro = nomeCliente + ";"
registro += telefone + ";"
registro += documento + ";"
registro += endLogradouro + ";"
registro += endNumero + ";"
registro += endComplemento + ";"
registro += endBairro + ";"
registro += endCidade + ";"
registro += endUF + ";"
registro += endCEP + "."

print(f"Registro: {registro}", file=arqClientes, flush=True)

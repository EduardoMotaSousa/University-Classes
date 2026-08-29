import random

partidas = 10
jogadas = 0

empate = 0
derrota = 0
vitoria = 0

while jogadas < partidas:

#===================COMPUTADOR========================
    
    computador = random.randint(1, 3)

    if computador == 1:
        print("Computador: PEDRA")

    elif computador == 2:
        print("Computador: PAPEL")

    else:
        print("Computador: TESOURA")

#===================USUARIO===========================
        
    usuario = int(input("Escolha 1 - Pedra | 2 - Papel | 3 - Tesoura: "))

    if usuario == 1:
        print("Usuario: PEDRA")

    elif usuario == 2:
        print("Usuario: PAPEL")

    else:
        print("Usuario: TESOURA")

#===================BATALHA===========================
        
    resultado = usuario - computador

    if usuario == computador:
        print("EMPATE!\n")
        empate += 1

    elif resultado == -1 or resultado == 2:
        print("DERROTA!\n")
        derrota += 1

    else:
        print("VITORIA!\n")
        vitoria += 1


    jogadas += 1

#===================MOSTRAR NA TELA===================
        
print(f"FIM DE JOGO!\n"
	f"Você ganhou: {vitoria}\n"
	f"Perdeu: {derrota}\n"
	f"Empate: {empate}\n")
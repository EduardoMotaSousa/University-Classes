import random

PEDRA = 1
PAPEL = 2
TESSOURA = 3

partidas = 10
jogadas = 0

empate = 0
derrota = 0
vitoria = 0

while jogadas < partidas:
    jogadas += 1

#===================COMPUTADOR===================
    
    computador = random.randint(1, 3)

    if computador == 1:
        print("Computador: PEDRA")

    elif computador == 2:
        print("Computador: PAPEL")

    else:
        print("Computador: TESSOURA")

#===================USUARIO===================
        
    usuario = int(input("Escolha 1 - Pedra | 2 - Papel | 3 - Tessoura: "))

    if usuario == 1:
        print("Usuario: PEDRA")

    elif usuario == 2:
        print("Usuario: PAPEL")

    else:
        print("Usuario: TESSOURA")

#===================BATALHA===================
        
    resultado = usuario - computador

    if usuario == computador:
        print("EMPATE!\n")
        empate += 1

    elif resultado == -1 or resultado == 2
        print("DERROTA!\n")
        derrota += 1

    else:
        print("VITORIA\n")
        vitoria += 1

#===================MOSTRAR NA TELA===================
        
print(f"O jogo acabou! Você ganhou: {vitoria} vezes. Perdeu: {derrota}. Empate: {empate}")

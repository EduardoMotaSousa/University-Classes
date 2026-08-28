import random

numSecreto = random.randint(1, 1000)
tentativas = 10
jogadas = 0

print('''
+------------------------------------------------------------+
|         Acerte o número e ganhe um grande NADA!            |
|     Você tem 10 tentativas para não passar vergonha! :P    |
+------------------------------------------------------------+
''')


while jogadas < tentativas:
    jogadas = jogadas + 1
    chute = int(input(f"[{tentativas - jogadas + 1:2d}] Qual o seu chute? "))

    if chute == numSecreto:
        print("Parabens você acertou!!!\n")
        break

    elif chute > numSecreto:
        print("Chutou muito alto:(\n")

    else:
        print("Chutou muito baixo:/\n")
        
print("FIM DE JOGO\n")
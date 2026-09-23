'''Exercicio 018 Faça um programa que peça o tamanho de um arquivo para download (em MB) e a velocidade de um link de Internet (em Mbps), 
calcule e informe o tempo aproximado de download do arquivo usando este link (em minutos).'''

arqMB = float(input("Qual o tamanho do arquivo em MB? "))
veloInt = float(input("Qual a velocidade da internet em Mbps? "))

tempo = (arqMB * 8) / veloInt / 60 # Calcula o tempo transformando MB em bites

print(f"Ira demorar {tempo:.2f} minutos para fazer o download do arquivo")
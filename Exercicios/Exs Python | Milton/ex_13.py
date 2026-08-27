'''Tendo como dado de entrada a altura (h) de uma pessoa, construa um algoritmo que calcule seu peso ideal, 
utilizando as seguintes fórmulas: Para homens: (72.7h) - 58 Para mulheres: (62.1h) - 44.7'''

altura = float(input("Sua altura em metros: "))

print(f"Seu peso ideal(Homem): {72.7 * altura - 58}\n"
      f"Seu peso ideal(Mulher): {62.1 * altura - 44.7}")
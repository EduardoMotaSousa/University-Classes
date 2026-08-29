'''Faça um Programa para uma loja de tintas.

O programa deverá pedir o tamanho em metros quadrados da área a ser pintada.

Considere que a cobertura da tinta é de 1 litro para cada 6 metros quadrados e que a tinta é vendida em latas de 18 litros, que custam R$ 80,00 ou em galões 
de 3,6 litros, que custam R$ 25,00.

Informe ao usuário as quantidades de tinta a serem compradas e os respectivos preços em 3 situações:

comprar apenas latas de 18 litros; 
comprar apenas galões de 3,6 litros; 
misturar latas e galões, de forma que o preço seja o menor. 

Acrescente 10% de folga e sempre arredonde os valores para cima, isto é, considere latas cheias. '''

import math

metros = float(input("Quantos metros vai ser pintado: "))
metros *= 1.1

# 1° Opção | Somente latas
print(f"Latas: {(math.ceil(metros / 108))}\n"
      f"Valor: R${(math.ceil(metros / 108)) * 80:.2f} Reais\n")

# 2° Opção | Somente galões
print(f"Galões: {(math.ceil(metros / 21.6))}\n"
      f"Valor: R${(math.ceil(metros / 21.6)) * 25:.2f} Reais\n")

# 3° Opção | Misturando ambos (Menos valor)
resto_galao = metros - (108 * math.floor(metros / 108))

print(f"Melhor opção: \nLatas: {(math.floor(metros / 108))}\n"
      f"Galões: {(math.ceil(resto_galao / 21.6))}\n"
      f"Valor: R${(math.floor(metros / 108) * 80) + (math.ceil(resto_galao / 21.6) * 25):.2f} Reais")
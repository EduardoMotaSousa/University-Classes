'''Faça um Programa que peça 2 números inteiros e um número real. Calcule e mostre: o produto do dobro do primeiro com metade do segundo. 
a soma do triplo do primeiro com o terceiro. o terceiro elevado ao cubo.'''

num1 = int(input("Entre com o 1° número inteiro: "))
num2 = int(input("Entre com o 2° número inteiro: "))
numF1 = float(input("Entre com o 1° número real: "))

print(f"\nProduto do dobro do primeiro com metade do segundo: {(num1 * 2) * (num2 / 2)}\nA soma do tiplo do primeiro com o terceiro: {num1 * 3 + numF1}\nTerceiro elevado ao cubo: {numF1**3}")
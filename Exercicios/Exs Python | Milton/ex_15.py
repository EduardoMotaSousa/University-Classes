'''Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês.

Calcule e mostre o total do seu salário no referido mês, sabendo-se que são descontados 11% para o Imposto de Renda, 8% para o INSS e 5% 
para o sindicato, faça um programa que nos dê: salário bruto. quanto pagou ao INSS. quanto pagou ao sindicato. o salário líquido. calcule os 
descontos e o salário líquido, conforme a tabela abaixo:

Salário Bruto : R$
IR (11%) : R$
INSS (8%) : R$
Sindicato ( 5%) : R$ = Salário Liquido : R$ Obs.: Salário Bruto - Descontos = Salário Líquido.'''

ganho = float(input("Quanto você ganha por hora? "))
horas = float(input("Quntas horas você trabalha por mês? "))

salario = ganho * horas

descontos = (salario * 0.11) + (salario * 0.08) + (salario * 0.05)

print(f"\nSalário Bruto: R${salario:.2f} Reais\n"
      f"IR (11%): R${salario * 0.11:.2f} Reais\n"
      f"INSS (8%): R${salario * 0.08:.2f} Reais\n"
      f"Sindicato (5%): R${salario * 0.05:.2f} Reais\n\n"
      f"Salário Liquido: R${salario - descontos} Reais\n"
      f"Descontos totais: R${descontos} Reais\n")

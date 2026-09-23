# Lista 1 - Exercicio 14
# Calculo de salário liquido

# FUNÇÕES

def calculaDescontoIR(salarioBruto):

    if(salarioBruto < 5000):
        descontoIR = 0

    elif(salarioBruto < 10000):
        descontoIR = 0.11

    else:
        descontoIR = 0.25

    valorDescontado = salarioBruto * descontoIR

    return valorDescontado

# Definição de variáveis

salarioPorHora = 0
horasTrabalhadas = 0
salarioBruto = 0
salarioLiquido = 0

descontoIR = 0
descontoINSS = 0.08
descontoSindicato = 0.05

valorDescontadoIR = 0
valorDescontadoINSS = 0
valorDesontadoSindicato = 0
valorDescontadoTotal = 0

# Solicita informções para o usuário

salarioPorHora = float(input("Qual seu salario/hora? "))
horasTrabalhadas = float(input("Quntas horas você trabalhou? "))


# Calculo

salarioBruto = salarioPorHora * horasTrabalhadas

valorDescontadoIR = calculaDescontoIR(salarioBruto)
valorDescontadoINSS = salarioBruto * descontoINSS
valorDescontadoSindicato = salarioBruto * descontoSindicato

valorDescontadoTotal = valorDescontadoIR + valorDescontadoINSS + valorDescontadoSindicato

salarioLiquido = salarioBruto - valorDescontadoTotal
                        
# Exibe

print(f"\nSalário Bruto: R${salarioBruto:.2f} Reais\n"
      f"IR ({(valorDescontadoIR / salarioBruto) * 100:.0f}%): R${valorDescontadoIR:.2f} Reais\n"
      f"INSS (8%): R${valorDescontadoINSS:.2f} Reais\n"
      f"Sindicato (5%): R${valorDescontadoSindicato:.2f} Reais\n"
      f"Salário Liquido: R${salarioLiquido:.2f} Reais\n"
      f"Descontos Totais: R${valorDescontadoTotal:.2f} Reais\n")

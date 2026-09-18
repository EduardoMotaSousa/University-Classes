# --------------------------------------------#
# Classes que representa uma carta de baralho #
# --------------------------------------------#

class Baralho:

    NAIPES = ["♦", "♠", "♥", "♣"]
    VALORES = ['4', '5', '6', '7', 'Q', 'J', 'K', 'A', '2', '3']

    CARTAS = []

    def __init__(self):
        for naipe in self.NAIPES:
            for valor in self.VALORES:
                carta = Carta(naipe, valor)
                self.CARTAS.append(carta)
                
    def mostrarCartas(self):
        return self.CARTAS

class Carta:

    ''' ATRIBUTOS '''

    VALOR = ''
    NAIPE = ''

    ''' MÉTODOS '''

    # Construtor
    
    def __init__(self, naipe, valor):
        self.NAIPE = naipe
        self.VALOR = valor

    # Método que devolve naipe e valor
    
    def __str__(self):
        return self.VALOR + ' de ' + self.NAIPE

    # Método para alterar valor

    def alterarValor(self, valor):
        self.VALOR = valor


    # Método para alterar nipe
    
    def alterarNaipe(self, naipe):
        self.NAIPE = naipe
        
    
# PROGRAMA PRINCIPAL

baralho = Baralho()
#print(baralho.mostrarCartas())
for carta in baralho.mostrarCartas():
    print(carta)

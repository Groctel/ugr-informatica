# encoding: utf-8
# frozen_string_literal: true

require_relative "casilla"

module Civitas

##
# Modelo del tablero por el que viajan los jugadores a lo largo de la partida.
# Está formado por diferentes casillas en un orden cíclico predefinido.

class Tablero
  ## Posición en la que se encuentra la casilla de la cárcel.
  attr_reader :num_casilla_carcel

  ## Vector donde se almacenan las casillas que componen el tablero.
  attr_reader :casillas

  ##
  # Crea un tablero inicializando el contenedor subyacente a un vector vacío de
  # Casilla sin juez ni pasos por salida. En caso de que se especifique una
  # casilla de cárcel menor o igual que 0, ésta se inicializa por defecto a 1.
  # Recibe la siguiente lista de argumentos:
  #
  # num_casilla_carcel:: Posición en la que se encontrará la cárcel.

  def initialize(num_casilla_carcel)
    @casillas           = []
    @num_casilla_carcel = [1, num_casilla_carcel].max
    @por_salida         = 0
    @tiene_juez         = false
  end

  private

  ##
  # Comprueba si la siguiente casilla a añadir al tablero es la casilla de la
  # cárcel, en cuyo caso la crea y la añade.

  def aniade_carcel
    if @casillas.length == @num_casilla_carcel
      carcel = Casilla.new_descanso("Mazmorras reales")
      @casillas << carcel
    end
  end

  ##
  # Consultor de la corrección del tablero. Se considera correcto un tablero que
  # tenga una casilla de cárcel y una casilla de juez.
  #
  # Devuelve booleanamente si el tablero es correcto.

  def correcto
    @casillas.length > @num_casilla_carcel && @tiene_juez
  end

  ##
  # Consultor de la corrección de un índice de casilla. Se considera correcto un
  # índice de casilla cuyo valor sea menor que el total de casillas que
  # ocmponen el tablero, que debe ser correcto por su parte. Recinbe la
  # siguiente lista de argumentos:
  #
  # num_casilla:: Índice de la casilla que se comprueba si es correcto.
  #
  # Devuelve booleanamente si el índice de la casilla es correcto.

  def casilla_correcta(num_casilla)
    correcto && @num_casilla < @casillas.length
  end

  public

  ##
  # Añade una casilla al tablero, comprobando si debe añadir una cárcel antes o
  # después de la misma y haciéndolo en caso afirmativo. Recibe la siguiente
  # lista de argumentos:
  #
  # casilla:: Casilla a añadir al final del tablero.

  def <<(casilla)
    aniade_carcel
    @casillas << casilla
    aniade_carcel
  end

  ##
  # Si el tablero no contiene una casilla de tipo juez, crea una casilla de
  # dicho tipo y la añade.

  def aniade_juez
    if !@tiene_juez
      juez = Casilla.new_juez("Guardia real", @num_casilla_carcel)
      @casillas << juez

      @tiene_juez = true
    end
  end

  ##
  # Calcula la tirada que necesita recorrer un jugador en la casilla  +origen+
  # para llegar a la casilla +destino+. Recibe la siguiente lista de argumentos:
  #
  # origen:: Casilla en la que se encuentra el jugador.
  # destino:: Casilla a la que se desea llegar.
  #
  # Devuelve el número de casillas que el jugador necesita recorrer para llegar
  # a la casilla de destino.

  def calcular_tirada(origen, destino)
    (tirada = destino - origen) > 0 ? tirada : tirada + @casillas.length
  end

  ##
  # Consultor de la casilla en un índice. Recibe la siguiente lista de
  # argumentos:
  #
  # num_casilla:: Índice de la casilla que se consulta.
  #
  # Devuelve el objeto de la casilla identificada por el índice especificado.

  def [](num_casilla)
    num_casilla <= @casillas.length ? @casillas[num_casilla] : nil
  end

  ##
  # Consultor de las veces que el jugador ha pasado por salida en el último
  # turno. Al realizar la consulta, se decrementa en una unidad el número de
  # veces que se pasa.
  #
  # Devuelve el número de veces restantes que se debe tener en cuenta los pasos
  # del jugador por la casilla de salida en el último turno.

  def get_por_salida
    por_salida_original = @por_salida
    @por_salida         = [0, por_salida - 1].max

    por_salida_original
  end

  ##
  # Calcula la posición a la que avanza el jugador tras una tirada del dado. En
  # caso de que el tablero no sea correcto, la tirada toma un valor nulo. Si el
  # jugador pasa por la casilla de salida al realizar la tirada, se incrementa
  # el número de veces que éste ha pasdo por salida en el último turno. Recibe
  # la siguiente lista de argumentos:
  #
  # actual:: Posición actual del jugador.
  # tirada:: Valor obtenido por el jugador en la última tirada.
  #
  # Devuelve la posición en la que el jugador acaba tras avanzar tantas casillas
  # como indica la tirada.

  def nueva_posicion(actual, tirada)
    nueva = nil

    if correcto
      nueva = (actual + tirada) % @casillas.length

      if nueva != actual + tirada
        @por_salida += 1
      end
    end

    nueva
  end
end
end

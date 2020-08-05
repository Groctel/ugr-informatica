# encoding: utf-8
# frozen_string_literal: true

require_relative "enum/tipo_casilla"
require_relative "jugador"
require_relative "mazo_sorpresas"
require_relative "sorpresa"
require_relative "titulo_propiedad"

module Civitas

##
# Modelo de las casillas por las que se mueve el jugador a través del tablero
# durante la partida. Cada casilla viene definida por un TipoCasilla, de forma
# que adoptan diferentes funciones en función de éste.

class Casilla
  ## Cadena que describe la instancia del objeto.
  attr_reader :nombre

  ## TítuloPropiedad asociado a las casillas de tipo TipoCasilla::CALLE.
  attr_reader :titulo

  ##
  # Recibe las instrucciones de inicialización de los constructores públicos e
  # inicializa las casillas a los valores adecuedos. Recibe la siguiente lista
  # de argumentos:
  #
  # tipo:: TipoCasilla que define el comportamiento de la casilla.
  # nombre:: Nombre por el cual se identifica la casilla.
  # titulo:: TituloPropiedad asociado a la casilla.
  # importe:: Cantidad que se le sustrae al jugador al caer en la casilla.
  # mazo:: MazoSorpresas del que se toman las cartas de Sorpresa.

  def initialize(tipo, nombre, titulo, importe, mazo)
    @importe = importe
    @mazo    = mazo
    @nombre  = nombre
    @titulo  = titulo
    @tipo    = tipo
  end

  private_class_method :new

  ##
  # Inicializa las casillas de +TipoCasilla::CALLE+ con su correspondiente
  # TituloPropiedad llamando al constructor privado. Recibe la siguiente lista
  # de argumentos:
  #
  # titulo:: TituloPropiedad asociado a la casilla.

  def self.new_calle(titulo)
    new(TipoCasilla::CALLE, titulo.nombre, titulo, nil, nil)
  end

  ##
  # Inicializa las casillas de +TipoCasilla::DESCANSO+ únicamente con su nombre
  # llamando al constructor privado. Recibe la siguiente lista de argumentos:
  #
  # nombre:: Nombre por el cual se identifica la casilla.

  def self.new_descanso(nombre)
    new(TipoCasilla::DESCANSO, nombre, nil, nil, nil)
  end

  ##
  # Inicializa las casillas de +TipoCasilla::IMPUESTO+ con el importe que debe
  # abonar el jugador a la banca al caer en ella y su nombre llamando al
  # constructor privado. Recibe la siguiente lista de argumentos.
  #
  # nombre:: Nombre por el cual se identifica la casilla.
  # importe:: Cantidad que se le sustrae al jugador al caer en la casilla.

  def self.new_impuesto(nombre, importe)
    new(TipoCasilla::IMPUESTO, nombre, nil, importe, nil)
  end

  ##
  # Inicializa las casillas de +TipoCasilla::JUEZ+ con el número de la casilla
  # de cárcel al que se envía al jugador al caer en ella y su nombre llamando al
  # constructor privado. Recibe la siguiente lista de argumentos:
  #
  # nombre:: Nombre por el cual se identifica la casilla.
  # num_casilla_carcel:: Casilla donde se encuentra la cárcel en el tablero.

  def self.new_juez(nombre, num_casilla_carcel)
    @@carcel = num_casilla_carcel

    new(TipoCasilla::JUEZ, nombre, nil, nil, nil)
  end

  ##
  # Inicializa las casillas de +TipoCasilla::SORPRESA+ con el MazoSorpresas del
  # que el jugador roba una carta al caer en ella y su nombre llamando al
  # constructor privado. Recibe la siguiente lista de argumentos:
  #
  # nombre:: Nombre por el cual se identifica la casilla.
  # mazo:: MazoSorpresas del que se toman las cartas de Sorpresa.

  def self.new_sorpresa(nombre, mazo)
    new(TipoCasilla::SORPRESA, nombre, nil, nil, mazo)
  end

  private

  ##
  # Envía al tablero un mensaje indicando qué jugador ha caído en qué casilla.
  # Recibe la siguiente lista de argumentos:
  #
  # actual:: Índice del jugador actual.
  # todos:: Vector que contiene a todos los jugadores.

  def informe(actual, todos)
    Diario.instance.ocurre_evento("#{todos[actual].nombre} cae en #{to_s}")
  end

  # def recibe_jugador_calle actual, todos
  # end

  ##
  # Si el jugador es correcto, informa al Diario de que ha caído en la casilla y
  # le hace pagar un impuesto igual al importe indicado en la misma.
  #
  # actual:: Índice del jugador actual.
  # todos:: Vector que contiene a todos los jugadores.

  def recibe_jugador_impuesto(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      todos[actual].paga_impuesto(@importe)
    end
  end

  ##
  # Si el jugador es correcto, informa al Diario de que ha caído en la casilla y
  # lo envía a la cárcel.
  #
  # actual:: Índice del jugador actual.
  # todos:: Vector que contiene a todos los jugadores.

  def recibe_jugador_juez(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      todos[actual].encarcelar(@@carcel)
    end
  end

  # def recibe_jugador_sorpresa actual, todos
  # end

  public

  ##
  # Comprueba que el jugador proporcionado es correcto, para lo cual debe ser un
  # índice válido dentro del vector de jugadores.
  #
  # actual:: Índice del jugador actual.
  # todos:: Vector que contiene a todos los jugadores.
  #
  # Devuelve booleanamente si el índice recibido es válido.

  def jugador_correcto(actual, todos)
    0 <= actual && actual < todos.length
  end

  # def recibe_jugador actual, todos
  # end

  ##
  # Proporciona la forma de imprimir la casilla en la salida estándar.
  #
  # Devuelve el nombre de la misma.

  def to_s
    @nombre
  end
end
end

# encoding: utf-8
# frozen_string_literal: true

module Civitas

##
# Modelo de las sorpresas que obtienen los jugadores a lo largo de la partida.
# Por ahora la sorpresa contiene únicamente una plantilla de uso básico que
# almacena su texto y permite su lectura.

class Sorpresa
  ## Cadena que describe la instancia del objeto.
  attr_reader :texto

  ##
  # Recibe las instrucciones de inicialización de los constructores públicos e
  # inicializa las sorpresas a los valores adecuedos. Recibe la siguiente lista
  # de argumentos:
  #
  # tipo:: TipoSorpresa que define el comportamiento de la sorpresa.
  # texto:: Texto que acompaña a la sorpresa.
  # tablero:: Referencia al Tablero para realizar operaciones sobre el mismo.
  # valor:: Cantidad que se gestiona en el efecto de la sorpresa.
  # mazo:: Referencia al MazoSorpresas para realizar operaciones sobre el mismo.

  def initialize(tipo, texto, tablero, valor, mazo)
    @mazo    = mazo
    @tablero = tablero
    @texto   = texto
    @tipo    = tipo
    @valor   = valor
  end

  private_class_method :new

  ##
  # Inicializa las sorpresas de +TipoSorpresa::IR_CARCEL+ con una referencia al
  # Tablero llamando al constructor privado. Recibe la siguiente lista de
  # argumentos:
  #
  # tipo:: TipoSorpresa que define el comportamiento de la sorpresa.
  # tablero:: Referencia al Tablero para realizar operaciones sobre el mismo.

  def self.new_carcel(tipo, tablero)
    new(tipo, "¡Alto, maleante! ¡Cumple tu sentencia!", tablero, nil, nil)
  end

  ##
  # Inicializa las sorpresas de +TipoSorpresa::IR_CASILLA+ con una referencia al
  # Tablero y el valor de la Casilla a enviar al jugador llamando al constructor
  # privado. Recibe la siguiente lista de argumentos:
  #
  # tipo:: TipoSorpresa que define el comportamiento de la sorpresa.
  # tablero:: Referencia al Tablero para realizar operaciones sobre el mismo.
  # valor:: Índice de la Casilla a la que se envía al Jugador.
  # texto:: Texto que acompaña a la sorpresa.

  def self.new_casilla(tipo, tablero, valor, texto)
    new(tipo, texto, tablero, valor, nil)
  end

  ##
  # Inicializa las sorpresas de +TipoSorpresa::PAGAR_COBRAR+,
  # +TipoSorpresa::POR_EDIFICIO+ y +TipoSorpresa::POR_JUGADOR+ llamando al
  # constructor privado. Recibe la siguiente lista de argumentos:
  #
  # tipo:: TipoSorpresa que define el comportamiento de la sorpresa.
  # valor:: Cantidad monetaria que se gestiona en el efecto de la sorpresa.
  # texto:: Texto que acompaña a la sorpresa.

  def self.new_generico(tipo, valor, texto)
    new(tipo, texto, nil, valor, nil)
  end

  ##
  # Inicializa las sorpresas de +TipoSorpresa::SALVOCONDUCTO+ con una referencia
  # MazoSorpresas llamando al constructor privado. Recibe la siguiente lista de
  # argumentos:
  #
  # tipo:: TipoSorpresa que define el comportamiento de la sorpresa.
  # mazo:: Referencia al MazoSorpresas para realizar operaciones sobre el mismo.

  def self.new_salvoconducto(tipo, mazo)
    new(tipo, "Por decreto real, queda absuelto de toda culpa.", nil, nil, mazo)
  end

  private

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se envía al jugador a la casilla especificada. Recibe la
  # siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_casilla(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      origen  = todos[actual].casilla_actual
      tirada  = @tablero.calcular_tirada(origen, @valor)
      destino = @tablero.nueva_posicion(origen, tirada)

      actual[todos].mover_a_casilla(destino)
      @tablero[destino].recibe_jugador(actual, todos)
    end
  end

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se envía al jugador a la cárcel. Recibe la siguiente lista
  # de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_carcel(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      todos[actual].encarcelar(@tablero.num_casilla_carcel)
    end
  end

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se modifica el saldo del mismo en base al valor de la
  # sorpresa. Recibe la siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_pagar_cobrar(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      todos[actual].modificar_saldo(@valor)
    end
  end

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se modifica el saldo del mismo en base al valor de la
  # sorpresa y la cantidad de edificios que éste posee. Recibe la siguiente
  # lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_por_edificio(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      todos[actual].modificar_saldo(@valor * todos[actual].cantidad_edificios)
    end
  end

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se modifica el saldo del mismo en base al valor de la
  # sorpresa multiplicado por el total de jugadores en la partida y resta a cada
  # un de dichos jugadores el valor de la sorpresa. Recibe la siguiente lista de
  # argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_por_jugador(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)

      cobrar = Sorpresa.new_generico(TipoSorpresa::PAGAR_COBRAR, \
                                     -@valor, @texto)
      pagar  = Sorpresa.new_generico(TipoSorpresa::PAGAR_COBRAR, \
                                     @valor * (todos.length - 1), @texto)

      todos.length.times do |jugador|
        jugador == actual ? pagar.aplicar_pagar_cobrar(jugador, todos) \
                          : cobrar.aplicar_pagar_cobrar(jugador, todos)
      end
    end
  end

  ##
  # Si el jugador definido por los argumentos es correcto, se realiza un informe
  # de la operación y se comprueba si algún jugador posee el salvoconducto. Si
  # no se encuentra, éste se saca del mazo y se da al jugador. Recibe la
  # siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar_salvoconducto(actual, todos)
    if jugador_correcto(actual, todos)
      informe(actual, todos)
      existe = false

      todos.each do |jugador|
        if jugador.tiene_salvoconducto
          existe = true
        end
      end

      if !existe
        todos[actual].obtener_salvoconducto(self)
        sacar_del_mazo
      end
    end
  end

  ##
  # Informa al Diario de que un jugador ha recibido una sorpresa. Recibe la
  # siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def informe(actual, todos)
    Diario.instance.ocurre_evento("#{todos[actual].nombre} recibe sorpresa: " \
                                  "#{@texto}")
  end

  public

  ##
  # Aplica la sorpresa al jugador llamando al método privado correspondiente.
  # Recibe la siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.

  def aplicar(actual, todos)
    case @tipo
    when TipoSorpresa::IR_CARCEL
      aplicar_carcel(actual, todos)
    when TipoSorpresa::IR_CASILLA
      aplicar_casilla(actual, todos)
    when TipoSorpresa::PAGAR_COBRAR
      aplicar_pagar_cobrar(actual, todos)
    when TipoSorpresa::POR_EDIFICIO
      aplicar_por_edificio(actual, todos)
    when TipoSorpresa::POR_JUGADOR
      aplicar_por_jugador(actual, todos)
    when TipoSorpresa::SALVOCONDUCTO
      aplicar_salvoconducto(actual, todos)
    end
  end

  ##
  # Mete de vuelta en el mazo la sorpresa de +TipoSorpresa::SALVOCONDUCTO+
  # habilitándola.

  def devolver_al_mazo
    if @tipo == TipoSorpresa::SALVOCONDUCTO
      @mazo.habilitar_carta_especial(self)
    end
  end

  ##
  # Comprueba si el índice del jugador al que se intenta acceder es menor que el
  # tamaño del vector de jugadores. Recibe la siguiente lista de argumentos:
  #
  # actual:: Índice del jugador al que se le aplica la sorpresa.
  # todos:: Vector de todos los jugadores disponibles en la partida.
  #
  # Devuelve booleanamente si el jugador al que se intenta acceder es válido.

  def jugador_correcto(actual, todos)
    actual < todos.length
  end

  ##
  # Saca del mazo la sorpresa de +TipoSorpresa::SALVOCONDUCTO+ inhabilitándola.

  def sacar_del_mazo
    if @tipo == TipoSorpresa::SALVOCONDUCTO
      @mazo.inhabilitar_carta_especial(self)
    end
  end

  ##
  # Proporciona la forma de imprimir la sorpresa en la salida estándar.
  #
  # Devuelve el texto de la misma.

  def to_s
    @texto
  end
end
end

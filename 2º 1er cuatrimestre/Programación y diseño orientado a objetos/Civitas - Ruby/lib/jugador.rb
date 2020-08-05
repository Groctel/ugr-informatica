# encoding: utf-8
# frozen_string_literal: true

module Civitas

##
# Modelo de los jugadores que llevan a cabo diversas acciones a lo largo de la
# partida. Dichas acciones están limitadas a las normas del juego e implementan
# mecanismos de seguridad para no realizarlas en momentos erróneos.

class Jugador
  def initialize(nombre)
    @@casas_max       = 4
    @@hoteles_max     = 4
    @@casas_por_hotel = 4
    @@paso_por_salida = 1000
    @@precio_libertad = 200
    @@saldo_inicial   = 7500

    @encarcelado    = false
    @nombre         = nombre
    @casilla_actual = 0
    @propiedades    = []
    @puede_comprar  = false
    @saldo          = @@saldo_inicial
    @salvoconducto  = nil
  end

  protected

  def self.new_copia(otro)
  end

  private

  def propiedad_correcta(ip)
  end

  def get_casas_max
  end

  def get_hoteles_max
  end

  def get_precio_libertad
  end

  def get_premio_paso_salida
  end

  ##
  # Devuelve la Sorpresa de +TipoSorpresa::SALVOCONDUCTO+ al mazo y la elimina
  # de la mano del jugador.

  def perder_salvoconducto
    @salvoconducto.devolver_al_mazo
    @salvoconducto = nil
  end

  ##
  # Consulta si el jugador tiene poder adquisitivo suficiente como para salir de
  # la cárcel desembolsándose el precio de la libertad mediante una llamada a
  # puede_gastar. El por qué no se llama directamente a este método es un
  # problema NP que atormentó a Alan Turing en pesadillas duranate décadas.
  #
  # Devuelve booleanamente si el saldo del jugador es mayor o igual que la
  # cantidad que debe pagar para salir de la cárcel.

  def puede_salir_carcel_pagando
    puede_gastar(@@precio_libertad)
  end

  def puede_edificar_casa(propiedad)
  end

  def puede_edificar_hotel(propiedad)
  end

  protected

  ##
  # Comprueba booleanamente si el jugador debe ir a la cárcel siempre que no se
  # encuentre en ella. Las llamadas a este método asumen que siempre debe ir a
  # menos que el jugador posea la Sorpresa de +TipoSorpresa::SALVOCONDUCTO+, en
  # cuyo caso lo pierde y se informa al Diario de este hecho.
  #
  # Devuelve booleanamente si el jugador debe ir a la cárcel.

  def debe_ser_encarcelado
    debe_serlo = false

    if !@encarcelado
      if tiene_salvoconducto
        Diario.instance.ocurre_evento("#{to_s} evita entrar en prisión.")
        perder_salvoconducto
      else
        debe_serlo = true
      end
    end

    debe_serlo
  end

  def get_nombre
  end

  public

  ##
  # Compara a un jugador con respecto a otro de forma que el orden del valor de
  # la comparación con respecto al 0 indica el orden del jugador actual con
  # respecto al comparado. Recibe la siguiente lista de argumentos:
  #
  # jugador:: Jugador con el que se compara al jugador actual.
  #
  # Devuelve el orden del jugador actual con respecto al comparado en función de
  # su saldo, de forma que los valores negativos indican que es menor, los
  # positivos que es mayor y el 0 que ambos son iguales.

  def <=>(jugador)
    @saldo <=> jugador.saldo
  end

  def cancelar_hipoteca
  end

  def cantidad_edificios
  end

  def comprar(titulo)
  end

  def construir_casa(ip)
  end

  def construir_hotel(ip)
  end

  def en_bancarrota
  end

  ##
  # Envía al jugador a la cárcel si éste debe ser encarcelado y deja constancia
  # de ello en el Diario. Recibe la siguiente lista de argumentos:
  #
  # num_casilla_carcel:: Índice de la casilla en la que se encuentra la cárcel.
  #
  # Devuelve el estado de encarcelamiento del jugador.

  def encarcelar(num_casilla_carcel)
    if debe_ser_encarcelado
      mover_a_casilla(num_casilla_carcel)
      @encarcelado = true
      Diario.instance.ocurre_evento("#{to_s} entra en prisión.")
    end

    @encarcelado
  end

  ##
  # Consulta si el jugador tiene gestionar inmobiliarias pendiente, para lo
  # cual debe tener al menos una propiedad a su disposición.
  #
  # Devuelve booleanamente si el jugador tiene propiedades compradas.

  def gestiones_pendientes
    propiedades.length > 0
  end

  def get_casas_por_hotel
  end

  def get_num_casilla_actual
  end

  def get_puede_comprar
  end

  def hipotecar(it)
  end

  ##
  # Suma al saldo la cantidad especificada (que puede ser negativa). Recibe la
  # siguiente lista de argumentos:
  #
  # cantidad:: Cantidada monetaria por la que modificar el saldo del jugador.
  #
  # Siempre devuelve +true+.

  def modificar_saldo(cantidad)
    @saldo += cantidad
    true
  end

  ##
  # Siempre que el jugador se encuentre en libertad, se modifica su casilla sin
  # que puedan comprar más en el turno y se informa al Diario de ello. Recibe la
  # siguiente lista de argumentos:
  #
  # num_casilla:: Índice de la Casilla a la que se mueve al jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def mover_a_casilla(num_casilla)
    exito = false

    if !@encarcelado
      @casilla_actual = num_casilla
      @puede_comprar  = false
      Diario.instance.ocurre_evento("#{to_s} movido a casilla "\
                                    "#{@casilla_actual}")
      exito = true
    end

    exito
  end

  ##
  # Si el jugador se encuentre en libertad, se le almacena la referencia a la
  # Sorpresa de +TipoSorpresa::SALVOCONDUCTO+. Recibe la siguiente lista de
  # argumentos:
  #
  # sorpresa:: Referencia al salvoconducto.
  #
  # Devuelve booleanamente el éxito de la operación.

  def obtener_salvoconducto(sorpresa)
    exito = false

    if !@encarcelado
      @salvoconducto = sorpresa
    end

    exito
  end

  ##
  # LLama a modificar_saldo para restarle la cantidad que debe pagar el jugador.
  # Recibe la siguiente lista de argumentos:
  #
  # cantidad:: Cantidad que debe desembolsarse el jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def pagar(cantidad)
    modificar_saldo(-cantidad)
  end

  ##
  # Si el jugador no está encarcelado, llama a pagar para sustraer al jugador la
  # cantidad especificada. Recibe la siguiente lista de argumentos:
  #
  # cantidad:: Cantidad que debe desembolsarse el jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def pagar_alquiler(cantidad)
    exito = false

    if !@encarcelado
      exito = pagar(cantidad)
    end

    exito
  end

  ##
  # Si el jugador no está encarcelado, llama a pagar para sustraer al jugador la
  # cantidad especificada. Recibe la siguiente lista de argumentos:
  #
  # cantidad:: Cantidad que debe desembolsarse el jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def pagar_impuesto(cantidad)
    exito = false

    if !@encarcelado
      exito = pagar(cantidad)
    end

    exito
  end

  def pasar_por_salida
  end

  def propiedad_correcta
  end

  ##
  # Modifica el atributo que indica si el jugador puede comprar una casilla en
  # base a si se encuentra en la cáracel, siendo ambos atributos conjuntamente
  # verdaderos o falsos.
  #
  # Devuelve el valor de dicho atributo

  def puede_comprar_casilla
    @puede_comprar = @encarcelado ? false : true
    @puede_comprar
  end

  ##
  # Comprueba si el jugador se encuentra en libertad y si, en ese caso, su saldo
  # es mayor o igual a la cantidad que procede a desembolsarse. Recibe la
  # siguiente lista de argumentos:
  #
  # cantidad:: Dinero que se comprueba si el jugador puede gastar.
  #
  # Devuelve booleanamente si el jugador puede permitirse gastar dicha cantidad.

  def puede_gastar(cantiad)
    puede = false

    if !@encarcelado
      puede = @saldo >= cantidad
    end

    puede
  end

  ##
  # Si el jugador no está encarcelado, llama a modificar_saldo para bonificar al
  # jugador la cantidad especificada. Recibe la siguiente lista de argumentos:
  #
  # cantidad:: Cantidad que debe desembolsarse el jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def recibir(cantidad)
    exito = false

    if !@encarcelado
      exito = modificar_saldo(cantidad)
    end

    exito
  end

  ##
  # Saca al jugador de la cárcel si se encuentra en ella y puede permitirse
  # pagar el precio de su libertad, desembolsándolo de dicha cantidad e
  # informando al Diario de ello.
  #
  # Devuelve booleanamente el éxito de la operación.

  def salir_carcel_pagando
    exito = false

    if @encarcelado && puede_salir_carcel_pagando
      Diario.instance.ocurre_evento("#{to_s} deja la prisión pagando")
      pagar(@@precio_libertad)
      exito = true
    end

    exito
  end

  def salir_carcel_tirando
  end

  ##
  # Consulta si el jugador posee una referencia a la Sorpresa de
  # +TipoSorpresa::SALVOCONDUCTO+.
  #
  # Devuelve booleanamente la condición de posesión de la misma.

  def tiene_salvoconducto
    @salvoconducto != nil
  end

  def to_s
  end

  ##
  # Elimina el TituloPropiedad del vector de propiedades del jugaodor si éste se
  # encuentra en libertad y si la propiedad especificada es correcta, en cuyo
  # caso se informa al Diario de la operación. Recibe la siguiente lista de
  # argumentos:
  #
  # propiedad:: Índice de la propiedad en el vector de propiedades del jugador.
  #
  # Devuelve booleanamente el éxito de la operación.

  def vender(propiedad)
    exito = false

    if !@encarcelado && propiedad_correcta(propiedad)
      if @propiedades[propiedad].vender
        Diario.instance.ocurre_evento("#{to_s} vende " \
                                      "#{@propiedades[propiedad].to_s}")
        @propiedades.delete_at(propiedad)
        exito = true
      end
    end

    exito
  end
end
end

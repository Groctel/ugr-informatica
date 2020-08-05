# encoding: utf-8
# frozen_string_literal: true

require_relative "jugador"

module Civitas

##
# Título que representa la propiedad asociada a una Casilla de
# +TipoCasilla::CALLE+. Contiene toda la información sobre el estado de la
# propiedad y las operaciones que permiten modificarla.

class TituloPropiedad
  ## Condición de hipotecamiento de la propiedad.
  attr_reader :hipotecado

  ## Nombre de la propiedad.
  attr_reader :nombre

  ## Casas construidas en la propiedad.
  attr_reader :num_casas

  ## Hoteles construidos en la propiedad.
  attr_reader :num_hoteles

  ## Precio que el Jugador debe pagar para comprar la propiedad.
  attr_reader :precio_compra

  ## Precio que el Jugador debe pagar para edificar en la propiedad.
  attr_reader :precio_edificar

  ## Jugador que posee la propiedad.
  attr_reader :propietario

  ##
  # Crea el TituloPropiedad inicializando sus atributos a los recibidos y
  # dejando por defecto la propiedad sin propietarios, casas, hoteles ni
  # hipoteca.

  def initialize(nombre, alquiler_base, factor_revalorizacion, hipoteca_base, \
                 precio_compra, precio_edificar)
    @@factor_intereses_hipoteca = 1.1.freeze

    @alquiler_base         = alquiler_base
    @factor_revalorizacion = factor_revalorizacion
    @hipoteca_base         = hipoteca_base
    @hipotecado            = false
    @nombre                = nombre
    @num_casas             = 0
    @num_hoteles           = 0
    @precio_compra         = precio_compra
    @precio_edificar       = precio_edificar
    @propietario           = nil
  end

  private

  ##
  # Comprueba si el Jugador especificado es el propeitario del título. Recibe
  # la siguiente lista de argumentos:
  #
  # jugador:: Jugador que a cotejar con el propietario del título.
  #
  # Devuelve booleanamente si el jugador especificado es el propietario.

  def es_propietario(jugador)
    @propietario = jugador
  end

  ##
  # Calcula la cantidad que recibe el propietario al caer otro Jugador en su
  # propiedad en base al número de casas y hoteles. Si éste está en la cárcel o
  # la propiedad está hipotecada, dicha cantidad es nula.
  #
  # Devuelve el precio de alquiler de la propiedad.

  def precio_alquiler
    propietario_encarcelado || @hipotecado ? \
    0 : @alquiler_base * (1 + @num_casas*0.5 + @num_hoteles*0.5)
  end

  ##
  # Calcula la cantidad que recibe el jugador por devolver la propiedad a la
  # banca en función del número de edificios construidos en ella y la
  # revalorización de los mismos.
  #
  # Devuelve el precio de venta de la propiedad.

  def precio_venta
    @precio_compra + @precio_edificar * total_edificios \
                                      * @factor_revalorizacion
  end

  ##
  # Comprueba si el propietario del título se encuentra actualmente en la
  # cárcel.
  #
  # Devuelve booleanamente la condición de encarcelación del mismo.

  def propietario_encarcelado
    @propietario.encarcelado
  end

  public

  ##
  # Actualiza el propietario del título al jugador determinado. Recibe la
  # siguiente lista de argumentos:
  #
  # jugador:: Jugador que pasa a ser el nuevo propietario.

  def actualiza_propietario(jugador)
    @propietario = jugador
  end

  # def cancelar_hipoteca(jugador)
  # end

  # def comprar(jugador)
  # end

  # def construir_casa(jugador)
  # end

  # def construir_hotel(jugador)
  # end

  ##
  # Decrementa la cantidad de casas que posee la propiedad en la determinada si
  # el jugador especificado es el propietario de ésta y si tiene suficientes
  # casas para derruir. Recibe la siguiente lista de argumentos:
  #
  # casas:: Número de casas a derruir.
  # jugador:: Jugador propietario del título.
  #
  # Devuelve booleanamente el éxito de esta operación.

  def derruir_casas(casas, jugador)
    exito = false

    if es_propietario(jugador) && @num_casas >= casas
      @num_casas -= casas
      exito       = true
    end

    exito
  end

  ##
  # Calcula la cantidad que debe desembolsar un jugador para cancelar la
  # hipoteca de la propiedad a partir de la hipoteca base y su factor de
  # intereses.
  #
  # Devuelve el precio de cancelación de la hipoteca de la propiedad.

  def importe_cancelar_hipoteca
    @hipoteca_base * @@factor_intereses_hipoteca
  end

  # def hipotecar(jugador)
  # end

  ##
  # Comprueba si el título está asociado a un Jugador, pero no revela su
  # identidad.
  #
  # Devuelve booleanamente si el título tiene un propietario asociado.

  def tiene_propietario
    @propietario != nil
  end

  ##
  # Proporciona la forma de imprimir el título en la salida estándar.
  #
  # Devuelve el nombre de la misma junto con su propietario y número de casas y
  # hoteles.

  def to_s
    "#{@nombre} (#{@propietario}) [#{@num_casas}/#{@num_hoteles}]"
  end

  ##
  # Calcula el total de edificaciones realizadas sobre la propiedad.
  #
  # Devuelve la suma de casas y hoteles.

  def total_edificios
    @num_casas + @num_hoteles
  end

  ##
  # Si el jugador que cae en la casilla asociada con el título no es el
  # propietario de éste y tiene propietario, se realiza un intercambio del
  # valor de alquilar la propiedad durante un turno. Recibe la siguiente lista
  # de argumentos:
  #
  # jugador:: Jugador que debe pagar el alquiler.

  def tramitar_alquiler(jugador)
    if !es_propietario(jugador) && tiene_propietario
      jugador.pagar_alquiler(precio_alquiler)
      @propietario.recibir(precio_alquiler)
    end
  end

  ##
  # Si el jugador especificado es el propietario del título, se le embolsa el
  # precio de venta de la propiedad y se le desvincula de ésta, eliminando las
  # edificaciones de la misma.
  #
  # jugador:: Jugador que vende la propiedad.
  #
  # Devuelve booleanamente el éxito de esta operación.

  def vender(jugador)
    exito = false

    if es_propietario(jugador) && !@hipotecado
      jugador.recibe(precio_venta)
      @propietario = nil
      @num_casas   = 0
      @num_hoteles = 0
      exito        = true
    end

    exito
  end
end
end

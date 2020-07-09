# encoding: utf-8
# frozen_string_literal: true

require_relative "sorpresa"

module Civitas

##
# Modelo del mazo que contiene las cartas que obtienen y afectan a los jugadores
# a lo largo de la partida.

class MazoSorpresas
  ##
  # Crea el mazo llamando al método privado +init+ e inicializando su opción de
  # depuración a la especificada o +false+ por defecto. Recibe la siguiente
  # lista de argumentos:
  #
  # debug=false:: Indicador de la opción de depuración.

  def initialize debug=false
    self.init

    @debug             = debug
    @ultima_sorpresa   = nil
  end

  private

  ##
  # Inicializa el mazo a dos vectores vacíos para las cartas especiales y las
  # sorpresas almacenadas, estando éste último sin barajar y sin cartas usadas.

  def init
    @barajado          = false
    @cartas_especiales = []
    @sorpresas         = []
    @usadas            = 0
  end

  public

  ##
  # Introduce una sorpresa al final del mazo si éste aún no ha sido barajado.
  # Recibe la siguiente lista de argumentos:
  #
  # sorpresa:: Sorpresa a introducir en el mazo.

  def al_mazo sorpresa
    if !@barajado
      @sorpresas << sorpresa
    end
  end

  ##
  # Elimina la carta especial especificada del contenedor de cartas especiales
  # y la devuelve al contenedor principal del mazo, dejando constancia en el
  # Diario en caso de éxito. Recibe la siguiente lista
  # de argumentos:
  #
  # sorpresa:: Sorpresa a habilitar.

  def habilitar_carta_especial sorpresa
    carta = @cartas_especiales.find_index sorpresa

    if carta != nil
      Diario.instance.ocurre_evento "Habilitada " \
                                    "\"#{@cartas_especiales[carta]}\""

      @sorpresas << @cartas_especiales[carta]
      @cartas_especiales.delete_at carta
    end
  end

  ##
  # Elimina la carta especial especificada del contenedor principal del mazo y
  # la devuelve al contenedor de cartas especiales, dejando constancia en el
  # Diario en caso de éxito. Recibe la siguiente lista
  # de argumentos:
  #
  # sorpresa:: Sorpresa a inhabilitar.

  def inhabilitar_carta_especial sorpresa
    carta = @sorpresas.find_index sorpresa

    if carta != nil
      Diario.instance.ocurre_evento "Inhabilitada \"#{@sorpresas[carta]}\""

      @cartas_especiales << @sorpresas[carta]
      @sorpresas.delete_at carta
    end
  end

  ##
  # Baraja el mazo si aún no se ha barajado o si se han usado todas las cartas
  # confirmando que la opción depuración está desactivada en cualquier caso y
  # envía la última carta del mazo al final del mismo, incrementando en una
  # unidad el número de cartas usadas.
  #
  # Devuelve el objeto de la Sorpresa que el jugador recoge del mazo.

  def siguiente
    if (!@barajado || @usadas == @sorpresas.length) && !@debug
      @sorpresas.shuffle!

      @usadas   = 0
      @barajado = true
    end

    @usadas          += 1
    @ultima_sorpresa  = @sorpresas.first
    @sorpresas.rotate!

    return @ultima_sorpresa
  end
end
end

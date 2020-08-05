# encoding: utf-8
# frozen_string_literal: true

require 'singleton'
require_relative 'diario'

module Civitas

##
# Generador de números pseudoaleatorios adaptado a las limitaciones de un dado
# físico. Por defecto se considera que éste tiene seis caras (d6), pero se
# puede lanzar con un número distinto para tiradas en situaciones específicas de
# la partida.

class Dado
  include Singleton

  ## Valor producido por la última tirada del dado.
  attr_reader :ultimo_resultado

  ##
  # Crea el objeto Dado con el modo de depuración desactivado e incializa la
  # semilla del PRNG.

  def initialize
    @@SALIDA_CARCEL = 5.freeze

    @debug            = false
    @ultimo_resultado = nil

    Random.srand
  end

  ##
  # Lanza un dado con tantas caras como el número de jugadores disponible para
  # elegir uno de ellos para comenzar la partida. Recibe la siguiente lista de
  # argumentos:
  #
  # num_jugadores:: Número de jugadores en la partida.
  #
  # Devuelve el índice del jugador que empieza la partida.

  def quien_empieza(num_jugadores)
    tirar(num_jugadores) - 1
  end

  ##
  # Si el dado no se encuentra en modo de depuración, en cuyo caso siempre se
  # sale de la cárcel, realiza una tirada de 1d6 para para intentar salir de la
  # cárcel.
  #
  # Devuelve la condición booleana de salida de la cárcel.

  def salgo_de_la_carcel
    @debug ? true : tirar >= SALIDA_CARCEL
  end

  ##
  # Modifica el estado del modo de depuración del dado y deja constancia de ello
  # en el Diario.

  def set_debug(debug)
    Diario.instance.ocurre_evento("Debug del dado modificado de #{@debug} a " \
                                  "#{debug}")
    @debug = debug
  end

  ##
  # Realiza una tirada de un número determinado de caras, 6 por defecto, y
  # almacena el valor en +:ultimo_resultado+.
  #
  # Devuelve el valor de la tirada.

  def tirar(caras=6)
    @ultimo_resultado = 1

    if !@debug
      @ultimo_resultado = Random.rand(caras) + 1
    end

    @ultimo_resultado
  end
end
end

# encoding: utf-8
# frozen_string_literal: true

require 'singleton'

module Civitas

##
# Gestor del registro y muestra de los eventos ocurridos a lo largo de la
# partida. Los eventos pasan por el contenedor subyacente en forma de cola
# (FIFO).

class Diario
  include Singleton

  ##
  # Inicializa el diario a un vector de eventos vacía.

  def initialize
    @eventos = []
  end

  ##
  # Añade un evento al final de la lsita de eventos. Recibe la siguiente lista
  # de argumentos:
  #
  # evento:: Cadena de caracteres a añadir como evento a la lista.

  def ocurre_evento(evento)
    @eventos << evento
  end

  ##
  # Consultor de la existnecia de eventos pendientes de salida en el diario.
  #
  # Devuelve booleanamente si existen eventos en el contenedor subyacente.

  def eventos_pendientes
    @eventos.length > 0
  end

  ##
  # Lee el evento más antiguo almacenado en el diario y lo elimina.
  #
  # Devuelve dicho evento.

  def leer_evento
    @eventos.shift
  end
end
end

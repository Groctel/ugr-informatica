# encoding: utf-8
# frozen_string_literal: true

module Civitas

##
# Modelo de las casillas por las que se mueve el jugador a lo largo del tablero.
# Por ahora la casilla contiene únicamente una plantilla de uso básico que
# almacena su nombre y permite su lectura.

class Casilla
  ## Cadena que describe la instancia del objeto.
  attr_reader :nombre

  ##
  # Inicializa la casilla con un nombre descriptivo. Recibe la siguiente lista
  # de argumentos:
  #
  # nombre:: Cadena que describe la instancia del objeto.

  def initialize nombre
    @nombre = nombre
  end
end
end

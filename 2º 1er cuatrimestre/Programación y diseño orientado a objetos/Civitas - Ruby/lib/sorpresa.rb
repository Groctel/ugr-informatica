# encoding: utf-8
# frozen_string_literal: true

module Civitas

##
# Modelo de las sorpresas que obtienen los jugadores a lo largo de la partida.
# Por ahora la sorpresa contiene únicamente una plantilla de uso básico que
# almacena su nombre y permite su lectura.

class Sorpresa
  ## Cadena que describe la instancia del objeto.
  attr_reader :nombre

  ##
  # Inicializa la sorpresa con un nombre descriptivo. Recibe la siguiente lista
  # de argumentos:
  #
  # nombre:: Cadena que describe la instancia del objeto.

  def initialize nombre
    @nombre = nombre
  end
end
end

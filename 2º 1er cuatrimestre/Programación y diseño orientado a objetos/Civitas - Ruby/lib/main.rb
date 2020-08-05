# encoding: utf-8
# frozen_string_literal: true

# require_relative "tests/test_p1"
require_relative "civitas_juego"
require_relative "mazo_sorpresas"

##
# Módulo principal que ejecuta el juego y dentro de cual se encuentran todos los
# objetos del mismo.

module Civitas
  @juego = CivitasJuego.new ["Pedro", "Pablo", "Poncio"]
  # test_p1 = TestP1.new
  # test_p1.test
end

# encoding: utf-8
# frozen_string_literal: true

require 'singleton'
require_relative "../casilla"
require_relative "../dado"
require_relative "../diario"
require_relative "../enum/estados_juego"
require_relative "../enum/figuras"
require_relative "../enum/operaciones_juego"
require_relative "../enum/tipo_casilla"
require_relative "../enum/tipo_sorpresa"
require_relative "../mazo_sorpresas"
require_relative "../sorpresa"
require_relative "../tablero"

module Civitas
##
# Test diseñado para probar los elementos implementados en la Práctica 1.

class TestP1
  ##
  # Gestiona la ejecución y salida de los diferentes tests que se realizan sobre
  # el programa.

  def test
    puts "#{Figuras::PARTE}COMENZANDO TEST P1"

    puts "#{Figuras::SECCION}Test1: " \
         "Distribución equitativa en Dado::quien_empieza"
    test_quien_empieza

    puts "#{Figuras::SECCION}Test2: " \
         "Resultados de Dado::tirar en función de :debug"
    test_tirar

    puts "#{Figuras::SECCION}Test3: " \
         "Muestra de los enumerados disponibles"
    test_enum

    puts "#{Figuras::SECCION}Test4: " \
         "Funcionamiento del mazo de sorpresas"
    test_mazo_sorpresas

    puts "#{Figuras::SECCION}Test5: " \
         "Funcionamiento del tablero"
    test_tablero
  end

  private

  ## Muestra los componentes de todos los enumerados implementados.

  def test_enum
    puts "#{Figuras::ELEMENTO}EstadosJuego: " \
         "#{EstadosJuego::DESPUES_AVANZAR} " \
         "#{EstadosJuego::DESPUES_CARCEL} " \
         "#{EstadosJuego::DESPUES_COMPRAR} " \
         "#{EstadosJuego::DESPUES_GESTIONAR} " \
         "#{EstadosJuego::INICIO_TURNO}"

    puts "#{Figuras::ELEMENTO}OperacionesJuego: " \
         "#{OperacionesJuego::AVANZAR} " \
         "#{OperacionesJuego::COMPRAR} " \
         "#{OperacionesJuego::GESTIONAR} " \
         "#{OperacionesJuego::PASAR_TURNO} " \
         "#{OperacionesJuego::SALVOCONDUCTO}"

    puts "#{Figuras::ELEMENTO}TipoCasilla: " \
         "#{TipoCasilla::CALLE} " \
         "#{TipoCasilla::DESCANSO} " \
         "#{TipoCasilla::IMPUESTO} " \
         "#{TipoCasilla::JUEZ} " \
         "#{TipoCasilla::SORPRESA}"

    puts "#{Figuras::ELEMENTO}TipoSorpresa: " \
         "#{TipoSorpresa::IR_CARCEL} " \
         "#{TipoSorpresa::IR_CASILLA} " \
         "#{TipoSorpresa::PAGAR_COBRAR} " \
         "#{TipoSorpresa::POR_EDIFICIO} " \
         "#{TipoSorpresa::POR_JUGADOR} " \
         "#{TipoSorpresa::SALIR_CARCEL}"
  end

  ##
  # Añade cinco cartas a un MazoSorpresas, de las cuales una es especial. Juega
  # las cinco cartas y luego inhabilita y habilita la carta especial,
  # mostrándolo debidamente a través del Diario.

  def test_mazo_sorpresas
    @mazo = MazoSorpresas.new

    4.times do |i|
      sorpresa = Sorpresa.new("Sorpresa #{i}")
      @mazo.al_mazo(sorpresa)
    end

    especial = Sorpresa.new("Carta especial")
    @mazo.al_mazo(especial)

    5.times do
      puts "#{Figuras::ELEMENTO}#{@mazo.siguiente.inspect}"
    end

    @mazo.inhabilitar_carta_especial(especial)
    puts "#{Figuras::ELEMENTO}#{Diario.instance.leer_evento}"

    @mazo.habilitar_carta_especial(especial)
    puts "#{Figuras::ELEMENTO}#{Diario.instance.leer_evento}"
  end

  ##
  # Llama cien mil veces al método quien_empieza del Dado y almacena el
  # resultado en un vector de cuatro jugadores disponibles. Muestra los valores
  # obtenidos para cada jugador, que deben ser similares.

  def test_quien_empieza
    @quien_empieza = []

    4.times do
      @quien_empieza << 0
    end

    100000.times do
      @quien_empieza[Dado.instance.quien_empieza(4)] += 1
    end

    print "#{Figuras::ELEMENTO}Jugador 0 -> #{@quien_empieza[0]}\n" \
          "#{Figuras::ELEMENTO}Jugador 1 -> #{@quien_empieza[1]}\n" \
          "#{Figuras::ELEMENTO}Jugador 2 -> #{@quien_empieza[2]}\n" \
          "#{Figuras::ELEMENTO}Jugador 3 -> #{@quien_empieza[3]}\n"
  end

  ##
  # Crea un tablero con cinco casillas, siendo la tercera la cárcel y la última
  # el juez, que se intenta añadir varias veces sin éxito. Se realizan varias
  # tiradas y se muestra la progresión.

  def test_tablero
    @tablero  = Tablero.new 3
    posicion  = 0

    3.times do |i|
      casilla = Casilla.new("Casilla #{i}")
      @tablero.aniade_casilla(casilla)
    end

    10.times do
      @tablero.aniade_juez
    end

    print "#{Figuras::ELEMENTO}Avance por el tablero:"

    50.times do
      posicion = @tablero.nueva_posicion(posicion, Dado.instance.tirar)
      print " #{posicion}"
    end

    print "\n"
  end

  ##
  # Con el modo de depuración activado y desactivado, tira 20 veces el dado
  # para realizar tiradas normales y otras 20 para comprobar si sale de la
  # cárcel, mostrando lo ocurrido por la salida estándar.

  def test_tirar
    Dado.instance.set_debug(true)
    puts "#{Figuras::ELEMENTO}#{Diario.instance.leer_evento}"

    print "#{Figuras::ELEMENTO}:debug = true -> tirar:"
    20.times do
      print " #{Dado.instance.tirar}"
    end

    print "\n#{Figuras::ELEMENTO}:debug = true -> salgo_de_la_carcel:"
    20.times do
      print " #{Dado.instance.salgo_de_la_carcel}"
    end

    print "\n"

    Dado.instance.set_debug(false)
    puts "#{Figuras::ELEMENTO}#{Diario.instance.leer_evento}"

    print "#{Figuras::ELEMENTO}:debug = false -> tirar:"
    20.times do
      print " #{Dado.instance.tirar}"
    end

    print "\n#{Figuras::ELEMENTO}:debug = false -> salgo_de_la_carcel:"
    20.times do
      print " #{Dado.instance.salgo_de_la_carcel}"
    end

    print "\n"

    puts "#{Figuras::ELEMENTO}Último resultado del dado: " \
         "#{Dado.instance.ultimo_resultado}"
  end
end
end

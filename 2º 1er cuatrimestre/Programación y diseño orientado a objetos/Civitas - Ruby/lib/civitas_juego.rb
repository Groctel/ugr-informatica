# encoding: utf-8
# frozen_string_literal: true

require_relative "casilla"
require_relative "dado"
require_relative "gestor_estados"
require_relative "jugador"
require_relative "mazo_sorpresas"
require_relative "titulo_propiedad"
require_relative "tablero"

module Civitas

##
# Modelo principal del juego encargado de realizar las tareas de gestión de
# inicio del mismo, el avance al final de cada turno y la finalización de la
# partida.

class CivitasJuego
  ##
  # Inicializa los objetos Jugador, el GestorEstados, el Mazo y el Tablero.
  # Recibe la siguiente lista de argumentos:
  #
  # nombres:: Vector de nombres de los jugadores a introducir en la partida.

  def initialize(nombres)
    @jugadores = []

    nombres.each do |nombre|
      jugador = Jugador.new(nombre)
      @jugadores << jugador
    end

    @gestor         = GestorEstados.new
    @estado         = @gestor.estado_inicial
    @jugador_actual = Dado.instance.quien_empieza(@jugadores.length)
    @mazo           = MazoSorpresas.new

    self.init_tablero(@mazo)
  end

  private

  def avanza_jugador
  end

  def init_mazo(tablero)
  end

  ##
  # Inicializa el tablero creando los TituloPropiedad correspondientes de cada
  # calle y añadiendo todas las casillas en orden. Recibe la siguiente lista de
  # argumentos:
  #
  # mazo:: MazoSorpresas de las casillas de +TipoCasilla::SORPRESA+.

  def init_tablero(mazo)
    @tablero = Tablero.new(6)

    t01 = TituloPropiedad.new("Chabolas junto al río",  20,  1,   40,  60,  30)
    t02 = TituloPropiedad.new("Cultivos en barbecho",   50,  1,   60,  100, 50)
    t03 = TituloPropiedad.new("Ruinas abandonadas",     40,  1.1, 80,  120, 60)
    t04 = TituloPropiedad.new("Posada entre las cimas", 40,  1.1, 80,  140, 70)
    t05 = TituloPropiedad.new("Cuevas en el barranco",  50,  1.2, 100, 160, 80)
    t06 = TituloPropiedad.new("Poblado a la sombra",    60,  1.2, 130, 200, 100)
    t07 = TituloPropiedad.new("Posada de las colinas",  70,  1.3, 140, 220, 110)
    t08 = TituloPropiedad.new("Monolito florecido",     80,  1.3, 160, 240, 120)
    t09 = TituloPropiedad.new("Granja de trigo",        90,  1.4, 180, 280, 140)
    t10 = TituloPropiedad.new("Colosos de la frontera", 100, 1.4, 200, 300, 150)
    t11 = TituloPropiedad.new("Carretera del valle",    100, 1.5, 200, 320, 160)
    t12 = TituloPropiedad.new("Magna Civitas",          130, 1.5, 260, 400, 200)

    @tablero << (Casilla.new_descanso "Puertas del poblado")
    @tablero << (Casilla.new_calle(t01))
    @tablero << (Casilla.new_calle(t02))
    @tablero << (Casilla.new_impuesto "¡Asalto en el camino!", 100)
    @tablero << (Casilla.new_calle(t03))

    @tablero << (Casilla.new_calle(t04))
    @tablero << (Casilla.new_calle(t05))
    @tablero << (Casilla.new_sorpresa "Mensaje a caballo", mazo)
    @tablero << (Casilla.new_calle(t06))

    @tablero << (Casilla.new_descanso "Establos del desfiladero")
    @tablero << (Casilla.new_calle(t07))
    @tablero << (Casilla.new_calle(t08))
    @tablero << (Casilla.new_sorpresa "Mercader ambulante", mazo)
    @tablero << (Casilla.new_calle(t09))

    @tablero.aniade_juez
    @tablero << (Casilla.new_calle(t10))
    @tablero << (Casilla.new_calle(t11))
    @tablero << (Casilla.new_sorpresa "Control en la muralla", mazo)
    @tablero << (Casilla.new_calle(t12))
  end

  def pasar_turno
  end

  def ranking
  end

  def total_vueltas(jugador_actual)
  end
end
end

require_relative 'diario'
require_relative 'enum/operaciones_juego'
require_relative "enum/estados_juego"

module Civitas

class GestorEstados
  def estado_inicial
   EstadosJuego::INICIO_TURNO
  end

  def operaciones_permitidas(jugador, estado)
    operacion = nil

    case estado
    when EstadosJuego::INICIO_TURNO
      operacion = jugador.encarcelado ? OperacionesJuego::SALIR_CARCEL \
                                      : OperacionesJuego::AVANZAR
    when EstadosJuego::DESPUES_CARCEL
      operacion = OperacionesJuego::PASAR_TURNO
    when EstadosJuego::DESPUES_AVANZAR
      if jugador.encarcelado
        operacion = OperacionesJuego::PASAR_TURNO
      elsif jugador.puede_comprar
        operacion = OperacionesJuego::COMPRAR
      elsif jugador.gestiones_pendientes
        operacion = OperacionesJuego::GESTIONAR
      else
        operacion = OperacionesJuego::PASAR_TURNO
      end
    when EstadosJuego::DESPUES_COMPRAR
      operacion = jugador.gestiones_pendientes ? OperacionesJuego::GESTIONAR \
                                               : OperacionesJuego::PASAR_TURNO
    when EstadosJuego::DESPUES_GESTIONAR
      operacion = OperacionesJuego::PASAR_TURNO
    end

    operacion
  end



  def siguiente_estado(jugador, estado, operacion)
    siguiente = nil

    case estado
    when EstadosJuego::INICIO_TURNO
      if operacion == OperacionesJuego::SALIR_CARCEL
        siguiente = EstadosJuego::DESPUES_CARCEL
      elsif operacion == OperacionesJuego::AVANZAR
        siguiente = EstadosJuego::DESPUES_AVANZAR
      end
    when EstadosJuego::DESPUES_CARCEL
      if operacion == OperacionesJuego::PASAR_TURNO
        siguiente = EstadosJuego::INICIO_TURNO
      end
    when EstadosJuego::DESPUES_AVANZAR
      case operacion
      when OperacionesJuego::PASAR_TURNO
        siguiente = EstadosJuego::INICIO_TURNO
      when
        OperacionesJuego::COMPRAR
        siguiente = EstadosJuego::DESPUES_COMPRAR
      when OperacionesJuego::GESTIONAR
        siguiente = EstadosJuego::DESPUES_GESTIONAR
      end
    when EstadosJuego::DESPUES_COMPRAR
      #if (jugador.gestiones_pendientes)
      if operacion == OperacionesJuego::GESTIONAR
        siguiente = EstadosJuego::DESPUES_GESTIONAR
      #  end
      elsif operacion == OperacionesJuego::PASAR_TURNO
        siguiente = EstadosJuego::INICIO_TURNO
      end
    when EstadosJuego::DESPUES_GESTIONAR
      if operacion == OperacionesJuego::PASAR_TURNO
        siguiente = EstadosJuego::INICIO_TURNO
      end
    end

    Diario.instance.ocurre_evento("De #{estado.to_s} con #{operacion.to_s} " \
                                  "sale: #{siguiente.to_s}")
    siguiente
  end
end
end

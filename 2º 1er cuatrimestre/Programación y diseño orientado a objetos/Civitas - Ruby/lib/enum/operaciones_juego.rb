# encoding: utf-8
# frozen_string_literal: true

module Civitas

## Operaciones que el jugador puede realizar en su turno.

module OperacionesJuego
  ## Lanzar el Dado para avanzar casillas en el tablero.
  AVANZAR      = :avanzar

  ## Comprar la propiedad asociada a una casilla.
  COMPRAR      = :comprar

  ## Gestionar la construcción en o venta de las propiedades disponibles.
  GESTIONAR    = :gestionar

  ## Finalizar las actividades y dejar paso al siguiente jugador.
  PASAR_TURNO  = :pasar_turno

  ## Intentar salir de la cárcel tirando el dado o pagando.
  SALIR_CARCEL = :salir_carcel
end
end

# encoding: utf-8
# frozen_string_literal: true

module Civitas

## Tipos de sorpresa que puede adoptar un objeto de la clase sorpresa.

module TipoSorpresa
  ## Envía al jugador objetivo a la cárcel.
  IR_CARCEL     = :ir_carcel

  ## Envía al jugador objetivo a una casilla.
  IR_CASILLA    = :ir_casilla

  ## Añade o sustrae dinero al jugador objetivo.
  PAGAR_COBRAR  = :pagar_cobrar

  ## El jugador objetivo paga en función de su rendimiento inmobiliario.
  POR_EDIFICIO  = :por_edificio

  ## El resto de jugadores a pagan una cantidad al jugador objetivo.
  POR_JUGADOR   = :por_jugador

  ## El jugador objetivo sale de la cárcel automáticamente y pierde la Sorpresa.
  SALVOCONDUCTO = :salvoconducto
end
end

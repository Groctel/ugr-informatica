# encoding: utf-8
# frozen_string_literal: true

module Civitas

## Tipos de casilla que puede adoptar un objeto de la clase Casilla.

module TipoCasilla
  ## Casilla con una propiedad asociada adquirible por el jugador.
  CALLE    = :calle

  ## Casilla en la que no se activan acciones de forma automática.
  DESCANSO = :descanso

  ## Casilla que le sustrae una cantidad al jugador a favor de la banca.
  IMPUESTO = :impuesto

  ## Casilla que envía al jugador a la cárcel.
  JUEZ     = :juez

  ## Casilla en la que el jugador recibe la siguiente Sorpresa del mazo.
  SORPRESA = :sorpresa
end
end

# encoding: utf-8
# frozen_string_literal: true

module Civitas

## Indentificadores de las fases de cada turno del juego.

module EstadosJuego
  ## Fase inicial del turno donde se avanza o intenta salir de la cárcel.
  INICIO_TURNO      = :inicio_turno

  ## Activación de las acciones definidas en la casilla a la que se ha avanzado.
  DESPUES_AVANZAR   = :despues_avanzar

  ## Avanzar tras salir de la cárcel.
  DESPUES_CARCEL    = :despues_carcel

  ## Acciones de gestión realizadas después de comprar una propiedad.
  DESPUES_COMPRAR   = :despues_comprar

  ## Acciones de realizadas al final del turno.
  DESPUES_GESTIONAR = :despues_gestionar
end
end

# encoding: utf-8
# frozen_string_literal: true

require_relative "../kernel/string"

module Civitas

## Cadenas de caracteres predefinidas para facilitar la escritura.

module Figuras
  ## Introductor general de los tests y las salidas de información general.
  PARTE    = "==> ".bold.green

  ##
  # Introductor de las secciones que componen los tests y las salidas de
  # información general
  SECCION  = "  -> ".bold.blue

  ##
  # Introductor de los elementos que componen las secciones de los tests y las
  # salidas de información general.
  ELEMENTO = "  :: ".bold.magenta.blink
end
end

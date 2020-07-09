# encoding: utf-8
# frozen_string_literal: true

##
# Modificaciones realizadas sobre la clase String para estilizar la muestra de
# datos por la salida estándar.

class String
  ## Transforma la cadena sobre la que se aplica a color negro

  def black
    return "\e[30m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color rojo

  def red
    return "\e[31m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color verde

  def green
    return "\e[32m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color marrón

  def brown
    return "\e[33m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color azul

  def blue
    return "\e[34m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color magenta

  def magenta
    return "\e[35m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color cian

  def cyan
    return"\e[36m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a color gris

  def gray
    return "\e[37m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color negro

  def bg_black
    return "\e[40m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color rojo

  def bg_red
    return "\e[41m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color verde

  def bg_green
    return "\e[42m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color marrón

  def bg_brown
    return "\e[43m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color azul

  def bg_blue
    return "\e[44m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color magenta

  def bg_magenta
    return "\e[45m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color cian

  def bg_cyan
    return "\e[46m#{self}\e[0m"
  end

  ## Transforma el fondo de la cadena sobre la que se aplica a color gris

  def bg_gray
    return "\e[47m#{self}\e[0m"
  end

  ## Transforma la cadena sobre la que se aplica a texto en negrita

  def bold
    return "\e[1m#{self}\e[22m"
  end

  ## Transforma la cadena sobre la que se aplica a texto en cursiva

  def italic
    return "\e[3m#{self}\e[23m"
  end

  ## Transforma la cadena sobre la que se aplica a texto subrayado

  def underline
    return "\e[4m#{self}\e[24m"
  end

  ## Transforma la cadena sobre la que se aplica a texto pulsante

  def blink
    return "\e[5m#{self}\e[25m"
  end

  ## Transforma la cadena sobre la que se aplica a colores inversos

  def reverse_color
    return "\e[7m#{self}\e[27m"
  end
end

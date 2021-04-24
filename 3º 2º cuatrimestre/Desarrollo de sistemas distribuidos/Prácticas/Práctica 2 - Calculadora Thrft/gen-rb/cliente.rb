# frozen-string-literal: true

$LOAD_PATH.push('gen-rb')
$LOAD_PATH.unshift '../../lib/rb/lib'

require 'thrift'
require_relative './calculadora'

## Operaciones a realizar y sus simbolos
module Operaciones
  SUMA     = '+'
  RESTA    = '-'
  PRODUCTO = '*'
  DIVISION = '/'
end

def operacion_escalar(operando1, operando2, operacion, cliente)
  e1 = operando1.to_i
  e2 = operando2.to_i

  case operacion
  when Operaciones::SUMA
    puts(cliente.suma_escalar(e1, e2).to_s)
  when Operaciones::RESTA
    puts(cliente.resta_escalar(e1, e2).to_s)
  when Operaciones::PRODUCTO
    puts(cliente.producto_escalar(e1, e2).to_s)
  when Operaciones::DIVISION
    puts(cliente.division_escalar(e1, e2).to_s)
  end
end

def extraer_vector(vector_str)
  vector_str.tr('[]()', '').split(',').map(&:to_i)
end

def operacion_vectorial(operando1, operando2, operacion, cliente)
  v1 = extraer_vector(operando1)
  v2 = extraer_vector(operando2)

  case operacion
  when Operaciones::SUMA
    puts(cliente.suma_vectorial(v1, v2).to_s)
  when Operaciones::RESTA
    puts(cliente.resta_vectorial(v1, v2).to_s)
  when Operaciones::PRODUCTO
    puts(cliente.producto_vectorial(v1, v2).to_s)
  end
end

def extraer_matriz(matriz_str)
  matriz = matriz_str.split(')(')
  matriz.length.times do |i|
    matriz[i] = extraer_vector(matriz[i])
  end
  matriz
end

def operacion_matricial(operando1, operando2, operacion, cliente)
  m1 = extraer_matriz(operando1)
  m2 = extraer_matriz(operando2)

  case operacion
  when Operaciones::SUMA
    puts(cliente.suma_matricial(m1, m2).to_s)
  when Operaciones::RESTA
    puts(cliente.resta_matricial(m1, m2).to_s)
  when Operaciones::PRODUCTO
    puts(cliente.producto_matricial(m1, m2).to_s)
  end
end

begin
  transport = Thrift::BufferedTransport.new(Thrift::Socket.new('localhost', 9090))
  protocol  = Thrift::BinaryProtocol.new(transport)
  client    = Calculadora::Client.new(protocol)

  transport.open
  client.ping

  case ARGV[0][0]
  when '['
    operacion_matricial(ARGV[0], ARGV[2], ARGV[1], client)
  when '('
    operacion_vectorial(ARGV[0], ARGV[2], ARGV[1], client)
  else
    operacion_escalar(ARGV[0], ARGV[2], ARGV[1], client)
  end

  transport.close
rescue Thrift::Exception => e
  print 'Thrift::Exception: ', e.message, "\n"
end

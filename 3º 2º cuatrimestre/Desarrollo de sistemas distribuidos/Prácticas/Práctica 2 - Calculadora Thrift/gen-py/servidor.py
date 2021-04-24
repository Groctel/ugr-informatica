from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import logging
import numpy as np
logging.basicConfig(level=logging.DEBUG)


class CalculadoraHandler:
    """
    Realiza operaciones propias de una calculadora.
    """
    def __init__(self):
        self.log = {}

    @classmethod
    def ping(cls):
        """
        Alerta de que se ha hecho ping desde el cliente.
        """
        print("Pong!")

    @classmethod
    def suma_escalar(cls, sumando1, sumando2):
        """
        Parameters:
         - sumando1: Primer escalar a sumar
         - sumando2: Segundo escalar a sumar

        Devuelve la suma de dos números.
        """
        print(f"Sumando '{sumando1} + {sumando2}'...")
        return sumando1 + sumando2

    @classmethod
    def resta_escalar(cls, minuendo, sustraendo):
        """
        Parameters:
         - minuendo: Escalar a restar
         - sustraendo: Escalar con la que restar

        Devuelve la resta de dos números.
        """
        print(f"Restando '{minuendo} - {sustraendo}'...")
        return minuendo - sustraendo

    @classmethod
    def producto_escalar(cls, factor1, factor2):
        """
        Parameters:
         - factor1: Primer escalar a multiplicar
         - factor2: Segundo escalar a multiplicar

        Devuelve el producto de dos números.
        """
        print(f"Multiplicando '{factor1} * {factor2}'...")
        return factor1 * factor2

    @classmethod
    def division_escalar(cls, dividendo, divisor):
        """
        Parameters:
         - dividendo: Escalar a dividir
         - dividor: Escalar con el que dividir

        Devuelve el cociente de dos números.
        """
        print(f"Dividiendo '{dividendo} / {divisor}'...")
        return int(dividendo / divisor)

    @classmethod
    def suma_vectorial(cls, v_sumando1, v_sumando2):
        """
        Parameters:
         - v_sumando1: Primer vector a sumar
         - v_sumando2: Segundo vector a sumar

        Devuelve la suma de dos vectores.
        """
        print(f"Sumando '{str(v_sumando1)} + {str(v_sumando2)}")
        return np.array(v_sumando1) + np.array(v_sumando2)

    @classmethod
    def resta_vectorial(cls, v_minuendo, v_sustraendo):
        """
        Parameters:
         - v_minuendo: Vector a restar
         - v_sustraendo: Vector con la que restar

        Devuelve la resta de dos vectores.
        """
        print(f"Restando '{v_minuendo} - {v_sustraendo}'...")
        return np.array(v_minuendo) - np.array(v_sustraendo)

    @classmethod
    def producto_vectorial(cls, v_factor1, v_factor2):
        """
        Parameters:
         - v_factor1: Primer vector a multiplicar
         - v_factor2: Segundo vector a multiplicar

        Devuelve el producto de dos vectores.
        """
        print(f"Multiplicando '{v_factor1} * {v_factor2}'...")
        return np.array(v_factor1) * np.array(v_factor2)

    @classmethod
    def suma_matricial(cls, m_sumando1, m_sumando2):
        """
        Parameters:
         - m_sumando1: Primera matriz a sumar
         - m_sumando2: Segunda matriz a sumar

        Devuelve la suma de dos matrices.
        """
        print(f"Sumando '{str(m_sumando1)} + {str(m_sumando2)}'...")
        return np.array(np.matrix(m_sumando1) + np.matrix(m_sumando2),
                        dtype='int')

    @classmethod
    def resta_matricial(cls, m_minuendo, m_sustraendo):
        """
        Parameters:
         - m_minuendo: Matriz a restar
         - m_sustraendo: Matriz con la que restar

        Devuelve la resta de dos matrices.
        """
        print(f"Restando '{m_minuendo} - {m_sustraendo}'...")
        return np.array(np.matrix(m_minuendo) - np.matrix(m_sustraendo),
                        dtype='int')

    @classmethod
    def producto_matricial(cls, m_factor1, m_factor2):
        """
        Parameters:
         - m_factor1: Primera matriz a multiplicar
         - m_factor2: Segunda matriz a multiplicar

        Devuelve el producto de dos matrices.
        """
        print(f"Multiplicando '{m_factor1} * {m_factor2}'...")
        return np.array(np.matrix(m_factor1) * np.matrix(m_factor2),
                        dtype='int')


if __name__ == "__main__":
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host="127.0.0.1", port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print("Iniciando servidor...")
    server.serve()
    print("Fin de la ejecución.")

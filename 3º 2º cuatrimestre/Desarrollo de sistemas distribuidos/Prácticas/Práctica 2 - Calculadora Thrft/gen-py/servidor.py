import glob
import logging
import numpy as np
import sys

from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

logging.basicConfig(level=logging.DEBUG)

class CalculadoraHandler:
    def Ping(self):
        print("Pong!")

    def SumaEscalar(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        return operando1 + operando2

    def RestaEscalar(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        return operando1 - operando2

    def ProductoEscalar(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        return operando1 * operando2

    def DivisionEscalar(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        return operando1 / operando2

    def SumaVectorial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.array(operando1)
        vector2 = np.array(operando2)
        return vector1 + vector2

    def RestaVectorial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.array(operando1)
        vector2 = np.array(operando2)
        return vector1 - vector2

    def ProductoVectorial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.array(operando1)
        vector2 = np.array(operando2)
        return vector1 * vector2

    def SumaMatricial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.matrix(operando1)
        vector2 = np.matrix(operando2)
        return vector1 + vector2

    def RestaMatricial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.matrix(operando1)
        vector2 = np.matrix(operando2)
        return vector1 - vector2

    def ProductoMatricial(self, operando1, operando2):
        """
        Parameters:
         - operando1
         - operando2

        """
        vector1 = np.matrix(operando1)
        vector2 = np.matrix(operando2)
        return vector1 * vector2


if __name__ == '__main__':
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host='127.0.0.1', port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    print('Iniciando servidor ...')
    server.serve()
    print('Fin.')

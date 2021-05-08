package ejemplo3;

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class Contador extends UnicastRemoteObject implements IContador
{
	private static final long serialVersionUID = 637582643;
	private int suma;

	public Contador () throws RemoteException
	{ }

	public int Suma () throws RemoteException
	{
		return suma;
	}

	public void Sumar (int valor) throws RemoteException
	{
		suma = valor;
	}

	public int Incrementar () throws RemoteException {
		suma++;
		return Suma();
	}
}

package ejemplo3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IContador extends Remote
{
	int Suma () throws RemoteException;
	void Sumar (int valor) throws RemoteException;
	public int Incrementar () throws RemoteException;
}

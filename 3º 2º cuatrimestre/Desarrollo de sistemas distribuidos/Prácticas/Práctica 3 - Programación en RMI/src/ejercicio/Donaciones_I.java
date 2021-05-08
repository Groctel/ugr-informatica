package ejercicio;

import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Donaciones_I extends Remote
{
	public int TotalDonado (int cliente) throws RemoteException, NotBoundException;
	public int Registrar (int cliente) throws RemoteException, NotBoundException;
	public void Donar (int cliente, int cantidad) throws RemoteException;
}

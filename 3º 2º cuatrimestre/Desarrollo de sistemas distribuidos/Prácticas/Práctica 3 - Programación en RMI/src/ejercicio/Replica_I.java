package ejercicio;

import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Replica_I extends Remote
{
	public boolean Registrado (int cliente) throws RemoteException;
	public int SubtotalDonaciones () throws RemoteException;
	public int TotalDonado (int cliente) throws RemoteException, NotBoundException;
	public int TotalRegistrados () throws RemoteException;
	public void Donar (int cliente, int cantidad) throws RemoteException;
	public void Registrar (Cliente_I cliente) throws RemoteException, NotBoundException;
}

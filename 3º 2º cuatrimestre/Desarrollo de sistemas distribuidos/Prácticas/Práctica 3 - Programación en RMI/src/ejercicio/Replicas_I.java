package ejercicio;

import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Replicas_I extends Remote
{
	public boolean Registrado (int cliente) throws RemoteException;
	public int TotalDonado (int cliente) throws RemoteException, NotBoundException;
	public int Registrar (int cliente) throws RemoteException, NotBoundException;
	public int SubtotalDonaciones () throws RemoteException;
	public int TotalRegistrados () throws RemoteException;
	public void Donar (int cliente, int cantidad) throws RemoteException;
}

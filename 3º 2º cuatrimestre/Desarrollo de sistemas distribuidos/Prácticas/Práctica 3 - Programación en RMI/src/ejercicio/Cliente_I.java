package ejercicio;

import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

interface Cliente_I extends Remote
{
	public void asignarReplica (int replica) throws RemoteException;
	public String host () throws RemoteException;
	public int id () throws RemoteException;
	public int replica () throws RemoteException;
}

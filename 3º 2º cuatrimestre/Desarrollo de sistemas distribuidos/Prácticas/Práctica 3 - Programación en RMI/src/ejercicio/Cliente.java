package ejercicio;

import java.io.Serializable;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

class Cliente extends UnicastRemoteObject implements Cliente_I, Serializable
{
	private static final long serialVersionUID = 637894393;
	private String host_;
	private int id_;
	private int replica_ = -1;

	Cliente (String host, int id) throws RemoteException
	{
		host_ = host;
		id_   = id;
	}

	public void asignarReplica (int replica) throws RemoteException
	{
		replica_ = replica;
	}

	public String host () throws RemoteException
	{
		return host_;
	}

	public int id () throws RemoteException
	{
		return id_;
	}

	public int replica () throws RemoteException
	{
		return replica_;
	}
}


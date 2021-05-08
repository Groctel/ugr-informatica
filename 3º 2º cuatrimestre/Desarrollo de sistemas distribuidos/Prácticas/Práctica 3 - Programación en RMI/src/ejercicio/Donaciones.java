package ejercicio;

import java.rmi.*;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Donaciones extends UnicastRemoteObject implements Donaciones_I
{
	private static final long serialVersionUID = 637582643;
	Registry registry;
	Replicas replica;

	public Donaciones (String host, Replicas replica) throws RemoteException
	{
		this.replica = replica;
	}

	public int TotalDonado (int idCliente) throws RemoteException, NotBoundException
	{
		return replica.TotalDonado(idCliente);
	}

	public int Registrar (int idCliente) throws RemoteException, NotBoundException
	{
		return replica.Registrar(idCliente);
	}

	public void Donar (int cantidad, int idCliente) throws RemoteException
	{
		replica.Donar(cantidad, idCliente);
	}
}


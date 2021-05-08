package ejercicio;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.HashMap;

public class Replicas extends UnicastRemoteObject implements Replicas_I
{
	private static final long serialVersionUID = 637584321;

	private int id;
	private int subtotal = 0;
	private int total_replicas;

	private Registry registry;

	// id_cliente, total_donado
	private HashMap<Integer, Integer> registrados = new HashMap<Integer, Integer>();

	private boolean RegistradoYDonado (int cliente) throws RemoteException
	{
		return Registrado(cliente) && registrados.get(cliente) > 0;
	}

	private synchronized void IntroducirRegistro (int cliente)
	{
		this.registrados.put(cliente, 0);
	}

	public Replicas (String host, int id, int total_replicas) throws RemoteException
	{
		registry            = LocateRegistry.getRegistry(host, 1099);
		this.id             = id;
		this.total_replicas = total_replicas;
	}

	public int TotalDonado (int cliente) throws RemoteException, NotBoundException
	{
		int total = 0;

		if (RegistradoYDonado(cliente))
		{
			total = subtotal;

			for (int i = 0; i < this.total_replicas; i++)
				if (i != this.id)
					total += ((Replicas_I) registry.lookup("Replica" + i)).SubtotalDonaciones();
		}

		return total;
	}

	public int SubtotalDonaciones () throws RemoteException
	{
		return subtotal;
	}

	public int Registrar (int cliente) throws RemoteException, NotBoundException
	{
		int replica_min_registrados  = id;
		int min_total_registrados    = TotalRegistrados();
		boolean registrado           = false;
		Replicas_I replica_candidata = (Replicas_I) this;

		for (int i = 0; i < this.total_replicas; i++)
		{
			if (i != this.id)
			{
				replica_candidata = (Replicas_I) registry.lookup("Replica" + i);

				if (!registrado)
					registrado = replica_candidata.Registrado(cliente);

				int total_registrados = replica_candidata.TotalRegistrados();

				if (total_registrados < min_total_registrados)
				{
					replica_min_registrados = total_registrados;
					min_total_registrados   = total_registrados;
				}
			}
		}

		if (!registrado)
		{
			if (replica_min_registrados != cliente)
			{
				replica_candidata = (Replicas_I) registry.lookup("Replica" + replica_min_registrados);
				replica_candidata.Registrar(cliente);
			}
			else
			{
				System.out.println(
					"Registrando cliente " +
					cliente +
					" en Réplica " +
					this.id
				);
				IntroducirRegistro(cliente);
			}
		}

		return replica_min_registrados;
	}

	public boolean Registrado (int cliente) throws RemoteException
	{
		return registrados.containsKey(cliente);
	}

	public int TotalRegistrados () throws RemoteException
	{
		return registrados.size();
	}

	public synchronized void Donar (int cliente, int cantidad) throws RemoteException
	{
		registrados.put(cliente, cantidad);
		subtotal += cantidad;
	}
}


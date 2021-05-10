package ejercicio;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Collection;
import java.util.HashMap;

public class Replica extends UnicastRemoteObject implements Replica_I
{
	private static final long serialVersionUID = 637584321;
	private static int total_replicas;

	private int id;

	// id_cliente, total_donado
	private HashMap<Integer, Integer> registrados = new HashMap<Integer, Integer>();
	private Registry registry;

	private boolean RegistradoYDonado (int cliente) throws RemoteException
	{
		return Registrado(cliente) && registrados.get(cliente) > 0;
	}

	public boolean Registrado (int cliente) throws RemoteException
	{
		return registrados.containsKey(cliente);
	}

	public int SubtotalDonaciones () throws RemoteException
	{
		int subtotal = 0;
		Collection<Integer> donaciones = registrados.values();

		for (int d : donaciones)
			subtotal += d;

		return subtotal;
	}

	private void IntroducirRegistro (int cliente)
	{
		this.registrados.put(cliente, 0);
	}

	public Replica (String host, int id, int total_replicas) throws RemoteException
	{
		registry                = LocateRegistry.getRegistry(host, 1099);
		this.id                 = id;
		Replica.total_replicas = total_replicas;
	}

	public int TotalDonado (int cliente) throws RemoteException, NotBoundException
	{
		int total = 0;

		if (RegistradoYDonado(cliente))
		{
			for (int i = 0; i < Replica.total_replicas; i++)
				total += ((Replica_I) registry.lookup("Replica" + i)).SubtotalDonaciones();
		}

		return total;
	}

	public int Registrar (int cliente) throws RemoteException, NotBoundException
	{
		int replica_min_registrados  = id;
		int min_total_registrados    = TotalRegistrados();
		boolean registrado           = false;
		Replica_I replica_candidata = (Replica_I) this;

		for (int i = 0; i < Replica.total_replicas; i++)
		{
			if (i != this.id)
			{
				replica_candidata = (Replica_I) registry.lookup("Replica" + i);

				if (!registrado)
					registrado = replica_candidata.Registrado(cliente);

				int total_registrados = replica_candidata.TotalRegistrados();

				if (total_registrados < min_total_registrados)
				{
					replica_min_registrados = i;
					min_total_registrados   = total_registrados;
				}
			}
		}

		if (!registrado)
		{
			if (replica_min_registrados != id)
			{
				replica_candidata = (Replica_I) registry.lookup("Replica" + replica_min_registrados);
				replica_candidata.Registrar(cliente);
			}
			else
			{
				System.out.println(
					"Registrando cliente " + cliente +
					" en Réplica " + this.id
				);
				IntroducirRegistro(cliente);
			}
		}

		return replica_min_registrados;
	}

	public int TotalRegistrados () throws RemoteException
	{
		return registrados.size();
	}

	public void Donar (int cliente, int cantidad) throws RemoteException
	{
		registrados.put(cliente, registrados.get(cliente) + cantidad);

		System.out.println(
			"Recibida donación de " + cantidad +
			"€ por parte de cliente " + cliente +
			" en Réplica " + this.id
		);
	}
}

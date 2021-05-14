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
	private static int replica_decisiva = -1;
	private static int valor_decisivo = -1;
	private static boolean decision_ejecutada = false;

	private boolean iniciadora   = false;
	private boolean participante = false;
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

	private void IntroducirRegistro (Cliente cliente)
	{
		this.registrados.put(cliente.id(), 0);
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

	public void Registrar (Cliente cliente) throws RemoteException, NotBoundException
	{
		System.out.println(
			"==> Recibida petición de registro de cliente " + cliente.id() +
			" en réplica " + id
		);

		if (!participante)
		{
			if (Replica.replica_decisiva == -1 && valor_decisivo == -1)
			{
				System.out.println("  -> Iniciando operación de consenso " + id);
				iniciadora               = true;
				Replica.replica_decisiva = id;
				Replica.valor_decisivo   = TotalRegistrados();
			}
			else if (TotalRegistrados() < valor_decisivo)
			{
				System.out.println("  -> Actualizando valores decisivos " + id);
				Replica.replica_decisiva = id;
				Replica.valor_decisivo   = TotalRegistrados();
			}

			participante = true;
		}
		else
		{
			if (Replica.replica_decisiva == id)
			{
				System.out.println(
					"  -> Registrando cliente " + cliente.id() +
					" en Réplica " + this.id
				);
				IntroducirRegistro(cliente);
				cliente.asignarReplica(this.id);
				Replica.decision_ejecutada = true;
			}
		}

		if (participante)
		{
			if (!Replica.decision_ejecutada)
			{
				Replica_I siguiente = (Replica_I) registry.lookup(
					"Replica" + (id+1)%Replica.total_replicas
				);
				siguiente.Registrar(cliente);
			}

			participante = false;
		}

		if (iniciadora)
		{
			Replica.decision_ejecutada = false;
			iniciadora                 = false;
			Replica.replica_decisiva   = -1;
			Replica.valor_decisivo     = -1;
		}
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

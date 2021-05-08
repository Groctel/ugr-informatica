package ejercicio;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Cliente implements Runnable
{
	private String host;
	private String replica;

	public Cliente (String host, String replica)
	{
		this.host    = host;
		this.replica = replica;
	}

	public static void main (String [] args)
	{
		String host                 = "localhost";
		Scanner scanner             = new Scanner(System.in);
		ArrayList<Cliente> clientes = new ArrayList<>();
		ArrayList<Thread> hebras    = new ArrayList<>();
		int total_clientes          = 0;

		do
		{
			System.out.print("Escoge una réplica [0-4]");
			String replica = scanner.nextLine();

			System.out.println("¿Cuántos clientes van a conectarse?");
			int clientes_conectantes = Integer.parseInt(scanner.nextLine());

			if (System.getSecurityManager() == null)
				System.setSecurityManager(new SecurityManager());

			for (int i = 0; i < clientes_conectantes; i++)
				clientes.add(new Cliente(host, replica));

			total_clientes += clientes_conectantes;

			System.out.println("¿Conectarse a otra réplica? [Y/*]");
		}
		while (scanner.nextLine().toUpperCase().equals("Y"));

		for (int i = 0; i < total_clientes; i++)
		{
			hebras.add(new Thread(clientes.get(i), Integer.toString(i)));
			hebras.get(i).start();
		}

		scanner.close();
	}

	@Override
	public void run ()
	{
		try
		{
			Registry registry = LocateRegistry.getRegistry(this.host, 1099);

			System.out.println(
				"Registrando cliente '" +
				Thread.currentThread().getName() +
				"' en Réplica " +
				this.replica +
				"..."
			);

			Donaciones_I local = (Donaciones_I) registry.lookup("Replica" + this.replica + "Donaciones");
			this.replica = Integer.toString(local.Registrar(Integer.parseInt(Thread.currentThread().getName())));

			System.out.println(
				"Cliente '" +
				Thread.currentThread().getName() +
				"' registrado en Réplica" +
				this.replica +
				"."
			);

			int donacion = new Random().nextInt(100);

			System.out.println(
				"Cliente '" +
				Thread.currentThread().getName() +
				"' dona " +
				donacion +
				"€ en Réplica" +
				this.replica +
				"..."
			);

			local = (Donaciones_I) registry.lookup("Replica" + this.replica + "Donaciones");
			local.Donar(donacion, Integer.parseInt(Thread.currentThread().getName()));

			System.out.println(
				"Donación del Cliente '" +
				Thread.currentThread().getName() +
				"' completada"
			);

			System.out.println(
				"(Cliente '" +
				Thread.currentThread().getName() +
				"') Total donaciones: "
				+ local.TotalDonado(Integer.parseInt(Thread.currentThread().getName()))
			);
		}
		catch (Exception e)
		{
			System.err.println("Cliente '" + Thread.currentThread().getName() + "' exception");
			e.printStackTrace();
		}
	}
}

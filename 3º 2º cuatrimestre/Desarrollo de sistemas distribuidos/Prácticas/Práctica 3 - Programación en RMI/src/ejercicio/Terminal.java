package ejercicio;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.RemoteException;
import java.rmi.NotBoundException;
import java.util.ArrayList;
import java.util.Scanner;

class Terminal
{
	public static void main (String [] args) throws RemoteException, NotBoundException
	{
		String host                 = "localhost";
		Scanner scanner             = new Scanner(System.in);
		ArrayList<Cliente> clientes = new ArrayList<>();
		int total_clientes          = 0;
		boolean continuar           = true;
		Registry registry           = LocateRegistry.getRegistry(host, 1099);
		Replica_I replica_base      = (Replica_I) registry.lookup("Replica0");

		while (continuar)
		{
			System.out.println("Elija una operación:");
			System.out.println("[1] -- Registrar un cliente.");
			System.out.println("[2] -- Donar una cantidad.");
			System.out.println("[3] -- Consultar el total donado.");
			System.out.println("[0] -- Abortar el programa.");
			System.out.print("> ");

			int opcion = Integer.parseInt(scanner.nextLine());
			System.out.println("");

			if (opcion == 1)
			{
				Cliente cliente = new Cliente(host, total_clientes++);
				replica_base.Registrar(cliente);
				clientes.add(cliente);
			}
			else if (opcion == 2)
			{
				if (total_clientes == 0)
				{
					System.out.println("No hay clientes registrados.");
					System.out.println("");
				}
				else
				{
					System.out.print(
						"¿Qué cliente va a donar? [0-" +
						(total_clientes-1) + "]: "
					);

					int num_cliente = Integer.parseInt(scanner.nextLine());

					if (num_cliente >= 0 && num_cliente < total_clientes)
					{
						Cliente cliente = clientes.get(num_cliente);

						System.out.print("¿Qué cantidad desea donar?: ");

						int donacion = Integer.parseInt(scanner.nextLine());
						System.out.println("");

						Replica_I replica = (Replica_I) registry.lookup(
							"Replica" + cliente.replica()
						);
						replica.Donar(num_cliente, donacion);
					}
					else
					{
						System.out.println("Cliente no válido. Operación abortada.");
						System.out.println("");
					}
				}
			}
			else if (opcion == 3)
			{
				if (total_clientes == 0)
				{
					System.out.println("No hay clientes registrados.");
					System.out.println("");
				}
				else
				{
					System.out.print(
						"¿Qué cliente va a consultar? [0-" +
						(total_clientes-1) + "]: "
					);

					int num_cliente = Integer.parseInt(scanner.nextLine());

					if (num_cliente >= 0 && num_cliente < total_clientes)
					{
						Cliente cliente = clientes.get(num_cliente);
						Replica_I replica = (Replica_I) registry.lookup(
							"Replica" + cliente.replica()
						);

						int total = replica.TotalDonado(num_cliente);

						if (total > 0)
							System.out.println("Se han donado un total de " + total + "€.");
						else
							System.out.println("Acceso denegado, done primero.");

						System.out.println("");
					}
					else
					{
						System.out.println("Cliente no válido. Operación abortada.");
						System.out.println("");
					}
				}
			}
			else if (opcion == 0)
			{
				continuar = false;
			}
		}

		scanner.close();
	}
}

package ejercicio;

import java.rmi.Naming;

public class Servidor
{
	public static void main (String [] args)
	{
		if (System.getSecurityManager() == null)
		{
			System.setSecurityManager(new SecurityManager());
		}

		try
		{
			int numReplicas = 5;

			for (int i = 0; i < numReplicas; i++)
			{
				String remoteObjectName = "Replica" + i;

				Replicas replica = new Replicas("localhost", i, numReplicas);    // Servidor-servidor
				Naming.rebind(remoteObjectName, replica);

				Donaciones donaciones = new Donaciones("localhost", replica); // Cliente-servidor
				Naming.rebind(remoteObjectName+"Donaciones", donaciones);

				System.out.println("Réplica " + i + " lista");
			}

			System.out.println("Todas las réplicas operativas.");

		}
		catch (Exception e) {
			System.err.println("Réplica exception");
			e.printStackTrace();
		}
	}
}

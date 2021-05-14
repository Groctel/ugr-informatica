package ejercicio;

import java.rmi.Naming;

public class Servidor
{
	static final int replicas = 5;

	public static void main (String [] args)
	{
		if (System.getSecurityManager() == null)
			System.setSecurityManager(new SecurityManager());

		try
		{
			for (int i = 0; i < replicas; i++)
			{
				Replica replica = new Replica("localhost", i, replicas);
				Naming.rebind("Replica"+i, replica);

				System.out.println("Réplica " + i + " desplegada");
			}

			System.out.println("¡Desplegadas todas las réplicas!");
		}
		catch (Exception e)
		{
			System.err.println("Réplica exception");
			e.printStackTrace();
		}
	}
}

package ejemplo2;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Ejemplo implements Ejemplo_I
{
	public Ejemplo ()
	{
		super();
	}

	public void EscribirMensaje (String mensaje)
	{
		System.out.println("\nEntra Hebra " + mensaje);
		//Buscamos los procesos 0, 10, 20,...

		if (mensaje.endsWith("0"))
		{
			try
			{
				System.out.println("Empezamos a dormir");
				Thread.sleep(5000);
				System.out.println("Terminamos de dormir");
			}
			catch (Exception e)
			{
				System.err.println("Ejemplo exception:");
				e.printStackTrace();
			}
		}

		System.out.println("Sale Hebra " + mensaje);
	}

	public static void main (String [] args)
	{
		if (System.getSecurityManager() == null)
		{
			System.setSecurityManager(new SecurityManager());
		}

		try
		{
			String nombre_objeto_remoto = "Ejemplo_I";
			Ejemplo_I prueba = new Ejemplo();
			Ejemplo_I stub = (Ejemplo_I) UnicastRemoteObject.exportObject(prueba, 0);

			Registry registry = LocateRegistry.getRegistry();
			registry.rebind(nombre_objeto_remoto, stub);

			System.out.println("Ejemplo bound");
		}
		catch (Exception e)
		{
			System.err.println("Ejemplo exception:");
			e.printStackTrace();
		}
	}
}

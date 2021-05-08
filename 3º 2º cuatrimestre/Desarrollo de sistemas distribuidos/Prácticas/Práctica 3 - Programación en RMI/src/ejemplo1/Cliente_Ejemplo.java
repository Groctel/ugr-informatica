package ejemplo1;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Cliente_Ejemplo
{
	public static void main (String [] args)
	{
		if (System.getSecurityManager() == null)
			System.setSecurityManager(new SecurityManager());

		try
		{
			Registry registry = LocateRegistry.getRegistry(args[0]);
			System.out.println("Buscando el objeto remoto.");

			String nombre_objeto_remoto = "Evaristo";
			Ejemplo_I instancia_local = (Ejemplo_I) registry.lookup(nombre_objeto_remoto);

			System.out.println("Invocando el objeto remoto.");
			instancia_local.EscribirMensaje(Integer.parseInt(args[1]));
		}
		catch (Exception e)
		{
			System.err.println("Ejemplo_I exception:");
			e.printStackTrace();
		}
	}
}

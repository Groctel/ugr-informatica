package ejemplo3;

import java.net.MalformedURLException;
import java.rmi.*;

public class Servidor
{
	public static void main (String [] args)
	{
		// Crea e instala el gestor de seguridad
		if (System.getSecurityManager() == null)
			System.setSecurityManager(new SecurityManager());

		try
		{
			Contador micontador = new Contador();
			Naming.rebind("micontador", micontador);

			//suma = 0;
			System.out.println("Servidor RemoteException | MalformedURLExceptiondor preparado");
		}
		catch(RemoteException | MalformedURLException e)
		{
			System.out.println("Exception: "+ e.getMessage());
		}
	}
}

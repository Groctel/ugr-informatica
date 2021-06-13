package ejemplo3;

import java.net.MalformedURLException;
import java.rmi.*;

public class Servidor
{
	public static void main (String [] args)
	{
		if (System.getSecurityManager() == null)
			System.setSecurityManager(new SecurityManager());

		try
		{
			Contador micontador = new Contador();
			Naming.rebind("micontador", micontador);

			System.out.println("Servidor preparado");
		}
		catch(RemoteException | MalformedURLException e)
		{
			System.out.println("Exception: "+ e.getMessage());
		}
	}
}

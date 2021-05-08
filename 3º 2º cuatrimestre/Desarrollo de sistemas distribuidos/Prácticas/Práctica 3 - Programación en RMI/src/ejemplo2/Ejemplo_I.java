package ejemplo2;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Ejemplo_I extends Remote
{
	public void EscribirMensaje (String mensaje) throws RemoteException;
}

package ejemplo1;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Ejemplo_I extends Remote
{
	public void EscribirMensaje (int id_proceso) throws RemoteException;
}

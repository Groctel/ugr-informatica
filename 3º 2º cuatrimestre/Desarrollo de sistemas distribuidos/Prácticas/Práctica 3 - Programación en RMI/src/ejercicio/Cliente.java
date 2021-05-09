package ejercicio;

public class Cliente
{
	String host;
	String replica = "null";

	Cliente (String host)
	{
		this.host    = host;
	}

	void AsignarReplica (String replica)
	{
		this.replica = replica;
	}
}


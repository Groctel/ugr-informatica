package ejercicio;

import java.io.Serializable;

class Cliente implements Serializable
{
	private static final long serialVersionUID = 637894393;
	private String host_;
	private int id_;
	private int replica_ = -1;

	Cliente (String host, int id)
	{
		host_ = host;
		id_   = id;
	}

	void asignarReplica (int replica)
	{
		replica_ = replica;
	}

	String host ()
	{
		return host_;
	}

	int id ()
	{
		return id_;
	}

	int replica ()
	{
		return replica_;
	}
}


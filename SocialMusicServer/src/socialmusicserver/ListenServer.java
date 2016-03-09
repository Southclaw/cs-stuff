/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/
package socialmusicserver;

import java.awt.Frame;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

class ListenServer extends Thread
{
	SocialMusicServer source;
	ServerSocket listenSocket;
	int port;
	Socket connection;
	HandleServer handle;
	boolean again = true;

	ListenServer(SocialMusicServer s)
	{
		super();
		source = (SocialMusicServer) s;
		port = source.DEFAULT_PORT;

		try
		{
			listenSocket = new ServerSocket(port);
		}
		catch (IOException except)
		{
			except.printStackTrace();
		}
	}

	public void run()
	{
		try
		{
			while (again)
			{
				Socket connection = listenSocket.accept();
				HandleServer handleServer = new HandleServer(connection, source);
			}
		}
		catch (IOException except)
		{
			except.printStackTrace();
		}
	}
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;


public class ListenServer extends Thread
{

	protected ServerSocket listenSocket;
	protected int socketPort;
    private List<HandleServer> clients_ = new ArrayList();
	
	private List listeners_ = new ArrayList();

	public ListenServer(int port)
	{
		super();
		try
		{
			listenSocket = new ServerSocket(port);
			socketPort = port;
			System.out.format("Created ServerSocket on %d\n", port);
		}
		catch(IOException except)
		{
			except.printStackTrace(System.out);
		}
	}

	public synchronized void addListener(EventListener l)
	{
		listeners_.add(l);
	}

	public synchronized void remListener(EventListener l)
	{
		listeners_.remove(l);
	}

	protected synchronized NetMessage listenEvent(HandleServer hsvr, String args[])
	{
		ListenEvent evnt = new ListenEvent(this, hsvr, args);
		Iterator listeners = listeners_.iterator();
		NetMessage reply = new NetMessage();
		NetMessage tmp;

		while(listeners.hasNext())
		{
			tmp = ((EventListener)listeners.next()).msgRecv(evnt);
			
			if(tmp.type == NetMessage.NMT.NUL)
			{
				continue;
			}
			
			if(tmp.type == NetMessage.NMT.BIN)
			{
				reply.bin = tmp.bin;
				reply.type = NetMessage.NMT.BIN;
				// can't appent multiple byte replies, break loop and return
				break;
			}
			else if(tmp.type == NetMessage.NMT.TXT)
			{
				reply.txt = tmp.txt;
				reply.type = NetMessage.NMT.TXT;
				break;
			}
			else
			{
				//
			}
		}
		
		return reply;
    }
    
    public void broadcast(String message)
    {
        while(clients_.iterator().hasNext())
        {
            clients_.iterator().next().pushUpdate(message);
        }
    }

	@Override
	public void run()
	{
		try
		{
			while(true)
			{
				Socket s = listenSocket.accept();
				String[] args = new String[1];

				HandleServer handleServer = new HandleServer(this, s);
                clients_.add(handleServer);

				args[0] = "CONN";
				listenEvent(handleServer, args);

				handleServer.run();

			}
		}
		catch(IOException except)
		{
			except.printStackTrace(System.out);
		}
	}
}

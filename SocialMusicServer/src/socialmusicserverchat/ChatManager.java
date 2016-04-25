/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserverchat;

import socialmusicserver.EventListener;
import socialmusicserver.ListenEvent;
import socialmusicserver.NetMessage;


class ChatManager implements EventListener
{
	public void init()
	{
		// 
	}

	public NetMessage msgRecv(ListenEvent event)
	{
		NetMessage reply = new NetMessage();

		switch(event.args()[0])
        {
            case "MSSG":
            {
				reply.txt = "ACKN";
                break;
            }
        }

		return reply;
	}


	// Singleton stuff
	
	private static ChatManager instance = new ChatManager();
	
	private ChatManager(){}
	
	public static ChatManager inst()
	{
		return instance;
	}

}

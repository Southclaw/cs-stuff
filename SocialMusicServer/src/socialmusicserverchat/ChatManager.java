/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserverchat;

import socialmusicserver.EventListener;
import socialmusicserver.ListenEvent;
import socialmusicserver.ListenServer;


class ChatManager implements EventListener
{
	public void init()
	{
		// 
	}

	public String msgRecv(ListenEvent event)
	{
		switch(event.args()[0])
        {
            case "MSSG":
            {
                break;
            }
        }

		return "ACKN";
	}


	// Singleton stuff
	
	private static ChatManager instance = new ChatManager();
	
	private ChatManager(){}
	
	public static ChatManager inst()
	{
		return instance;
	}

}

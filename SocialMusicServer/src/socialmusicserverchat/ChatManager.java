/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserverchat;

import socialmusicserver.EventListener;
import socialmusicserver.ListenEvent;


class ChatManager implements EventListener
{
	public void init()
	{
		// 
	}

	public String msgRecv(ListenEvent event)
	{
		System.out.println("msgRecv:");
		for(String s: event.args())
		{
			System.out.println(s);
		}
		System.out.println("END.");

		return "REPLY";
	}
	

	// Singleton stuff
	
	private static ChatManager instance = new ChatManager();
	
	private ChatManager(){}
	
	public static ChatManager inst()
	{
		return instance;
	}

}

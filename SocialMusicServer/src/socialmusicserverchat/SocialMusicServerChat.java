/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserverchat;

import socialmusicserver.ListenServer;
import socialmusicserver.UserManager;

public class SocialMusicServerChat
{

	public static void init()
	{
		ListenServer listen = new ListenServer(7779);
		listen.start();

		listen.addListener(ChatManager.inst());

		System.out.println("Chat Server Started");
	}

	// singleton stuff

	private static SocialMusicServerChat instance = new SocialMusicServerChat();
	
	private SocialMusicServerChat(){}
	
	public static SocialMusicServerChat inst()
	{
		return instance;
	}
}

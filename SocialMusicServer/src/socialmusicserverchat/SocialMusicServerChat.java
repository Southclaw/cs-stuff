/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserverchat;

public class SocialMusicServerChat
{

	public static void main(String[] args)
	{
		ListenServer listen = new ListenServer(7779);
		listen.start();
		System.out.println("Chat Server Started");
	}
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

public class SocialMusicServer
{

	public static void main(String[] args)
	{
		ListenServer listen = new ListenServer(7778);
		listen.start();
		System.out.println("Started");
	}
}

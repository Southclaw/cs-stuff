/*==============================================================================

	Systems Software Project

	Social Music Server

	Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import socialmusicserverchat.SocialMusicServerChat;


public class SocialMusicServer
{

	public static void main(String[] args)
	{
		ListenServer listen = new ListenServer(7778);
		listen.start();
		SocialMusicServerChat.init();
		UserManagerDB.inst().init();
		UserManager.inst().init();

		listen.addListener(UserManager.inst());
	}


	// event
	/*
		switch(a[0])
		{
			case "REGS":
			{
				// a[1] is username
				// a[2] is password hash
				return "REGISTER COMMAND";
			}

			case "LOGN":
			{
				// a[1] is username
				// a[2] is password hash
				// return user ID (positive integer/UUID) or -1 for failure
				return "LOGIN COMMAND";
			}

			case "DETL":
			{
				// a[1] is userid
				// return user details string
				// username (correctly capitalised) reg date, last login, etc
				return "DETAILS COMMAND";
			}

			case "FRND":
			{
				// a[1] is userid
				// return friends list
				return "FRIEND LIST COMMAND";
			}
		}
*/
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;


public class UserManager implements EventListener
{
	private static UserManagerDB udb;

	public void init()
	{
		udb = UserManagerDB.inst();
	}

	@Override
	public String msgRecv(ListenEvent event)
	{
		// DEBUG
		System.out.println("\n\nmsgRecv PARAM DEBUG:");
		for(String s: event.args())
		{
			System.out.println(s);
		}
		System.out.println("msgRecv END PARAM DEBUG\n\n");
		// END DEBUG

		switch(event.args()[0])
		{
			case "REGS":
			{
				// a[1] is username
				// a[2] is password hash
				ArrayList<String> musicProfile = new ArrayList<>();

				if(event.args().length > 3)
				{
					for(int i = 0; i < event.args().length - 2; ++i)
					{
						musicProfile.add(event.args()[i + 2]);
					}
				}

				int ret = udb.RegisterUser(event.args()[1], event.args()[2], musicProfile);

				if(ret == 0)
					return "SUCCESS";

				if(ret == 1)
					return "FAILEX";

				if(ret == 2)
					return "FAILDB";
			}

			case "LOGN":
			{
				// a[1] is username
				// a[2] is password hash
				// return user ID (positive integer/UUID) or -1 for failure
				int ret = udb.LoginUser(event.args()[1], event.args()[2]);

				if(ret == 0)
					return "SUCCESS";

				if(ret == 1)
					return "FAILEX";

				if(ret == 2)
					return "FAILDB";

				if(ret == 3)
					return "FAILPW";
			}

			case "DETL":
			{
				// a[1] is userid
				// return user details string
				// username (correctly capitalised) reg date, last login, etc
				return udb.getUserInfo(event.args()[1]);
			}

			case "FRND":
			{
				// a[1] is userid
				// return friends list
				return "FRIEND LIST COMMAND";
			}
		}

		return "REPLY";
	}
	

	// Singleton stuff
	
	private static UserManager instance = new UserManager();
	
	private UserManager(){}
	
	public static UserManager inst()
	{
		return instance;
	}
}

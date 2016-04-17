/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;


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
		System.out.println("msgRecv:");
		for(String s: event.args())
		{
			System.out.println(s);
		}
		System.out.println("END.");
		// END DEBUG

		switch(event.args()[0])
		{
			case "REGS":
			{
				// a[1] is username
				// a[2] is password hash
				int ret = udb.RegisterUser(event.args()[1], event.args()[2]);

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
				return "DETAILS COMMAND";
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

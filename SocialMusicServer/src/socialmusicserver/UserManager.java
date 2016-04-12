/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;


public class UserManager implements EventListener
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
	
	private static UserManager instance = new UserManager();
	
	private UserManager(){}
	
	public static UserManager inst()
	{
		return instance;
	}
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.util.Vector;


public class UserManager
{
	Vector<User> Users;

	UserManager()
	{
	//
	}
	
	public void AddUser(User user)
	{
		Users.add(user);
	}

	public void RemoveUser(User user)
	{
		Users.remove(user);
	}
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.util.Vector;
import java.sql.*;

public class UserManager
{
	Vector<User> Users;

	public static void init()
	{
		Connection c = null;
		try
		{
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:users.db");
		}
		catch (Exception e)
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit(0);
		}

		System.out.println("UserManager class initialised, database opened successfully.");
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

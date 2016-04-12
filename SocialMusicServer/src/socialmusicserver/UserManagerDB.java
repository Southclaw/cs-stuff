/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.util.Vector;
import java.sql.*;

public class UserManagerDB
{
	public final String userTable = "users";

	private Vector<User> Users;
	private Connection c;
	
	private PreparedStatement addUser;
	private PreparedStatement remUser;

	public void init()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:data.db");
			
			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+userTable+" (" +
					"uuid INT PRIMARY KEY NOT NULL," +
					"name TEXT NOT NULL,"+
					"pass TEXT NOT NULL,"+
					"loca TEXT NOT NULL,"+
					"brth TEXT NOT NULL,"+
					"info TEXT NOT NULL )");
			}

			addUser = c.prepareStatement("INSERT INTO "+userTable+" VALUES(?, ?, ?, ?, ?, ?)");
			remUser = c.prepareStatement("DELETE FROM "+userTable+" WHERE name = ?");
		}
		catch (ClassNotFoundException | SQLException e)
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
	
	// Singleton stuff
	
	private static UserManagerDB instance = new UserManagerDB();
	
	private UserManagerDB(){}
	
	public static UserManagerDB inst()
	{
		return instance;
	}
}

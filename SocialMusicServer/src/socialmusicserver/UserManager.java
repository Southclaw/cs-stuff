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
	public final String userTable = "users";

	private Vector<User> Users;
	private Connection c;
	
	private PreparedStatement addUser;
	private PreparedStatement updUser;
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
					"UUID INT PRIMARY KEY NOT NULL," +
					"NAME TEXT NOT NULL,"+
					"PASS TEXT NOT NULL,"+
					"LOCA TEXT NOT NULL,"+
					"BRTH TEXT NOT NULL"+
					"INFO TEXT NOT NULL"+
					")");
			}

			addUser = c.prepareStatement("INSERT INTO users VALUES(?, ?, ?, ?, ?);");
			updUser = c.prepareStatement("UPDATE users SET (?, ?, ?, ?, ?);");
			remUser = c.prepareStatement("INSERT INTO users VALUES(?, ?, ?, ?, ?);");
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
	
	private static UserManager instance = new UserManager();
	
	private UserManager(){}
	
	public static UserManager inst()
	{
		return instance;
	}
}

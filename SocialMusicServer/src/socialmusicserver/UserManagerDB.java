/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;


public class UserManagerDB
{
	public final String userTable = "users";

	private Connection c;

	private PreparedStatement addUser;
	private PreparedStatement chkUser;
	private PreparedStatement logUser;

	public void init()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:data.db");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+userTable+" (" +
					"uuid INT PRIMARY KEY," +
					"name TEXT NOT NULL,"+
					"pass TEXT NOT NULL,"+
					"loca TEXT,"+
					"brth TEXT,"+
					"info TEXT )");
			}

			addUser = c.prepareStatement("INSERT INTO "+userTable+" (name, pass) VALUES(?, ?)");
			chkUser = c.prepareStatement("SELECT count(*) FROM "+userTable+" WHERE name = ? COLLATE NOCASE");
			logUser = c.prepareStatement("SELECT * FROM "+userTable+" WHERE name=? COLLATE NOCASE");
		}
		catch (ClassNotFoundException | SQLException e)
		{
			e.printStackTrace(System.out);
			System.exit(0);
		}

		System.out.println("UserManager class initialised, database opened successfully.");
	}

	public boolean AccountExists(String name)
	{
		boolean exists = false;

		try
		{
			chkUser.setString(1, name);
			ResultSet r = chkUser.executeQuery();

			exists = r.getInt(1) > 0;

			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
		}

		return exists;
	}
	
	public int RegisterUser(String name, String pass)
	{
		System.out.println("RegisterUser called");
		if(AccountExists(name))
		{
			return 1;
		}

		try
		{
			addUser.setString(1, name);
			addUser.setString(2, pass);
			addUser.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return 2;
		}

		return 0;
	}
	
	public int LoginUser(String name, String pass)
	{
		System.out.println("LoginUser called");
		if(!AccountExists(name))
		{
			return 1;
		}

		ResultSet r;
		String rpass;

		try
		{
			logUser.setString(1, name);
			r = logUser.executeQuery();
			rpass = r.getString(3);

			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return 2;
		}

		System.out.println("\n");
		System.out.println(pass);
		System.out.println(rpass);
		System.out.println("\n");

		if(!pass.equals(rpass))
		{
			return 3;
		}

		return 0;
	}

	// Singleton stuff

	private static UserManagerDB instance = new UserManagerDB();

	private UserManagerDB(){}

	public static UserManagerDB inst()
	{
		return instance;
	}
}

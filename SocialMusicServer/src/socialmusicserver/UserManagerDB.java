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
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;


public class UserManagerDB
{
	public final String userTable = "users";
	public final String friendTable = "friends";

	private Connection c;

	private PreparedStatement addUser;
	private PreparedStatement chkUser;
	private PreparedStatement logUser;
	
	private PreparedStatement getFriends;
	private PreparedStatement addFriend;
	private PreparedStatement delFriend;
	private PreparedStatement chkFriend;

	public void init()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:data.db");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+userTable+" ("+
					"uuid INT PRIMARY KEY AUTOINCREMENT,"+
					"name TEXT NOT NULL,"+
					"pass TEXT NOT NULL,"+
					"loca TEXT,"+
					"brth TEXT,"+
					"musc TEXT,"+
					"info TEXT )");
			}

			addUser = c.prepareStatement("INSERT INTO "+userTable+" (name, pass, musc) VALUES(?, ?, ?)");
			chkUser = c.prepareStatement("SELECT count(*) FROM "+userTable+" WHERE name = ? COLLATE NOCASE");
			logUser = c.prepareStatement("SELECT * FROM "+userTable+" WHERE name=? COLLATE NOCASE");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+userTable+" ("+
					"name TEXT NOT NULL,"+
					"rela TEXT NOT NULL)");
			}

			getFriends = c.prepareStatement("SELECT rela FROM "+friendTable+" WHERE name=?");
			addFriend = c.prepareStatement("INSERT INTO "+friendTable+" VALUES(?, ?)");
			delFriend = c.prepareStatement("DELETE FROM "+friendTable+" WHERE name=? AND rela=?");
			chkFriend = c.prepareStatement("SELECT COUNT(*) FROM "+friendTable+" WHERE name=? AND rela=?");
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
	
	public int RegisterUser(String name, String pass, ArrayList<String> musicList)
	{
		if(AccountExists(name))
		{
			return 1;
		}

		String musicListString = "";

		if(musicList.size() > 0)
		{
			Set<Integer> items = new HashSet<>();
			musicListString = musicList.get(0);

			for(int i = 1; i < musicList.size(); ++i)
			{
				// quick set usage to handle duplicates
				if(items.add(Integer.getInteger(musicList.get(i))))
				{
					musicListString += " " + musicList.get(i);
				}
			}
		}

		try
		{
			addUser.setString(1, name);
			addUser.setString(2, pass);
			addUser.setString(3, musicListString);
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
	
	public String getUserInfo(String name)
	{
		System.out.println("getUserInfo called");
		if(!AccountExists(name))
		{
			return "FAILEX";
		}

		String information = "";
		
		try
		{
			logUser.setString(1, name);
			ResultSet r = logUser.executeQuery();
			
			information = r.getString("info");
			
			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
			return "FAILDB";
		}
		
		return information;
	}
	
	public String getUserFriends(String name)
	{
		System.out.println("getUserFriends called");
		if(!AccountExists(name))
		{
			return "FAILEX";
		}

		String friendsList = "FRIENDS";

		try
		{
			getFriends.setString(1, name);
			ResultSet r = getFriends.executeQuery();
			
			while(r.next())
			{
				friendsList += " " + r.getString(1);
			}
			
			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
			return "FAILDB";
		}
		
		return friendsList;
	}

	// Singleton stuff

	private static UserManagerDB instance = new UserManagerDB();

	private UserManagerDB(){}

	public static UserManagerDB inst()
	{
		return instance;
	}
}

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
	public final String friendReqTable = "friend_reqs";
	public final String postTable = "posts";

	private Connection c;

	private PreparedStatement addUser;
	private PreparedStatement chkUser;
	private PreparedStatement logUser;

	private PreparedStatement getFriends;
	private PreparedStatement addFriend;
	private PreparedStatement delFriend;
	private PreparedStatement chkFriend;

	private PreparedStatement getFriendReqs;
	private PreparedStatement addFriendReq;
	private PreparedStatement delFriendReq;

	private PreparedStatement getPosts;
	private PreparedStatement addPost;
	private PreparedStatement delPost;

	public void init()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:data.db");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+userTable+" ("+
					"uuid INTEGER PRIMARY KEY AUTOINCREMENT,"+
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
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+friendTable+" ("+
					"name TEXT NOT NULL,"+
					"rela TEXT NOT NULL)");
			}

			getFriends = c.prepareStatement("SELECT rela FROM "+friendTable+" WHERE name=?");
			addFriend = c.prepareStatement("INSERT INTO "+friendTable+" VALUES(?, ?)");
			delFriend = c.prepareStatement("DELETE FROM "+friendTable+" WHERE name=? AND rela=?");
			chkFriend = c.prepareStatement("SELECT COUNT(*) FROM "+friendTable+" WHERE name=? AND rela=?");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+friendReqTable+" ("+
					"name TEXT NOT NULL,"+
					"rela TEXT NOT NULL)");
			}

			getFriendReqs = c.prepareStatement("SELECT rela FROM "+friendReqTable+" WHERE name=?");
			addFriendReq = c.prepareStatement("INSERT INTO "+friendReqTable+" VALUES(?, ?)");
			delFriendReq = c.prepareStatement("DELETE FROM "+friendReqTable+" WHERE name=? AND rela=?");

			try (Statement stmt = c.createStatement())
			{
				stmt.executeUpdate("CREATE TABLE IF NOT EXISTS "+postTable+" ("+
					"id INTEGER PRIMARY KEY AUTOINCREMENT,"+
					"name TEXT NOT NULL,"+
					"date DATE NOT NULL,"+
					"post TEXT NOT NULL)");
			}

			getPosts = c.prepareStatement("SELECT id, name, post FROM "+postTable+" ORDER BY date DESC LIMIT ?");
			addPost = c.prepareStatement("INSERT INTO "+postTable+" (name, date, post) VALUES(?, strftime('%s','now'), ?)");
			delPost = c.prepareStatement("DELETE FROM "+postTable+" WHERE id=?");
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

		if(!pass.equals(rpass))
		{
			return 3;
		}

		return 0;
	}
	
	public String getUserInfo(String name)
	{
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
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return information;
	}

	public String getUserFriends(String name)
	{
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
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return friendsList;
	}

	public String addUserFriend(String name, String rela)
	{
		if(!AccountExists(name))
		{
			return "FAILEX1";
		}

		if(!AccountExists(rela))
		{
			return "FAILEX2";
		}

		try
		{
			addFriend.setString(1, name);
			addFriend.setString(2, rela);
			addFriend.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}

	public String delUserFriend(String name, String rela)
	{
		if(!AccountExists(name))
		{
			return "FAILEX1";
		}

		if(!AccountExists(rela))
		{
			return "FAILEX2";
		}

		try
		{
			delFriend.setString(1, name);
			delFriend.setString(2, rela);
			delFriend.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}


	public String getUserFriendReqs(String name)
	{
		if(!AccountExists(name))
		{
			return "FAILEX";
		}

		String friendsList = "FRIENDS";

		try
		{
			getFriendReqs.setString(1, name);
			ResultSet r = getFriendReqs.executeQuery();
			
			while(r.next())
			{
				friendsList += " " + r.getString(1);
			}
			
			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return friendsList;
	}

	public String addUserFriendReq(String name, String rela)
	{
		if(!AccountExists(name))
		{
			return "FAILEX1";
		}

		if(!AccountExists(rela))
		{
			return "FAILEX2";
		}

		try
		{
			addFriendReq.setString(1, name);
			addFriendReq.setString(2, rela);
			addFriendReq.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}

	public String delUserFriendReq(String name, String rela)
	{
		if(!AccountExists(name))
		{
			return "FAILEX1";
		}

		if(!AccountExists(rela))
		{
			return "FAILEX2";
		}

		try
		{
			delFriendReq.setString(1, name);
			delFriendReq.setString(2, rela);
			delFriendReq.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}

	public String getPostsList()
	{
		String output = "POSTS\t";
		try
		{
			getPosts.setInt(1, 10);
			ResultSet r = getPosts.executeQuery();

			while(r.next())
			{
				output += "(" + r.getString(1) + ")" + r.getString(2) + ": " + r.getString(3) + "\t";
			}

			r.close();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}

		return output;
	}

	public String addPublicPost(String name, String post)
	{
		try
		{
			addPost.setString(1, name);
			addPost.setString(2, post);
			addPost.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}

	public String delPublicPost(String name, String post)
	{
		try
		{
			delPost.setString(1, name);
			delPost.setString(2, post);
			delPost.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace(System.out);
			return "FAILDB";
		}
		
		return "SUCCESS";
	}

	// Singleton stuff

	private static UserManagerDB instance = new UserManagerDB();

	private UserManagerDB(){}

	public static UserManagerDB inst()
	{
		return instance;
	}
}

/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;


public class User
{
	public String RemoteAddress;
	public String Username;
	public String Password;
	public String Location;
	public String DateOfBirth;
	public String Information;

	public String MusicProfile[];
	public String Friends[];
	public String SharedSongs[];
	public String FriendRequests[];
	
	public User(String address, String username, String password)
	{
		RemoteAddress = address;
		Username = username;
		Password = password;
	}
}

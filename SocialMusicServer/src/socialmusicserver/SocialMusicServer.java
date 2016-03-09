/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.net.*;
import java.io.*;
import java.awt.*;

public class SocialMusicServer
{
	public static final String DEFAULT_HOST = "ntu.ac.uk";
	public static final int DEFAULT_PORT = 8888;
	String host;
	ListenServer listen;

	public SocialMusicServer()
	{
		listen = new ListenServer(this);
		listen.start();
	}

	public static void main(String[] args)
	{
		SocialMusicServer server = new SocialMusicServer();

		System.out.println("Hello");
	}
}

/*==============================================================================

	Systems Software Project

	Social Music Server

	Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import socialmusicserverchat.SocialMusicServerChat;


public class SocialMusicServer
{
	public static void main(String[] args)
	{
/*
		MusicTypeList[0] = "Alternative";
		MusicTypeList[1] = "Blues";
		MusicTypeList[2] = "Classical";
		MusicTypeList[3] = "Country";
		MusicTypeList[4] = "Dance";
		MusicTypeList[5] = "Easy Listening";
		MusicTypeList[6] = "Electronic";
		MusicTypeList[7] = "Folk";
		MusicTypeList[8] = "Hip Hop / Rap";
		MusicTypeList[9] = "Indie Pop";
		MusicTypeList[10] = "Gospel";
		MusicTypeList[11] = "Asian Pop";
		MusicTypeList[12] = "Jazz";
		MusicTypeList[13] = "Latin";
		MusicTypeList[14] = "Opera";
		MusicTypeList[15] = "Pop (Popular music)";
		MusicTypeList[16] = "R&B / Soul";
		MusicTypeList[17] = "Reggae";
		MusicTypeList[18] = "Rock";
		MusicTypeList[19] = "World Music / Beats";
*/

		ListenServer listen = new ListenServer(7778);
		listen.start();
		SocialMusicServerChat.init();
		UserManagerDB.inst().init();
		
		SocialMusicServerChat chat = SocialMusicServerChat.inst();

		UserManager.inst().init(chat);

		listen.addListener(UserManager.inst());
	}
}

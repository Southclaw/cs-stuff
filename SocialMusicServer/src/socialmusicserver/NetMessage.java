/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;


public class NetMessage
{
	public enum NMT // network message type
	{
		NUL, // empty
		TXT, // text
		BIN  // binary
	}
	
	public NMT type;
	
	// data if binary_ == false
	public String txt;
	
	// data if binary_ == true
	public byte[] bin;

	public NetMessage()
	{
		type = NMT.NUL;
	}

	public NetMessage(String s)
	{
		type = NMT.TXT;
		txt = s;
	}

	public NetMessage(byte[] b)
	{
		type = NMT.BIN;
		bin = b;
	}
}

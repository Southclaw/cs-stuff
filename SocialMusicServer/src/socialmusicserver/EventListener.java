/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

public interface EventListener 
{
	public NetMessage msgRecv(ListenEvent event);
}

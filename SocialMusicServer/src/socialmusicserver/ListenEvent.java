/*==============================================================================

    Systems Software Project

    Social Music Server

    Barnaby Keene 2016

==============================================================================*/


package socialmusicserver;

import java.util.EventObject;


public class ListenEvent extends EventObject
{
	private HandleServer hsvr_;
	private String[] args_;

	public ListenEvent(Object source, HandleServer hsvr, String[] args)
	{
		super(source);
		hsvr_ = hsvr;
		args_ = args;
	}

	public HandleServer hsvr()
	{
		return hsvr_;
	}

	public String[] args()
	{
		return args_;
	}

	public String addr()
	{
		return hsvr_.getAddress();
	}
}

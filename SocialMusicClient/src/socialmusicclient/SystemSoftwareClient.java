package socialmusicclient;
///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//package systemsoftwareclient;
//
///**
// *
// * @author N0574076
// */
//
//import java.net.*;
//import java.io.*;
//import java.util.*;
//import java.awt.*;
//
//public class SystemSoftwareClient extends Frame  {
//
////*****  Mult-thread client
////            expects to find server on capefear.cs.unc.edu:8888
//
//Connection connection;
//public final String DEFAULT_HOST = "capefear.cs.unc.edu";
//public final int DEFAULT_PORT = 8888;
//
//MyFrame outerBox;
//
//public TextField hostDisplay, portDisplay;
//public TextArea logDisplay, msgDisplay;
//Panel topPanel;
//Panel middlePanel;
//Panel buttonPanel;
//Button connectButton, sendButton, cancelButton, quitButton;
//
//// **************
//
//  public SystemSoftwareClient  ()  {  
//    super ( "SystemSoftwareClient " );
//  }  // end Client_Threaded constructor
//
//// **************
//
//  public static void main ( String [ ] args )  {
//    SystemSoftwareClient client = new SystemSoftwareClient ();
//    client.buildUI ();
//  }  // end main
//
//// **************
//
//  public boolean action (Event event, Object arg) {
//
//    if (event.target == connectButton )  {
//
//      connection = new Connection ( this );
//      connection.start();
//      connection.connectServer ();
//      return true;
//
//    }  // end connectButton 
//
//    if (event.target == sendButton )  {
//
//      connection.sendReceive ();
//      return true;
//    }  // end sendButton
//
//    if (event.target == cancelButton )  {
//      msgDisplay.setText ( "" );
//      return true;
//    }  // end cancelButton 
//
//    if (event.target == quitButton )  {
//
//      connection.quitServer();
//      hide ();
//      dispose ();
//      System.exit ( 0 );
//      return true;
//    }  // end quitButton 
//
//    return false;
//
//  }  // end action
//
//// **************
//
//  public boolean handleEvent ( Event event )  {
//
//    if ( event.id == Event.WINDOW_ICONIFY )  {
//      hide ();
//      dispose ();
//      System.exit ( 0 );
//    }  // end if
//
//    return super.handleEvent ( event );
//
//  }  // end handleEvent 
//
//// **************
//
//  public void buildUI ()  {
//
//  hostDisplay = new TextField ( DEFAULT_HOST, 30 );
//  portDisplay = new TextField ( Integer.toString ( DEFAULT_PORT ), 4 );
//  topPanel = new Panel ();
//  topPanel.setLayout ( new BorderLayout () );
//  topPanel.add ( "North", hostDisplay );
//  topPanel.add ( "South", portDisplay );
//
//  logDisplay = new TextArea ( 40, 10 );
//  msgDisplay = new TextArea ( 40, 10 );
//  msgDisplay .setText ( "Default message." );
//  middlePanel = new Panel ();
//  middlePanel.setLayout ( new GridLayout ( 2, 1 ) );
//  middlePanel.add ( logDisplay );
//  middlePanel.add ( msgDisplay );
//
//  connectButton = new Button ( "Connect" );
//  sendButton = new Button ( "Send" );
//  cancelButton = new Button ( "Cancel" );
//  quitButton = new Button ( "Quit" );
//  buttonPanel = new Panel ( );
//  buttonPanel.add ( connectButton );
//  buttonPanel.add ( sendButton );
//  buttonPanel.add ( cancelButton );
//  buttonPanel.add ( quitButton );
//
//  outerBox = new MyFrame ( this, "Client_Threaded" );
//  outerBox.add ( "North", topPanel );
//  outerBox.add ( "Center", middlePanel );
//  outerBox.add ( "South", buttonPanel );
//
//  outerBox.resize ( 350, 400 );
//  outerBox.show ();
//
//  }  // end buildUI 
//
//}  // end Client_Threaded 
//
//// ************************  Connection Class ************************
//
//class Connection extends Thread  {
//  SystemSoftwareClient source;
//
//  Socket socket;
//  InputStream input;
//  OutputStream output;
//  char c;
//  String host;
//  int port;
//  boolean again = true;
//  String string;
//
//// **************
//
//  Connection (Frame s)  {
//    super ();
//    source = (SystemSoftwareClient) s;
//  }// end constructor
//
//// **************
//
//  public void run ()  {
//  }  // end run
//
//// **************
//
//  public void connectServer (  )  {
//
//    host = (source.hostDisplay).getText ();
//    port = Integer.parseInt ( (source.portDisplay).getText () );
//
//    try  {
//      socket = new Socket ( InetAddress.getByName ( host), port );
//      output = socket.getOutputStream ();
//      input = socket.getInputStream ();
//      source.logDisplay.setText ( "Socket created:  connecting to server\n" );
//
//     }
//    catch ( IOException except)  {
//      except.printStackTrace ();
//    }  // end catch
//
//  }  // end connectServer 
//
//// **************
//
//  public void sendReceive () {
//
//      source.logDisplay.appendText ( "Message, below, sent to Server\n" );
//      putMsg ( output, source.msgDisplay.getText () );
//
//      source.logDisplay.appendText ( "Message, below, received from server\n" );
//      source.msgDisplay.setForeground ( Color.red );
//      String stringIn = getMsg ( input );
//      source.msgDisplay.setText ( stringIn);
//
//}  // end sendReceive  
//
//// **************
//
//  public void quitServer () {
//
//    putMsg ( output, "$" );
//    try {
//      socket.close ();
//     }  catch ( IOException except )  {
//       except.printStackTrace ();
//     }
//    (source.logDisplay).appendText ( "Connection closed\n" );
//  }  // end quitServer
//
//// **************
//
//  public String getMsg ( InputStream input )  {
//    char[] charArray = new char [ 1024 ];
//  char c;
//        try {
//           int i = 0;
//            while ( ( (c = (char) input.read () ) != '#' ) && (i < 1024) ) {
//             charArray [ i ] =  c ;
//             i++;
//           }  // end while
//        }  catch ( IOException except )  {
//           except.printStackTrace ();
//        }  // end catch
//         String string = new String ( String.valueOf ( charArray) );
//          return string;
//  }  // end getMsg
//
//// **************
//
//  public void putMsg ( OutputStream output, String string )  {
//    try {
//      for ( int i = 0; i < string.length(); i++ ) {
//        output.write ( (int) string.charAt ( i ) );
//      }  // end for
//      output.write ( (int)'#' );  // end of message mark
//    }  catch ( IOException except )  {
//       except.printStackTrace ();
//    }  // end catch
//  }  // end putMsg
//
//
//}  // end Connection
//
//// ************************  MyFrame Class ************************
//
//class MyFrame extends Frame  {
//  Frame source;
//
//  MyFrame ( Frame a )  {
//    super ( );
//    source = a;
//  }  // end constructor
//
//  MyFrame ( Frame a, String title )  {
//    super ( title );
//    source = a;
//  }  // end constructor
//
//  public boolean action ( Event event, Object object )  {
//    if ( source.action ( event, object ) ) return true;
//    else return false;
//  }  // end action
//
//  public boolean handleEvent ( Event event )  {
//    if ( source.handleEvent ( event ) ) return true;
//    else return super.handleEvent ( event );
//  }  // end handleEvent
//
//}  // end MyFrame
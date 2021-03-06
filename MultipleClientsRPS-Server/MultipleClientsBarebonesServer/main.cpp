#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main()
{
	// Initialze winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return;
	}
	
	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		return;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; 
	
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);

	// Create the master file descriptor set and zero it
	// the main variable for handling one thread client server
	fd_set master;
	FD_ZERO(&master);

	// Add our first socket that we're interested in interacting with; 
	// the listening socket to hear incoming connections 
	FD_SET(listening, &master);

	//assign variables for the loop
	bool running = true; 
	string ClientID1 = "\n";
	string ClientID2 = "\n";
	bool showOnce = true;

	while (running)
	{
		fd_set copy = master;

		// initialize socket count to be looped
		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		// Loop through all the current connections / potential connect
		for (int i = 0; i < socketCount; i++)
		{
			// Makes things easy for us doing this assignment
			SOCKET sock = copy.fd_array[i];
			
			// Is it an inbound communication?
			if (sock == listening)
			{
				// Accept a new connection
				SOCKET client = accept(listening, nullptr, nullptr);
				
				// Add the new connection to the list of connected clients
				FD_SET(client, &master);

				// Send a welcome message to the connected client
				string Msg = "Welcome to Rock Paper Scissors!\n"
					"Enter an input: Rock, Paper, or Scissors? \n";
				send(client, Msg.c_str(), Msg.size() + 1, 0);
				
			}
			else // It's an inbound message
			{
				char buf[4096];
				ZeroMemory(buf, 4096);
				
				// Makes things easy for us doing this assignment
				int bytesIn = recv(sock, buf, 4096, 0);
				if (bytesIn <= 0) // if no msg receive
				{
					// Drop the client
					closesocket(sock);
					FD_CLR(sock, &master);
				}
				else
				{
					// Check to see if it's a command. \quit kills the server
					if (buf[0] == '\\')
					{
						// Is the command quit? 
						string cmd = string(buf, bytesIn);
						if (cmd == "\\quit")
						{
							exit(1);
							break;
						}
						// Unknown command
						continue;
					}
					
					// main loop for checking the logic of client inputs
					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];

						ostringstream ss;
						ss << "Player" << outSock; //current client = outsock; other client = sock
						string name1 = ss.str();
						ClientID1 = name1;
						ss << "Player" << sock; //current client = outsock; other client = sock
						string name2 = ss.str();
						ClientID2 = name2;

						if (buf[0] == 'r' || buf[0] == 'R') {
							name1 = "Your PlayerID is " + ClientID1 + "\n";
							
							if (outSock != listening && outSock != sock)
							{
								ostringstream ss2;
								ss2 << "Player" << sock << " picked Rock!" << "\r\n";
								string strOut = ss2.str();
								
								strOut = name1 + strOut;

								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
						else if (buf[0] == 'p' || buf[0] == 'P') {
							name1 = "Your PlayerID is " + ClientID1 + "\n";
							if (outSock != listening && outSock != sock)
							{
								ostringstream ss2;
								ss2 << "Player" << sock << " picked Paper!" << "\r\n";
								string strOut = ss2.str();

								strOut = name1 + strOut;

								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
						else if (buf[0] == 's' || buf[0] == 'S') {
							name1 = "Your PlayerID is " + ClientID1 + "\n";
							if (outSock != listening && outSock != sock)
							{	
								ostringstream ss2;
								ss2 << "Player" << sock << " picked Scissors!" << "\r\n";
								string strOut = ss2.str();

								strOut = name1 + strOut;

								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
						else {
							name1 = "Your PlayerID is " + ClientID1 + "\n";
							if (outSock != listening && outSock != sock)
							{
								ostringstream ss2;
								ss2 << "Player" << sock << " had an Invalid Input" << "\r\n";
								string strOut = ss2.str();

								strOut = name1 + strOut;
								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
						
					}
				}
			}
		}
	}

	

	// Remove the listening socket from the master file descriptor set and close it
	// to prevent anyone else trying to connect.
	FD_CLR(listening, &master);
	closesocket(listening);
	
	// Message to let users know what's happening.
	string msg = "Server is shutting down. Goodbye\r\n";

	while (master.fd_count > 0)
	{
		// Get the socket number
		SOCKET sock = master.fd_array[0];

		// Send the goodbye message
		send(sock, msg.c_str(), msg.size() + 1, 0);

		// Remove it from the master file list and close the socket
		FD_CLR(sock, &master);
		closesocket(sock);
	}

	// Cleanup winsock
	WSACleanup();

	//system("pause");
}
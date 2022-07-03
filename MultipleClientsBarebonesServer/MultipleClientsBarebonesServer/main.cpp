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
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 
	
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);

	// Create the master file descriptor set and zero it
	fd_set master;
	FD_ZERO(&master);

	// Add our first socket that we're interested in interacting with; the listening socket!
	// It's important that this socket is added for our server or else we won't 'hear' incoming
	// connections 
	FD_SET(listening, &master);

	// this will be changed by the \quit command (see below, bonus not in video!)
	bool running = true; 
	bool runningSelection = false;
	bool runningGame = false;
	string name[2];

	while (running)
	{
		// Make a copy of the master file descriptor set, this is SUPER important because
		// the call to select() is _DESTRUCTIVE_. The copy only contains the sockets that
		// are accepting inbound connection requests OR messages. 

		// E.g. You have a server and it's master file descriptor set contains 5 items;
		// the listening socket and four clients. When you pass this set into select(), 
		// only the sockets that are interacting with the server are returned. Let's say
		// only one client is sending a message at that time. The contents of 'copy' will
		// be one socket. You will have LOST all the other sockets.

		// SO MAKE A COPY OF THE MASTER LIST TO PASS INTO select() !!!

		fd_set copy = master;
		

		// See who's talking to us
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
				string pokemonMsg = "Pokemon Duel Simulator\n"
					"Greetings Trainers! We are trying to develop a simulator in order to learn more about pokemon.\n"
					"As of now we currently have 7 pokemon in the system with two different moves\nWe ask that two of you do a battle simulation with a pokemon of your choosing\n"
					"The starting turn is determined randomly\n"
					"\t[1] - Entei\t[4] - Pikachu\t[7] - Stunfisk\n"
					"\t[2] - Milotic\t[5] - Groudon\n"
					"\t[3] - Torterra\t[6] - Lapras\n\n";
				send(client, pokemonMsg.c_str(), pokemonMsg.size() + 1, 0);
				//string welcomeMsg = "Waiting for player to join...\r\n";
				//send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
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
					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];
						if (buf[0] == '1') {
								
							if (outSock != listening && outSock != sock)
							{
								ostringstream ss; // find a way to change player number
								ss << "Player" << sock << " chosed Entei" << "\r\n";
								string strOut = ss.str();

								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
						if (buf[0] == '2') {

							if (outSock != listening && outSock != sock)
							{
								ostringstream ss; // find a way to change player number
								ss << "Player" << sock << " chosed Milotic" << "\r\n";
								string strOut = ss.str();

								send(outSock, strOut.c_str(), strOut.size() + 1, 0);
							}
						}
					}
				}
				
				// Receive message
				/*
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
					if (buf[0] == 'quit')
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
					
					// Send message to other clients, and definiately NOT the listening socket
					/*
					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];
						if (outSock != listening && outSock != sock)
						{
							ostringstream ss; // find a way to change player number
							ss << "Player" << sock << ": " << buf << "\r\n";
							string strOut = ss.str();

							send(outSock, strOut.c_str(), strOut.size() + 1, 0);
						}
					}
					
				}*/
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
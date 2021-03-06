#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main()
{
	string ipAddress = "127.0.0.1";			// IP Address of the server
	int port = 54000;						// Listening port # on the server

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Can't start Winsock, Err #" << wsResult << endl;
		return;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	// Fill in a hint structure, which contains the adress and port
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	// Do-while loop to send and receive data
	char buf[4096];
	string userInput;
	bool once = false;
	int points = 0;

	do
	{
		if (!once) {
			ZeroMemory(buf, 4096);
			int bytesReceived = recv(sock, buf, 4096, 0);
			if (bytesReceived > 0)
			{
				// print out initial msg from server
				cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
			}
			once = true;
		}
		
		// Prompt the user for some text
		cout << "> ";
		getline(cin, userInput);

		if (userInput.size() > 0) 
		{
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				// Wait for response
				ZeroMemory(buf, 4096);
				int bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{
					// Print out server response to client console
					cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;

					// game result and logic from the client and server data
					// rock picked
					if (buf[44] == 'R' && (userInput == "r" || userInput == "R")) {
						cout << "SERVER> It's a draw" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'S' && (userInput == "r" || userInput == "R")) {
						cout << "SERVER> You Win! +1 Point" << endl;
						points++;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'P' && (userInput == "r" || userInput == "R")) {
						cout << "SERVER> You Lose!" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					// paper picked
					else if (buf[44] == 'P' && (userInput == "p" || userInput == "P")) {
						cout << "SERVER> It's a draw" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'R' && (userInput == "p" || userInput == "P")) {
						cout << "SERVER> You Win! +1 Point" << endl;
						points++;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'S' && (userInput == "p" || userInput == "P")) {
						cout << "SERVER> You Lose!" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					// scissors picked 
					else if (buf[44] == 'S' && (userInput == "s" || userInput == "S")) {
						cout << "SERVER> It's a draw" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'P' && (userInput == "s" || userInput == "S")) {
						cout << "SERVER> You Win! +1 Point" << endl;
						points++;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else if (buf[44] == 'R' && (userInput == "s" || userInput == "S")) {
						cout << "SERVER> You Lose!" << endl;
						cout << "You have " << points << " Points" << endl << endl;
					}
					else {
						cout << "SERVER> Nothing happened..." << endl;
						cout << "You have " << points << " Points" << endl;
					}
				}
				if (points == 3) {
					cout << "SERVER> You Win the Whole Game!" << endl;
					system("pause");
					closesocket(sock);
					WSACleanup();
				}
			}
		}
	
	} while (userInput.size() > 0);

	// Gracefully close down everything
	closesocket(sock);
	WSACleanup();

}

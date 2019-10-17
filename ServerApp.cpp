// ServerApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    std::cout << "Starting server...\n";
	// Server side step:
	// 1.WSAStartup
	// 2.Create soket
	// 3.Bind socket
	// 4.Listenning
	// 5.Accept
	// 6.Communication client - server.......
	// 7.WSACleanUp

	// 1. WSAStartup: Load winsock library
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 2. Create socket
	// 2.1. AF_INET: IPv4
	// 2.2. SOCK_STREAM: TCP/IP
	//		SOCK_DGRAM: UDP/IP
	// 2.3. IPPROTO_TCP: TCP
	//		IPPROTO_UDP: UDP
	SOCKET udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	// 3. Bind socket
	SOCKADDR_IN udpAddress;
	int port = 9900;
	udpAddress.sin_family = AF_INET;
	udpAddress.sin_port = htons(port);
	udpAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	sizeof(USHORT);
	sizeof(IN_ADDR);
	bind(udpSocket, (SOCKADDR*)&udpAddress, sizeof(udpAddress));

	// 4. Listenning
	listen(udpSocket, 5);

	// 5. Accept a new connection when one arrives
	SOCKADDR_IN clientAddress;
	int clientAddressLength;
	SOCKET newUdpSocket;
	newUdpSocket = accept(udpSocket, (SOCKADDR*)&clientAddress, &clientAddressLength);
	if (newUdpSocket == INVALID_SOCKET)
	{
		std::cout << "Connect failed" << std::endl;
	}
	
	// 6.Communication Server-Client

	// Close socket
	closesocket(newUdpSocket);
	closesocket(udpSocket);

	// 7. WsaCleanUp
	WSACleanup();
}

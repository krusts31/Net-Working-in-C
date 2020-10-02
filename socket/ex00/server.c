#include <sys/types.h> 
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int	main()
{
	char			server_message[256] = "\nCongrats You have reach the Server\n\n";
	bzero(server_message, sizeof(server_message));
	memcpy(server_message, "\nCongrats You have reach the Server\n\n", strlen("\nCongrats You have reach the Server\n\n"));
	int			server_socket;
	struct	sockaddr_in	server_address;
	int			fd_bind;
	int			client_socket;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("192.128.1.218");	//any address on the local machine

	fd_bind = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	if (fd_bind == -1)
	{
		printf("bind failed! SERVER SIDE\n");
		return (-1);
	}
	listen(server_socket, 1);
	client_socket = accept(server_socket, NULL, NULL);
	send(client_socket, server_message, sizeof(server_message), 0);
	close(server_socket);
	return (0);
}

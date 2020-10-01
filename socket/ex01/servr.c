#include <sys/types.h> 
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int	main()
{
	char			server_message[256] = {0};
	int			server_socket;
	struct	sockaddr_in	server_address = {0};
	int			fd_bind;
	socklen_t		len;

//	bzero(server_message, sizeof(server_message));
//	memcpy(server_message, "\nCongrats You have reach the Server\n\n", strlen("\nCongrats You have reach the Server\n\n"));
	server_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_socket == -1)
	{
		printf("Error: %s\n", "Failed to create socket");
		return (-1);
	}
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;	//any address on the local machine

	fd_bind = bind(server_socket, (const struct sockaddr*) &server_address, sizeof(server_address));
	if (fd_bind == -1)
	{
		printf("bind failed! SERVER SIDE\n");
		close(server_socket);
		return (-1);
	}

	len = recvfrom(server_socket, (char *) server_message, 256, MSG_WAITALL, 0, &len);
	printf("this is len: %d\nthis is message: %s\n", len, server_message);
	close(server_socket);
	return (0);
}


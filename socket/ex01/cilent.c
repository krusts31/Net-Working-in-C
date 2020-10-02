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
	int			fd_socket;
	struct	sockaddr_in	server_address = {0};
	int			len;
	char			recived_message[256];

	bzero(recived_message, sizeof(recived_message));
	memcpy(recived_message, "LETS GO UDP", strlen("LETS GO UDP"));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("192.168.1.218");
	fd_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd_socket == -1)
	{
		printf("Failed to create a socket\n");
		return (-1);
	}
	len = sendto(fd_socket, (const char *)recived_message, strlen(recived_message), 0, (const struct sockaddr *)&server_address, sizeof(server_address));
	if (len == -1)
		printf("Message not sent\n");
	close(fd_socket);
	return (0);
}

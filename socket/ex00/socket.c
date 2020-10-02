#include <sys/types.h> 
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

//	int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
//      int socket(int domain, int type, int protocol);

int	main()
{
	int			fd_socket;
	struct	sockaddr_in	server_address;
	int			connect_status;
	char			recived_message[256];
	bzero(recived_message, sizeof(recived_message));

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("192.168.1.218");
	fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
		printf("Failed to create a socket\n");
	connect_status = connect(fd_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connect_status)
	{
		printf("Connections failed!\n");
		return (-1);
	}
	recv(fd_socket, &recived_message, sizeof(recived_message), 0);
	printf("Recived message: %s\n", recived_message);
	close(fd_socket);
	return (0);
}

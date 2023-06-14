#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

	
	char bye[]="GoodBye";
	
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	// send the message
	int check=0;
	int n=10;
	while(n>0)
	{
		char server_message[256];
		char buf[200];
		recv(client_socket, &buf, sizeof(buf), 0);
		printf("\n %s \n", buf);
		check=0;
		for(int i=0;i<7;i++)
			{
				if(buf[i]==bye[i]||buf[i]==bye[i]+32||buf[i]==bye[i]-32)
				{	
					
				}
				else 
				{
					check=0;
					break;
				}
				check=1;
				break;
			}
		if(check==1)
		break;
		printf("Me: ");
		fgets(server_message,50, stdin);
		//scanf("%[^\n]%*c", server_message);
		//scanf("%s", server_message);
		send(client_socket, server_message, strlen(server_message), 0);
		check=0;
		for(int i=0;i<7;i++)
			{
				if(server_message[i]==bye[i]||server_message[i]==bye[i]+32||server_message[i]==bye[i]-32)
				{	
					
				}
				else 
				{
					check=0;
					break;
				}
				check=1;
				break;
			}
		if(check==1)
		break;
	}

	// close the socket
	close(server_socket);
	
	return 0;
}

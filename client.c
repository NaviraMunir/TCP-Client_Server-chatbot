#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
int main() {
	
	
	char bye[]="GoodBye";
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	int check=0;
	int n=10;
	while(n>0)
	{
		
		char request[256];
		char buf[200];
		printf("Me: ");
		fgets(request, 50, stdin);
		//scanf("%s", request);
		//scanf("%[^\n]%*c",request);
		send(sock, request, strlen(request), 0);
		check=0;
		for(int i=0;i<7;i++)
		{
			if(request[i]==bye[i]||request[i]==bye[i]+32||request[i]==bye[i]-32)
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
		recv(sock, &buf, sizeof(buf), 0);
		listen(sock,0);
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
	}
	
	close(sock);

	return 0;
}


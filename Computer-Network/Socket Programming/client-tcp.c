// TCP client and server connection using select function

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8080
int main() {
	int sockfd, newfd;
	struct sockaddr_in server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("Socket Creation Failed\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
		printf("Connection with the Server Failed\n");
	char message[50], recvmessage[50];
	printf("Enter the Message: ");
	scanf("%[^\n]s", message);
	send(sockfd, message, sizeof(message), 0);
	int k = recv(sockfd, recvmessage, sizeof(recvmessage), 0);
	recvmessage[k] = '\0';
	printf("Message Received from Server: %s\n", recvmessage);
  return 0;
}

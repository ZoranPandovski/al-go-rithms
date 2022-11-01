// TCP client and server connection using select function

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/select.h>
#define PORT 8085
#define BACKLOG 10
int main() {
	int sockfd, newfd;
	struct sockaddr_in server, client;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("Socket Creation Failed\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	int b = bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr));
	if (b == -1)
		printf("Socket Binding Failed\n");
	if (listen(sockfd, BACKLOG) < 0)
		printf("Server Listening Failed\n");
	fd_set allfd, readfd;
	FD_ZERO(&allfd);
	FD_SET(sockfd, &allfd);
	int i = 0, j, maxfd, fd[10];
	maxfd = sockfd + 1;
	struct timeval timeout;
	timeout.tv_sec = 10;
	timeout.tv_usec = 5;
	char message[50], recvmessage[50];
	int s = sizeof(client);
	while (1) {
		readfd = allfd;
		select(maxfd, &readfd, NULL, NULL, &timeout);
		if (FD_ISSET(sockfd, &readfd)) {
			fd[i] = accept(sockfd, (struct sockaddr *)&client, &s);
			FD_SET(fd[i], &allfd);
			if (fd[i] >= maxfd)
				maxfd = fd[i] + 1;
			i++;
		}
		for (j = 0; j < i; j++) {
			if (FD_ISSET(fd[j], &readfd)) {
				int k = recv(fd[j], recvmessage, sizeof(recvmessage), 0);
				if (k == 0) {
					close(fd[j]);
					FD_CLR(fd[j], &allfd);
				}
				else {
					recvmessage[k] = '\0';
					printf("Message Received from Client: %s\n", recvmessage);
					printf("Enter the Message: ");
					scanf("%[^\n]s", message);
					send(fd[j], message, sizeof(message), 0);
				}
			}
		}
	}
	return 0;
}

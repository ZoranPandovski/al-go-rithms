// // A program in C using TCP where the server handles multiple clients in sequential communication (minimum 2 clients).

#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
int main(){
	struct sockaddr_in addr,cliaddr;
	addr.sin_family=AF_INET;
	addr.sin_port=5050;
	addr.sin_addr.s_addr=INADDR_ANY;
	char buf[]="    hello22222";
	int s=socket(AF_INET,SOCK_DGRAM,0);
        int len;
	sendto(s,buf,strlen(buf),0,(struct sockaddr *)&addr,sizeof(addr));
}

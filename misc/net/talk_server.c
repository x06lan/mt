#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> //Server – simples.c, gcc simples.c -o simples -lunp

int main(int argc , char *argv[]){
	char receMessage[256];
	char message[256] = {"Sorry.\n"};
	char text[100] = "112/12/28";
	int sockfd = 0, clientSockfd = 0; //socket的建立
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if (sockfd == -1){ printf("Fail to create a socket."); }
	struct sockaddr_in serverInfo,clientInfo; //socket的連線
	int addrlen = sizeof(clientInfo);
	bzero(&serverInfo,sizeof(serverInfo));
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = INADDR_ANY;
	serverInfo.sin_port = htons(atoi(argv[2]));
	bind(sockfd,(struct sockaddr *)&serverInfo,sizeof(serverInfo));
	listen(sockfd, 8);
	char end[]="bye";
	while(1){
		clientSockfd = accept(sockfd,(struct sockaddr*) &clientInfo, &addrlen);
		while (1) {
			printf("waiting\n");
			recv(clientSockfd, receMessage, sizeof(receMessage),0);
			printf("client:%s \n",receMessage);
			if (strcmp(receMessage,end)==0)
				break;

			printf("input:");
			scanf("%s",text);
			// if (strcmp(text,end)==0)
			// 	break;
			send(clientSockfd, text, sizeof(message),0);
			printf("sended\n");
			if (strcmp(text,end)==0)
				break;
		}
		if (strcmp(receMessage,end)==0)break;
		if (strcmp(text,end)==0)break;
	}
	printf("close\n");
	return 0;
}

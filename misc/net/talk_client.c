#include <stdio.h> // Client – simplec.c
#include <stdlib.h> // gcc simplec.c -o simplec -lunp
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc , char *argv[]) {
	char message[256], receiveMessage[256]; //Send/receive a message to server;
	int sockfd = 0; //socket的建立
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if (sockfd == -1){ printf("Fail to create a socket."); }
	struct sockaddr_in info; //socket的連線
	bzero(&info,sizeof(info));
	info.sin_family = PF_INET;
	info.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost test
	info.sin_port = htons(atoi(argv[2]));
	int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	if(err==-1){ printf("Connection error"); }
	char end[]="bye";

	while (1) {
		printf("input:");
		scanf("%s", message);
		send(sockfd, message, sizeof(message),0);
		if (strcmp(message,end)==0) break;

		printf("waiting:\n");
		recv(sockfd, receiveMessage, sizeof(receiveMessage),0);
		printf("Server: %s\n", receiveMessage);
		if (strcmp(receiveMessage,end)==0) break;
	}
	printf("close Socket\n");
	close(sockfd);
	return 0;
}

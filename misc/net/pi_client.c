#include <stdio.h> // Client – simplec.c
#include <stdlib.h> // gcc simplec.c -o simplec -lunp
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc , char *argv[]) {
	//char message[256], receiveMessage[256]; //Send/receive a message to server;
	float rec=2.0;
	float sended=100.0;
	int sockfd = 0; //socket的建立
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if (sockfd == -1){ printf("Fail to create a socket."); }
	struct sockaddr_in info; //socket的連線
	bzero(&info,sizeof(info));
	info.sin_family = PF_INET;
	info.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost test
	info.sin_port = htons(8700);
	int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	if(err==-1){ printf("Connection error"); }
	int count=0;
	while (count<2) {
		printf("send %lf\n",sended);
		send(sockfd, &sended, sizeof(sended),0);

		printf("waiting:\n");

		recv(sockfd, &rec, sizeof(rec),0);
		printf("rec: %lf\n", rec);
		count++;
	}
	printf("close Socket\n");
	close(sockfd);
	return 0;
}

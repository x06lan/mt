#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> //Server – simples.c, gcc simples.c -o simples -lunp

int main(int argc , char *argv[]){
	char receMessage[256];
	float rec=1.0;
	float sended=1.0;
	char message[] = {"Sorry.\n"};
	char text[100] = "";
	int sockfd = 0, clientSockfd = 0; //socket的建立
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if (sockfd == -1){ printf("Fail to create a socket."); }
	struct sockaddr_in serverInfo,clientInfo; //socket的連線
	int addrlen = sizeof(clientInfo);
	bzero(&serverInfo,sizeof(serverInfo));
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = INADDR_ANY;
	serverInfo.sin_port = htons(8700);
	bind(sockfd,(struct sockaddr *)&serverInfo,sizeof(serverInfo));
	listen(sockfd, 8);
	int count=0;
	//while(1){
		clientSockfd = accept(sockfd,(struct sockaddr*) &clientInfo, &addrlen);
		while (count<2) {
			printf("waiting\n");

			recv(clientSockfd, &rec, sizeof(rec),0);
			printf("rec:%lf \n",rec);
			sended=0.0;
			for(int i=1;i<(int)rec;i++){
				float temp= 1/(float)(i*2-1);
				if(i%2==0)
					temp*=-1;
				printf("%lf\n",temp);
				sended+=temp;
			}
			sended*=4;

			send(clientSockfd, &sended, sizeof(sended),0);
			printf("sended %lf\n",sended);
			count++;
		}
	//}
	printf("close\n");
	return 0;
}

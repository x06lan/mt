#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define UDP_TEST_PORT 50001
#define bsize 256
void w(char *buffer){
}
int main(int argC, char* arg[]) {
	struct sockaddr_in addr;
	int sockfd, len = 0;
	int addr_len = sizeof(struct sockaddr_in);
	char buffer[bsize];
/* 建立socket，注意必須是SOCK_DGRAM */
	if ((sockfd=socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror ("socket");
		exit(1);
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(UDP_TEST_PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY) ;// 接收任意IP
	/* 綁定socket */
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr))<0) {
		perror("connect");
		exit(1);
	}
	FILE *f;
	char fname[]="rece_file.jpg";
	f=fopen(fname,"w");
	long long int left;
	while(1) {
		len = recvfrom(sockfd, &left, sizeof(left), 0,
		(struct sockaddr *)&addr ,&addr_len);
		printf("rec int:%d \n",left);
		if(left<=0)
			break;
		/* 顯示client端的網路位址和收到的字串消息 */
		// printf("%d\n",len);
		// printf("from %s ,Received : %s\n",
		// inet_ntoa(addr.sin_addr), buffer);
		/* 將收到的字串消息回給client端 */
		len = recvfrom(sockfd, buffer, sizeof(buffer), 0,
		(struct sockaddr *)&addr ,&addr_len);
		printf("send\n");
		// printf("send chat %s:\n",buffer);
		sendto(sockfd,&left, sizeof(left), 0, (struct sockaddr *)&addr, addr_len);
		if(left>=sizeof(buffer))
			left=sizeof(buffer);
		fwrite(buffer, left,1,f);
	}
	fclose(f);
	return 0;
}


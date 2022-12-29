#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define UDP_TEST_PORT 50001
#define UDP_SERVER_IP "127.0.0.1"
#define bsize 256
unsigned long fsize(char* file) {
	FILE * f = fopen(file, "r");
	fseek(f, 0, SEEK_END);
	unsigned long len = (unsigned long)ftell(f);
	fclose(f);
	return len;
}
int main(int argC, char* arg[]){
	struct sockaddr_in addr;
	int sockfd; 
	int addr_len = sizeof(struct sockaddr_in);
	char buffer[bsize];
	/* 建立socket，注意必須是SOCK_DGRAM */
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(UDP_TEST_PORT);
	addr.sin_addr.s_addr = inet_addr(UDP_SERVER_IP);
	// char fname[123];
	char *fname=arg[2];
	FILE *f;
	// len=fsize(fname);
	f=fopen(fname,"rb");
	fseek(f, 0, SEEK_END);
	long long int len = 0;
	long long int check = 0;
	len = (unsigned long)ftell(f);
	fseek(f, 0, SEEK_SET);
	while(1) {
		
		sendto(sockfd, &len, sizeof(len), 0, (struct sockaddr *)&addr, addr_len);
		printf("send int %lld:\n",len);
		if(len<=0)
			break;
		// memset(buffer,0, sizeof(buffer));
		fread(buffer, sizeof(buffer),1,f);

		// printf("send:%s\n",buffer);
		sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, addr_len);
		// printf("send char %s:\n",buffer);
		printf("send char\n");
		check = recvfrom(sockfd,&check , sizeof(check), 0,
				(struct sockaddr *)&addr, &addr_len);
		len-=sizeof(buffer);
		
	}
	fclose(f);
	return 0;
}

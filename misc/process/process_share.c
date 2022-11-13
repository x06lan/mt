#include <sys/types.h> // sf1.c
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define KEY 567
typedef unsigned char byte;
byte * getBytes(float *pValue) {
byte *p = (byte *)(pValue);
return p;
}
float* getValue(byte *pValue) {
	float *p=(float  *)(pValue);
	return p;
}
int main() {
	pid_t pid=fork();
	int status,tem, value=0;
	int *v=&value;
	if(pid== 0) {
		int shm_id;
		key_t key;
		char *shm, *s;
		byte *p,*p1;
		float k = 17.62513782;
		float j = 3;
		if ((shm_id = shmget(KEY, sizeof(float)*4, IPC_CREAT | 0666)) < 0) {
			perror("shmget");
			printf("creat fail");
			exit(1);
		}
		if ((shm = shmat(shm_id, NULL, 0)) == (char*) - 1) {
			perror("shmat");
			printf("attach fail");
			exit(1);
		}
		p = getBytes(&k);
		p1 = getBytes(&j);
		s = shm;
		for (int i=0; i<4; i++) {
			s[i] = p[i];
			s[i+4] = p1[i];
		}
	}
	else {
		pid = wait(&status);
		int tem= WEXITSTATUS(status);

		int shm_id;
		key_t key;
		char *shm, *s;
		byte *p=malloc(sizeof(byte)*4);
		byte *p1=malloc(sizeof(byte)*4);
		if ((shm_id = shmget(KEY, sizeof(float)*4, IPC_CREAT | 0666)) < 0) {
			perror("shmget");
			printf("creat fail");
			exit(1);
		}
		if ((shm = shmat(shm_id, NULL, 0)) == (char*) - 1) {
			perror("shmat");
			printf("attach fail");
			exit(1);
		}
		s = shm;
		for (int i=0; i<4; i++) {
			p[i] = s[i];
			p1[i] = s[i+4];
		}
		float *v=getValue(p);
		float *v1=getValue(p1);
		printf("%lf\n",*v+*v1);
		
	}
	return 0;
}

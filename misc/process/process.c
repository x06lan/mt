#include <stdio.h> // f2.c
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	pid_t pid=fork();
	int status,tem, value=0;
	int *v=&value;
	if(pid== 0) {
		printf("child process pid =%d\n", getpid());
		for(int i=31;i<=60;i++){
			(*v)+=i;
		}

		printf("%d\n",*v);
		close(*v);
	}
	else {
		sleep(1);
		pid = wait(&status);
		tem= WEXITSTATUS(status);
		printf("%d\n",*v);
		printf("%d\n",tem);
	}
	return 0;
}

#include <sys/types.h> // f1.c
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

//
//1
//1 fork
//1 \
//1  \
//1   1
//1   1 fork
//1 \ 1
//1 1 1

int main() {
	pid_t pid;
	pid = fork(); //fork a child process
	int status=0;
	int *tem=&status;
	int wa=1500;
	if (pid < 0) { // error occurred
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { // child process
		printf("pid:%d\n",pid);
		pid_t pid1;
		pid1 = fork(); //fork a child process
		if(pid1==0)
		printf("pid:%d %d\n",pid,pid1);
		else{
			wait(NULL); // parent wait child complete
			printf("pid:%d %d\n",pid,pid1);
		}

	}
	else { // parent process
		wait(NULL); // parent wait child complete
		printf("pid:%d\n",pid);
	}
	return 0;
}


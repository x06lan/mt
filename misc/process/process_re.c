#include <sys/types.h> // f1.c
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void count_pi(int s, int e, float *v) {
  for (int i = s; i <= e; i++) {
    float tem = 2 * i + 1;
    float t = 1 / tem;
    if (i % 2 == 1) {
      t = t * -1;
    }
    *v += t;
  }
}
int main() {
	pid_t pid;
	pid = fork(); //fork a child process
	int status=0;
	int *tem=&status;
	int wa=1500;
	struct timespec te1;
	clock_gettime(CLOCK_REALTIME, &te1);
	if (pid < 0) { // error occurred
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { // child process
		printf("child pid:%d\n",pid);
		float v=0;
		count_pi(0,100000000,&v);
		FILE *fptr;
		fptr = fopen("tem.txt","w+");
		fprintf(fptr,"%lf",v);
		fclose(fptr);

	}
	else { // parent process
		wait(NULL); // parent wait child complete
        int vv= WIFEXITED(status);
		printf("pid:%d\n",pid);
		double v=10;
		FILE *fptr ;
		fptr = fopen("tem.txt","r");
		//fread(&v, sizeof(int), 1, fptr); 
		fscanf(fptr,"%lf",&v);
		printf("v:%lf\n",v*4);
		fclose(fptr);

		struct timespec te2;
		clock_gettime(CLOCK_REALTIME, &te2);
		printf("%lf ms\n", (float)(te2.tv_sec - te1.tv_sec)*1000+(te2.tv_nsec - te1.tv_nsec)/1000000);
	}
	return 0;
}


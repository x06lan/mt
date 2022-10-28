#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // f1.c
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

//
// 1
// 1
// 1 \ fork
//                                                                             1
//                                                                                                      \
//1   1
// 1   1
// 1 \ 1 fork
// 1 1 1

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
  time_t t;
  int status;

  if ((pid = fork()) < 0)
    perror("fork() error");
  else if (pid == 0) {
    // sleep(5);
    struct timeval te;
    gettimeofday(&te, NULL); // get current time

    float v = 0;
    count_pi(31, 60, &v);

    struct timeval te2;
    gettimeofday(&te2, NULL); // get current time
    printf("%lf\n", (float)(te2.tv_usec - te.tv_usec) / 1000);
    // printf("%lf\n", v * 200);

    _exit(v * 200);
  } else
    do {
      if ((pid = waitpid(pid, &status, WNOHANG)) == -1)
        perror("wait() error");
      else if (pid == 0) {
        time(&t);
        sleep(1);
      } else {
        int v = WIFEXITED(status);
        float vv = (float)v / 200;
        struct timeval te;
        gettimeofday(&te, NULL); // get current time

        count_pi(0, 30, &vv);
        struct timeval te2;
        gettimeofday(&te2, NULL); // get current time
        printf("%lf\n", (float)(te2.tv_usec - te.tv_usec) / 1000);

        printf("child exited with status of %lf\n", vv * 4);
      }
    } while (pid == 0);
}

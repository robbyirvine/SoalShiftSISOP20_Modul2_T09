#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
pid_t pid, sid;

pid = fork();
 
switch (pid) {

case pid < 0:
  exit(EXIT_FAILURE);

case pid > 0:
  exit(EXIT_SUCCESS);
}

umask(0);

sid = setsid();

switch (sid) {
case sid < 0:
  exit(EXIT_FAILURE);

case chdir("/home/shempaque/Documents/Linux2") < 0:
  exit(EXIT_FAILURE);
}

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);


if(argc != 5){
printf("error");
return 0;
}

int s;
int m;
int h;

s = 0;
m = 0;
h = 0;

if(strcmp(argv[1], "*") != 0){ s = atoi(argv[1]); if(s > 59 || s < 0){printf("tidak sesuai detik");return 0;}}
if(strcmp(argv[2], "*") != 0){ m = atoi(argv[2]); if(m > 59 || m < 0){printf("tidak sesuai menit");return 0;}}
if(strcmp(argv[3], "*") != 0){ h = atoi(argv[3]); if(h > 59 || h < 0){printf("tidak sesuai jam");return 0;}}

while(1){
time_t t;
struct tm* ptm;

t = time(NULL);
ptm = localtime(&t);

if((h == ptm->tm_hour || h == 0) && (m == ptm->tm_min || m == 0) && (s == ptm->tm_sec || s == 0)) {
if (fork()==0)
execl("/bin/bash", "bash", argv[5], NULL);}
sleep(1);
}
}

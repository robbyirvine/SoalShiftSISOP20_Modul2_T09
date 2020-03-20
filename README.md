# SoalShiftSISOP20_Modul2_T09

Nama Anggota: 
  - Robby Irvine Surya    05311840000026
  - Widyantari Febiyanti  05311840000030

## Soal 1
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

Ketentuan:

  A. Program menerima 4 argumen berupa :
  
  Ketentuan A (i, ii, iii dan iv)
  
    i. Detik: 0-59 atau * (any value)
    ii. Menit: 0-59 atau * (any value)
    iii. Jam: 0-23 atau * (any value)
    iv. Path file .sh
  B. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai

  C. Program hanya menerima 1 config cron

  D. Program berjalan di background (daemon)

  E. Tidak boleh menggunakan fungsi system()

## Penyelesaian: 
Source Code: 
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
   pid_t pid, sid;
   int s,m,h;

   pid = fork();

 if (pid < 0) {
   exit(EXIT_FAILURE);
 }

 if (pid > 0) {
   exit(EXIT_SUCCESS);
 }

 umask(0);

 sid = setsid();
 if (sid < 0) {
   exit(EXIT_FAILURE);
 }
 if ((chdir("/home/shempaque/Documents/Linux2")) < 0) {
  exit(EXIT_FAILURE);
 }


 close(STDIN_FILENO);
 close(STDOUT_FILENO);
 close(STDERR_FILENO);


   if(argc != 5){
   	printf("error");
   	return 0;
   }
   
   d = 0;
   m = 0;
   j = 0;
   
   if(strcmp(argv[1], "*") != 0){ s = atoi(argv[1]); if(s > 59 || s < 0){printf("tidak sesuai detik");return 0;}} 
   if(strcmp(argv[2], "*") != 0){ s = atoi(argv[2]); if(s > 59 || s < 0){printf("tidak sesuai menit");return 0;}} 
   if(strcmp(argv[3], "*") != 0){ s = atoi(argv[3]); if(s > 23 || s < 0){printf("tidak sesuai jam");return 0;}} 
   
   while(1){
   	time_t t;
   	struct tm* ptm;
   	
   	t= time(NULL);
   	ptm = localtime(at);
   	
   	if((h == ptm->tm_hour || h == 0) && (m == ptm->tm_min || m == 0) && (s == ptm->tm_sec || s == 0)) {
   		if (fork()==0)
   		execl("/bin/bash", "bash", argv[4], NULL);)
   		sleep(1);
   	}
   }
	   }
   }
   ```

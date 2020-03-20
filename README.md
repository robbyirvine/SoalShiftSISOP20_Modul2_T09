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
- ``` int main(int argc, char** argv``` adalah main fungsi dari program. fungsi perintah  ```argc``` sebagai parameter bertipe int dan berfungsi untuk menunjukkan banyaknya parameter yang digunakan. 
Sedangkan untuk ```argv``` berfungsi untuk menyimpan parameter apa saja yang digunakan (dalam bentuk array). 
- selanjutnya adalah membuat **Daemon**. Pembuatan daemon sesuai dengan modul yang telah dipublikasikan yaitu: 
``` 
pid_t pid, sid;
   int s,m,h;

   pid = fork();

 if (pid < 0) {
   exit(EXIT_FAILURE);
 }

 if (pid > 0) {
   exit(EXIT_SUCCESS);
   
   }
   ```
   
- Memiliki fungsi yaitu untuk membuat sebuah parent process dan memunculkan child process dengan melakukan ```fork()```. Kemudian membunuh parent process agar sistem mengira proses telah selesai. 

``` umask(0); ``` 
- Memiliki fungsi yaitu untuk mengatur akses permission agar file bisa ditulis dan dibaca. 

``` sid = setsid();
 if (sid < 0) {
   exit(EXIT_FAILURE);
```
- Memiliki fungsi membuat **Unique Session ID (SID)** untuk mendapatkan **SID** menggunakan perintah ```setsid()```. perintah itu akan menjalankan perintah ```fork()```. 
``` 
if ((chdir("/home/shempaque/Documents/Linux2")) < 0) {
  exit(EXIT_FAILURE);
```
- Selanjutnya adalah memindahkan proses Daemon kesuatu directory yang ada. Untuk mengubahnya menggunakan perintah ```chdir()```. 

```
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
```
- Proses Daemon adalah proses yang berjalan di background secara otomatis. Oleh karena itu harus menutup file yang tidak diperlukan agar tidak menggunakan terminal yang digunakan. 
```STDIN``` (standar input) berfungsi untuk menutup/ mencegah membaca data dari I/O.
```STDOUT``` (standar output) berfungsi untuk menutup/mencegah menampilkan I/O ke layar.
```STDERR``` (standar error) berfungsi untuk menutup/mecegah menampilkan pesan error ke layar. 

``` 
if(argc != 5){
   	printf("error");
   	return 0;
```
- Sesuai dengan yang diminta, kita harus memasukkan 5 argumen (1 argumen diawal untuk memanggil program yang dibuat. Selanjutnya adalah sesuai dengan detik, menit, jam dan nama file yang ingin dijalankan). Apabila argumen yang diinputkan ```if(argc !=5)``` maka akan muncul **error**.  

``` 
d = 0;
m = 0;
j = 0;
```
- inisiasi awal argumen dari detik ```d```, menit ```m```, jam ```j```. 

``` 
if(strcmp(argv[1], "*") != 0){ s = atoi(argv[1]); if(s > 59 || s < 0){printf("tidak sesuai detik");return 0;}} 
if(strcmp(argv[2], "*") != 0){ s = atoi(argv[2]); if(s > 59 || s < 0){printf("tidak sesuai menit");return 0;}} 
if(strcmp(argv[3], "*") != 0){ s = atoi(argv[3]); if(s > 23 || s < 0){printf("tidak sesuai jam");return 0;}} 
```
- Selanjutnya adalah untuk menjalankan program. Untuk ```argv[1]``` yaitu untuk mendapatkan nilai detik. menggunakan perintah ```strcmp``` adalah perintah yang berfungsi untuk membandingkan dua buah string. Sesuai dengan perintah, input bisa berupa ```detik: 0-59``` atau ```* (any value)```. 
``` atoi``` berfungsi untuk mengonversi nilai string menjadi bilangan bertipe integer. Range yang diminta untuk detik yaitu ```if(s > 59 || s < 0)``` dari 0-59. ```printf("tidak sesuai detik")``` akan menampilkan **tidak sesuai detik** apabila input yang dimasukkan tidak sesuai range yang diberikan. 

- Untuk ```argv[2]``` yaitu untuk mendapatkan nilai menit. menggunakan perintah ```strcmp``` adalah perintah yang berfungsi untuk membandingkan dua buah string. Sesuai dengan perintah, input bisa berupa ```menit: 0-59``` atau ```* (any value)```. 
``` atoi``` berfungsi untuk mengonversi nilai string menjadi bilangan bertipe integer. Range yang diminta untuk detik yaitu ```if(m > 59 || m < 0)``` dari 0-59. ```printf("tidak sesuai menit")``` akan menampilkan **tidak sesuai menit** apabila input yang dimasukkan tidak sesuai range yang diberikan. 

- Untuk ```argv[3]``` yaitu untuk mendapatkan nilai jam. menggunakan perintah ```strcmp``` adalah perintah yang berfungsi untuk membandingkan dua buah string. Sesuai dengan perintah, input bisa berupa ```jam: 0-23``` atau ```* (any value)```. 
``` atoi``` berfungsi untuk mengonversi nilai string menjadi bilangan bertipe integer. Range yang diminta untuk detik yaitu ```if(j > 23 || j < 0)``` dari 0-23. ```printf("tidak sesuai detik")``` akan menampilkan **tidak sesuai jam** apabila input yang dimasukkan tidak sesuai range yang diberikan. 

```
while(1){
time_t t;
struct tm* ptm;
   	
t= time(NULL);
ptm = localtime(at);
```
- Pada ```while(1)``` adalah perintah looping karena daemon akan bekerja dalam waktu tertentu. 
- Perintah ```time_t t;``` untuk menyimpan waktu saat ini dalam variabel t. 
- Perintah ```struct tm* ptm``` untuk melakukan pointer ke ```ptm``` yang berisikan localtime yang akan mengonversi nilai dalam variabel t ke waktu yang digunakan sistem (localtime). 
	

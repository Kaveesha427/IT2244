// write process1

#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SHM_SIZE 1024 // size of shared memory segment

int main(){
	
	key_t key = ftok("shmfile",11010);//genarate unique key
	int shmid = shmget(key,SHM_SIZE,IPC_CREAT | 0666);//CREATE SHARE MEMORY SEGMENT
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL,0);//attach to share memory
	if(shmaddr == (char*) -1) {
		perror("shmat");
		exit(1);
	}
	printf("Write date:");
	fgets(shmaddr,SHM_SIZE,stdin);//write data to shared memory
	
	printf("DAta written in memmory:%s\n",shmaddr);
	
	shmdt(shmaddr); //Detach from shared memory
	return 0;
	
}


//reader

#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SHM_SIZE 1024 // size of shared memory segment

int main(){
	
	key_t key = ftok("shmfile",11010);//genarate unique key
	int shmid = shmget(key,SHM_SIZE,IPC_CREAT | 0666);//CREATE SHARE MEMORY SEGMENT
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL,0);//attach to share memory
	if(shmaddr == (char*) -1) {
		perror("shmat");
		exit(1);
	}
	printf("Data read from memory :%s\n",shmaddr);
	shmdt(shmaddr); // Detach from shared memory
	
	shmctl(shmid,IPC_RMID,NULL);//remove shared memory segment
	return 0;
	
}

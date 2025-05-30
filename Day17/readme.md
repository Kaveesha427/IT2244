<h1>🌳Wait(),exit(),sleep() functions</h1>
<h3>Activity 1</h3>
<pre>
  #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("Program Started!.\n");
	
	printf("Sleeping for 3 seconds...\n");
	sleep(3);
	
	printf("Exiting the program.\n");
	exit(0);
return 0;
}
</pre>


![1](https://github.com/user-attachments/assets/c337a608-1007-4317-b7d2-fe94ac620ef5)

<h3>Activity 2</h3>
<pre>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	
	printf("Parent Process Started. PID: %d\n", getpid());
	
	pid = fork();
	
	if (pid<0){
		perror("Fork Failed!");
		exit(1);
	}
	
	if (pid==0){
		printf("Child Process. PID: %d, sleeping for 2 seconds...\n");
		sleep(2);
		printf("Child Process exiting.\n");
		exit(0);
	}
	else{
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
		}
		else{
			printf("Child did not exit normally\n");
		}
		printf("Parent process ending.\n");
	}
return 0;
}

</pre>


![2](https://github.com/user-attachments/assets/4da9e559-eb70-44b9-abe9-26a04d8ffaa6)

<h3>exercise1</h3>

![3 0](https://github.com/user-attachments/assets/2d7dfd82-cc69-464a-88b7-ffad1abe88a9)

<h3>exercise2</h3>

![3](https://github.com/user-attachments/assets/01dbcffd-86e1-4f94-aa20-3863c7644ac7)

<h3>exercise3</h3>

![5](https://github.com/user-attachments/assets/03fe71ea-5610-483d-b000-003fdea40965)

<ptre>
The wait, exit, and sleep functions are important for process management and synchronization:

🟢wait() is used by a parent process to pause its execution until one of its child processes finishes. It helps manage the order and control of processes.

🟢exit() is used by a process to terminate its execution and return a status code to the operating system. It signals that the process is done.

🟢sleep() temporarily stops a process for a specified amount of time without ending it. It is useful for delays and timing control.
</pre>

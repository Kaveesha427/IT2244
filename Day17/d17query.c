//activity1

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


//Activity2

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

exercise1:

/*First Child: Slept for 1 second
Second Child : Slept for 3 seconds
Parent : Both children have finished.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid, pid1;
	pid = fork();
	
	if (pid<0){
		perror("Fork Failed!");
		exit(1);
	}
	
	if (pid==0){
		sleep(1);
		printf("First Child: Slept for 1 second.\n");
		exit(0);
	}
	else{
		pid1 =fork();
		if (pid1==0){
		sleep(2);
		printf("Second Child: Slept for 1 second.\n");
		exit(0);
		}
		else{
			int status, status1;
			waitpid(pid,&status);
			waitpid(pid1,&status1);	
			if(WIFEXITED(status) && WIFEXITED(status1)){
				printf("Parent : Both children have finished.");
			}
		}
	}
return 0;
}


exercise2:

/*Exercise 02:
First child: sleeps for 2 seconds, exits with status 2.
Second child: sleeps for 1 seconds, exits with status 1.
Parent: waits twice, and prints which child (by PID or exit code) finished first snd second.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); // Create first child

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child process
        printf("First child process. PID: %d, sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child exiting with status 2.\n");
        exit(2);
    }

    pid2 = fork(); // Create second child

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child process
        printf("Second child process. PID: %d, sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("Second child exiting with status 1.\n");
        exit(1);
    }

    // Parent process
    for (int i = 0; i < 2; ++i) {
        pid_t finished_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Child with PID %d exited with status %d\n", finished_pid, WEXITSTATUS(status));
        } else {
            printf("Child with PID %d did not exit normally.\n", finished_pid);
        }
    }

    printf("Parent process ending.\n");
    return 0;
}



/*Exercise 03: 
The parent creates a child process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status 2.
the child waits for the grandchild, prints its exit status,
then exits with status 55.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    child_pid = fork(); // Parent creates child

    if (child_pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // In child process
        printf("Child process started. PID: %d\n", getpid());

        grandchild_pid = fork(); // Child creates grandchild

        if (grandchild_pid < 0) {
            perror("fork failed");
            exit(1);
        }

        if (grandchild_pid == 0) {
            // In grandchild process
            printf("Grandchild process started. PID: %d, sleeping 2 seconds...\n", getpid());
            sleep(2);
            printf("Grandchild process exiting with status 2.\n");
            exit(2);
        } else {
            // Child waits for grandchild
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Child: Grandchild exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Child: Grandchild did not exit normally.\n");
            }
            printf("Child process exiting with status 55.\n");
            exit(55);
        }
    } else {
        // Parent waits for child
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not exit normally.\n");
        }
        printf("Parent process ending.\n");
    }

    return 0;
}









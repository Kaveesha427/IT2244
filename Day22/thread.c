#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/*A normal  c function that is executed as a thread
when it name is specified in pthread_create()*/



void  *helloworld(void *vargb)
{
	sleep(1);
	printf("Hello world \n");
	return NULL;
	
	}
	
	int main(){
	
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id,NULL,helloworld,NULL);
	pthread_join(thread_id,NULL);
	printf("After thread\n");
	exit(0);
	
	}
	

//Multi threaded proces

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//function to be executed by the thread
void *print_message(void *arg){
	char* message = (char*)arg;
	printf("%s\n",message);
	return NULL;
}

int main(){
	pthread_t thread1,thread2;
	
	//create first thread
	pthread_create(&thread1,NULL,print_message, "Hello from thread 1!");
	
	//create second thread
	pthread_create(&thread2,NULL,print_message, "Hello from thread 2!");
	
	//wait for both thread to finish
	
	pthread_join(thread1,NULL);//untill thread 1 printing the hello from thread 1 thread 2 waited.
	pthread_join(thread2,NULL);
	
	printf("Both thread completed \n");
	return 0;
	
}
	
	
//output

Hello from thread 1!
Hello from thread 2!
Both thread completed


//exercise 1
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//function to be executed by the thread
void *print_message(void *arg){
	char* message = (char*)arg;
	printf("%s\n",message);
	return NULL;
}

int main(){
	pthread_t threads[3];
	char* messages[] = {
		"thread 1 says hi!",
		"thread 2 says hello!",
		"thread 3 says hey!",
		
	};		
	
	//create  threads
	for(int i=0;i<3;i++){
	pthread_create(&threads[i],NULL,print_message, messages[i]);
	}
	
	
	//wait for threads to finish
	for(int i=0;i<3;i++){
	pthread_join(threads[i],NULL);
	}
	
	printf("all threads are completed \n");
	return 0;
	
}

//output
thread 1 says hi!
thread 3 says hey!
thread 2 says hello!
all threads are completed

//exercise2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 6

int arr[SIZE] = {1, 2, 3, 4, 5, 6};
int sum1 = 0, sum2 = 0;

// Function to sum first half
void *sum_part1(void *arg) {
    for (int i = 0; i < SIZE / 2; i++) {
        sum1 += arr[i];
    }
    return NULL;
}

// Function to sum second half
void *sum_part2(void *arg) {
    for (int i = SIZE / 2; i < SIZE; i++) {
        sum2 += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, sum_part1, NULL);
    pthread_create(&t2, NULL, sum_part2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Print total sum
    printf("Total sum = %d\n", sum1 + sum2);

    return 0;
}





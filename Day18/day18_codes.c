//send
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

//structure for message queue

struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}
message;
int main(){
	key_t key;
	int msgid;
	
	//ftok to genarate unique key
	
	key = ftok("progfile",65);
	
	//msgget creates a message queue
	//and returns identifiier
	
	msgid=msgget(key,0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Write Data :");
	fgets(message.mesg_text,MAX,stdin);
	
	//msgsnd to send message
	msgsnd(msgid,&message,sizeof(message),0);
	
	//display the message
	printf("DAta send is : %s \n", message.mesg_text);
	return 0;
	
}


//recieve
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//structure for message queue

//structure for message queue

	struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}
message;
int main(){
	key_t key;
	int msgid;
	
	//ftok to genarate unique key
	
	key = ftok("progfile",65);
	
	//msgget creates a message queue
	//and returns identifiier
	
	msgid=msgget(key,0666 | IPC_CREAT);
	
	//msgrcv to recieve message
	msgrcv(msgid,&message,sizeof(message),1,0);
	
	
	//display the message
	printf("DAta recieved is : %s \n", message.mesg_text);
	
	//to destroy the message queue
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
	
}


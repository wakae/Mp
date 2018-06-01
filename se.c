#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
int true = 1;

struct msg_queue
{
	long msg_type;
	char msg_text[100];
} msg;

int main(){
	key_t key;
	int msg_id;

	
	key = ftok("message passing",65);

	
	msg_id = msgget(key,0666 |IPC_CREAT);
	msg.msg_type = 1; 
	while(true){
	printf("Insert Text:\n");
	
	char mes = fgets(msg.msg_text,sizeof(msg.msg_text),stdin);
	
	msgsnd(msg_id,&msg,sizeof(msg),0);

	
	printf("data sent is :  %s\n",msg.msg_text );
}
	return 0;
}

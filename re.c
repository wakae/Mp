#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

int true = 1;
struct msg_queue
{
	long msg_type;
	char msg_text[200];
} msg;

int main(){
	key_t  key;
	int msg_id;

	key = ftok("message passing",65);

	msg_id = msgget(key,0666 | IPC_CREAT);
	while(true){
	
	msgrcv(msg_id,&msg,sizeof(msg),1,0);


	
	printf("data Received is:%s\n",msg.msg_text );
}
	
	msgctl(msg_id,IPC_RMID,NULL);

	return 0;
}

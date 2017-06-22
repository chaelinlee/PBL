#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "client.h"
#include "msgbuf.h"

void client() {
	key_t key = msgget(8504, IPC_CREAT|0666);
	struct msgbuf msg;
	char text[100];
	int n,keys;
	if (key < 0) {
		perror("error ");
		exit(0);
	}

	

	while (1) {
		printf("1)put(key,value), 2)get(key) 3)delete(key) 중 하고 싶은 일을 입력하세요. ");
		scanf("%d",&n);

		if(n==1){
			msg.mtype = 1;
			printf(">>key를 입력하세요.");
			scanf("%d",&keys);
			printf(">>value를 입력하세요.");
			scanf("%s",text);

			msg.info.key = keys;
			strcpy(msg.info.value, text);
			
		}else if(n==2) {
			msg.mtype = 2;
			printf(">> 찾고자하는 key를 입력하세요.");
			scanf("%d",&keys);
			msg.info.key = keys;

		}else if(n ==3){
			msg.mtype = 3; 
			printf(">> 지우고자 하는 key를 ")
		}
		
		
		//printf("client send: %s\n", msg.mtext);
		if (msgsnd(key, &msg, sizeof(struct msgbuf) - sizeof(long), 0) < 0) {
			perror("error ");
			exit(0);
		}

		sleep(1);
	}
}
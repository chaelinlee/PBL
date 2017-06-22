#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "server.h"
#include "msgbuf.h"
#include "LinkedList.h"

void server() {
	key_t key = msgget(8504, IPC_CREAT|0666);
	struct msgbuf msg;
	struct linkedList *L= createNode();
	

	if (key < 0) {
		perror("error ");
		exit(0);
	}

	while (1) {
		if(msg.mtype==1){
			//넣는건뎅
			printf("타입이 1이다앙!");
			insertNode(L,msg.info.key,msg.info.value);
			printNode(L);

		}
		if (msgrcv(key, &msg, sizeof(struct msgbuf) - sizeof(long), 0, 0) < 0) {
			perror("error ");
			exit(0);
		}

		printf("server: %d%s\n", msg.info.key,msg.info.value );
	}
}


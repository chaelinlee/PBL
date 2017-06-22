#include <stdio.h>
#include <unistd.h>
#include "server.h"
#include "client.h"

int main(){

	if(fork() == 0){
		client(); 
	}else{
		server();
	}

}
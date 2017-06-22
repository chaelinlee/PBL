struct client_info {
	unsigned int key;
	char value[100];
};


struct msgbuf 
{ 
    long mtype;             // 메시지 타입 
    char mtext[100];  // 보내고자 하는 데이터
    struct client_info info; 
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc,char *argv[]){
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len=0;			//存有读取的总字节数
	int idx=0, read_len=0;	

	if(argc != 3){	// nc 127.0.0.1 port
		printf("Usage : %s <IP> <port>\n",argv[0]);
		exit(1);
	}

	sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock == -1){
		error_handling("socket() error");
	}
	
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;						// 协议族
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);		// IP地址
	serv_addr.sin_port = htons(atoi(argv[2]));			// 端口号

	if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) == -1){
		error_handling("connect() error\r\n");
	}
	
	while( read_len = read(sock,&message[idx++],1) ){		// 一次只读 1 字节，读到末尾时read返回 0
		if( read_len == -1 )
			error_handling("read() error!");
		
		str_len += read_len;
	
	}

	printf("Message from server : %s \n",message);
	printf("Function read call count: %d \n", str_len);	//存有读取的总字节数

	close(sock);
	return 0;
}

void error_handling(char *message){
	fputs(message,stderr);
	fputs("\n",stderr);
	exit(1);
}

// 客户端

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 30;
void error_handling( char *message );

int main( int argc, char *argv[]){
	int sock;
	struct sockaddr_in recv_adr;
	if(argc != 3){
		printf("Usage : %s <IP> <PORT>\n",argv[0]);
		exit(1);
	}
	
	sock = socket( PF_INET, SOCK_STREAM, 0);
	memset( &recv_adr, 0, sizeof(recv_adr));
	recv_adr.sin_family = AF_INET;
	recv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	recv_adr.sin_port = htons( atoi(argv[2]));
	
	if( connect( sock, (struct sockaddr*)&recv_adr, sizeof(recv_adr) ) == -1 ){
		error_handling( "connect error!\n" );
	}
	
	write( sock, "123", strlen("123") );
	sleep(2);
	send( sock, "4", strlen("4"), MSG_OOB );
	sleep(2);
	write( sock, "5667", strlen("5667") );
	sleep(2);
	send( sock, "892", strlen("892"), MSG_OOB );
	sleep(2);
	
	close(sock);

	return 0;
}

void error_handling(char *message){
	fputs( message, stderr);
	fputc( '\n', stderr );
	exit(1);
}
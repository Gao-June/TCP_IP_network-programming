#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1000

void error_handing( char* message );

int main(void){
	int fd;
	char buf[BUF_SIZE];
	
	fd = open("data1.txt", O_RDONLY);
	if( fd == -1){
		error_handing("open() error!");
	}
	printf("file descriptor: %d\n", fd);

	if(read( fd, buf, sizeof(buf)) == -1){
		error_handing("read() error!");
	}
	printf("file data: %s\n", buf);
	close(fd);

	return 0;
}

void error_handing(char* message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handing( char* message );

int main(){
	int fd;
	char buf[] = "hello world!\n";

	fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);	//必要时创建文件、只写打开、删除全部现有数据
	if( fd == -1){
		error_handing("open() error!");	
	}

	printf("file descriptor: %d \n",fd);

	if( write(fd, buf, sizeof(buf)) == -1 ){
		error_handing("write() error!");
	}

	close(fd);

	return 0;
}
	
void error_handing(char* message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}



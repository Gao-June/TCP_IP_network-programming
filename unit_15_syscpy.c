// 使用系统自带的读写函数 read()、write()

#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 10

int main( int argc, char *argv[]){
	int fd1, fd2;
	int len;
	char buf[BUF_SIZE];
	
	fd1 = open("news.txt", O_RDONLY );	//只读打开
	fd2 = open("cpy.txt", O_WRONLY | O_CREAT | O_TRUNC);	//只写打开，必要时创建文件，清空已有数据
	
	while( ( len = read(fd1, buf, sizeof(buf)) ) > 0 ){
		write(fd2, buf, len);
	}
	
	close(fd1);
	close(fd2);

	return 0;
}


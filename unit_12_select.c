//select() 函数调用示例

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 30

int main( int argc, char* argv[]){
	fd_set reads, temps;
	int result, str_len;
	char buf[BUF_SIZE];
	struct timeval timeout;
	
	FD_ZERO(&reads);	// reads 所有位初始化
	FD_SET(0, &reads);	// 给第0位注册信息
	
	while(1){
		temps = reads;
		timeout.tv_sec = 5;		//超时时间设为 5s
		timeout.tv_usec = 0;
	
		result = select( 1, &temps, 0, 0, &timeout );	//监视1位，temps中的
		if(result == -1){
			puts("select() error");
			break;
		}
		else if(result == 0){
			puts(" Time-out\n");
		}
		else{
			if(FD_ISSET( 0, &temps )){		//temps 的第0号位信息有变化
				str_len = read(0, buf, BUF_SIZE);
				buf[str_len] = 0;
				printf("message from console: %s", buf);
			
			}
		}
		
				
	}
		
	
	return 0;
}



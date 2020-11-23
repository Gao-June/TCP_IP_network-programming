// 验证僵尸进程
// 在 fork() 后程序会先运行子进程然后父进程。
// 在本程序中，父进程 sleep(30); 在这个过程中子进程未被回收，而成为了僵尸进程。
// 在 这30s 过程中，打开一个新的终端 ps aux 在 sta栏内会看到一个进程的状态为 Z+, 就是此僵尸进程。

#include <stdio.h>
#include <unistd.h>

int main( int argc, char* argv[] ){
	pid_t pid = fork();
	
	if(pid == -1){
		printf(" fork err!\n ");
	}
	else if( pid == 0 ){
		printf(" I am child process!\n ");
	}
	else{
		printf(" I am parent!  my child ID is : %d\n ", pid);
		sleep(30);
	}
	
	//end
	if( pid==0 ){
		puts("end child process!");
	}
	else{
		puts("end parent process!");
	}
	

	return 0;
}




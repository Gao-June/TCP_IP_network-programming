// 使用标准 I/O 函数 fgets()、fputs()

#include <stdio.h>

#define BUF_SIZE 10

int main( int argc, char *argv[]){
	FILE *fp1;		// 保存在 fp1 中的是 FILE 结构体指针
	FILE *fp2;		// 保存在 fp2 中的是 FILE 结构体指针
	char buf[BUF_SIZE];
	
	

	fp1 = open("news.txt", "r");	//读
	fp2 = open("cpy.txt", "w");		//写
	
	while( fgets(fp1, buf, sizeof(buf)) != NULL ){
		fputs(buf, fp2);
	}
	
	close(fp1);
	close(fp2);

	return 0;
}



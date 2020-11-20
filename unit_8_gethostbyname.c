#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

void error_handling(char *message);

int main(int argc, char *argv[]){
    int i;
    struct hostent *host;

    if(argc != 2){
	printf("Usage : %s <addr> \n",argv[0]);
	exit(1);
    }

    host = gethostbyname(argv[1]);

    if(!host){
	error_handling("gethostbyname error");
    }

    printf("Official name: %s \n",host->h_name);	//官方域名
    
    for(i=0;host->h_aliases[i];i++){	//用这种循环退出的方式是因为 struct hostent 独特的结构，指针元素最后一个是NULL
    	printf("Aliases %d: %s \n",i+1,host->h_aliases[i]);		//其它域名
    }

    printf("Address type : %s \n",(host->h_addrtype == AF_INET)?"AF_INET":"AF_INET6");	// IP类型

    for(i=0;host->h_addr_list[i];i++){
	printf("IP addr %d:%s \n", i+1,inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));	// IP
			// 这里两个 * 要好好理解。
			// 第二个* 是因为 host->h_addr_list[i] 是 *struct in_addr 类型。
			// 然后，第一个 * 是因为要取 host->h_addr_list[i]的内容
    }
    
    return 0;
}

void error_handling(char *message){
    fputs(message,stderr);
    fputs("\n",stderr);
    exit(1);
}

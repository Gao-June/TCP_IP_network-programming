#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

void error_handling(const char *message);

int main(int argc,char *argv[])
{
  int sock;
  int send_buf, recv_buf, state;
  socklen_t len;
  
  sock = socket( PF_INET, SOCK_STREAM, 0 );
  len=sizeof(send_buf);  
  state=getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void *)&send_buf,&len);
  if(state)
      error_handling("getsockopt() error!\n");

  len=sizeof(recv_buf);  
  state=getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(void *)&recv_buf,&len);
  if(state)
      error_handling("getsockopt() error!\n");
 
  printf("Input buff size: %d \n",recv_buf);
  printf("Output buff size: %d \n",send_buf);
  return 0;
}

void error_handling(const char *message){  
  
    fputs(message,stderr);  
    fputs("\n",stderr);  
    exit(1);  
}

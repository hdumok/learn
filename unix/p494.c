/*
 * =====================================================================================
 *
 *       Filename:  p494.c
 *    Description:  
 *        Created:  2015年05月27日 19时41分47秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include "p488.c"
#define BUFLEN 128
//extern int connect_retry(int,int,int,const struct sockaddr*,socklen_t);
void print_uptime(int sockfd)
{
	int n;
	char buf[BUFLEN];
	while((n=recv(sockfd,buf,BUFLEN,0))>0)
		write(STDOUT_FILENO,buf,n);
	if(n<0)
		err_sys("recv error");
}
int main(int argc,char *argv[])
{
	struct addrinfo *ailist,*aip;
	struct addrinfo hint;
	int sockfd,err;
	if(argc!=2)
		err_sys("input error");
	memset(&hint,0,sizeof(hint));
	hint.ai_socktype=SOCK_STREAM;
	hint.ai_canonname=NULL;
	hint.ai_addr=NULL;
	hint.ai_next=NULL;
	if((err=getaddrinfo(argv[1],"ruptime",&hint,&ailist))!=0)
		err_quit("geraddrinfo error");
	for(aip=ailist;aip!=NULL;aip=aip->ai_next)
	{
		if((sockfd=connect_retry(aip->ai_family,SOCK_STREAM,0,aip->ai_addr,aip->ai_addrlen))<0)
			err_sys("sockfd error");
		else
		{
			print_uptime(sockfd);
			exit(0);
		}
	}
	err_exit(err,"cannot connect to %s",argv[1]);
}

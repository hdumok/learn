/*
 * =====================================================================================
 *
 *       Filename:  p497.c
 *    Description:  
 *        Created:  2015年05月28日 08时11分55秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#define BUFLEN 128
#define QLEN 10
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

int initserver(int type,const struct sockaddr* addr,socklen_t alen,int qlen)
{
	int sockfd;
	int err;
	if((sockfd=socket(addr->sa_family,type,0))<0)
		return -1;
	if(bind(sockfd,addr,alen)<0)
		goto errout;//连接失败
	if(type=SOCK_STREAM||type==SOCK_SEQPACKET)
		if(listen(sockfd,qlen)<0)
			goto errout;//监听失败
	return(sockfd);
errout:
	err=errno;
	close(sockfd);
	errno=err;
	return(-1);
}
void serve(int sockfd)
{
	int clfd,status;
	pid_t pid;
	set_cloexec(sockfd);
	while(1)
	{
		if((clfd=accept(sockfd,NULL,NULL))<0)
		{
			syslog(LOG_ERR,"ruptimed:accept error:%s",strerror(errno));
			exit(1);
		}
		if((pid=fork())<0)
		{	
			syslog(LOG_ERR,"ruptimed:fork error:%s",strerror(errno));
			exit(1);
		}
		else if(pid==0)
		{
			if(dup2(sockfd,STDIN_FILENO)!=STDIN_FILENO||dup2(sockfd,STDOUT_FILENO!=STDOUT_FILENO))
			{
				syslog(LOG_ERR,"ruptimed:unexpected error");
				exit(1);
			}
			close(clfd);
			execl("/usr/bin/uptime","uptime",(char*)0);
			syslog(LOG_ERR,"ruptimed:unexpected retrun from exec:%s",strerror(errno));
		}
		else
		{
			close(clfd);
			waitpid(pid,&status,0);
		}
	}
}

int main(int argc,char* argv[])
{
	struct addrinfo *ailist,*aip;
	struct addrinfo hint;
	int sockfd,err,n;
	char *host;
	if(argc!=1)
		err_sys("usage:ruptimed");
	if((n=sysconf(_SC_HOST_NAME_MAX))<0)
		n=HOST_NAME_MAX;
	if((host=(char*)malloc(n))==NULL)
		err_sys("malloc error");
	if(gethostname(host,n)<0)//获得本主机的名字
		err_sys("gethostname error");
	daemonize("ruptimed");
	memset(&hint,0,sizeof(hint));
	hint.ai_flags=AI_CANONNAME;
	hint.ai_socktype=SOCK_STREAM;
	hint.ai_canonname=NULL;
	hint.ai_addr=NULL;
	hint.ai_next=NULL;
	if((err=getaddrinfo(host,"ruptimed",&hint,&ailist))!=0)//获得指定主机指定端口的信息，主要时地址信息
	{
		syslog(LOG_ERR,"ruptimed:getaddrinfo error:%s",gai_strerror(err));
		exit(1);
	}
	for(aip=ailist;aip!=NULL;aip=aip->ai_next)
	{
		if((sockfd=initserver(SOCK_STREAM,aip->ai_addr,aip->ai_addrlen,QLEN))>=0)//用获得的地址 端口信息 创建套接子绑定端口 开始监听
			serve(sockfd);//获取对方的连接请求 新建套接子处理该请求，并获取本机时间信息 发送给客户端
		exit(0);
	}
	exit(1);
}

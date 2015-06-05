/*
 * =====================================================================================
 *
 *       Filename:  p483.c
 *    Description:  
 *        Created:  2015年05月20日 13时45分49秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#if defined(SOLARIS)
#include <netinet/in.h>
#endif
#include <netdb.h>
#include <arpa/inet.h>
#if defined(BSD)
#include <sys/socket.h>
#include <netinet/in.h>
#endif

void print_family(struct addrinfo* aip)
{
	printf("family:");
	switch(aip->ai_family)
	{
		case AF_INET:
			printf("AF_INET");
			break;
		case AF_INET6:
			printf("AF_INET6");
			break;
		case AF_UNIX:
			printf("AF_UNIX");
			break;
		case AF_UNSPEC:
			printf("AF_UNSPEC");
			break;
		default:
			printf("unknown family");
	}
	printf("\n");
}
void print_type(struct addrinfo* aip)
{
	printf("socktype:");
	switch(aip->ai_socktype)
	{
		case SOCK_STREAM:
			printf("SOCK_STREAM");
			break;
		case SOCK_DGRAM:
			printf("SOCK_DGRAM");
			break;
		case SOCK_SEQPACKET:
			printf("SOCK_SEQPACKET");
			break;
		case SOCK_RAW:
			printf("SOCK_RAM");
			break;
		default:
			printf("unknown socktype");
	}
	printf("\n");
}
void print_protocol(struct addrinfo* aip)
{
	printf("protocol:");
	switch(aip->ai_protocol)
	{
		case 0:
			printf("default");
			break;
		case IPPROTO_TCP:
			printf("IPPROTO_TCP");
			break;
		case IPPROTO_UDP:
			printf("IPPROTO_UDP");
			break;
		case IPPROTO_RAW:
			printf("IPPROTO_RAM");
			break;
		default:
			printf("unknown protocol");
	}
	printf("\n");
}
void print_flags(struct addrinfo* aip)
{
	printf("flags:");
	if(aip->ai_flags==0)	
		printf("0");
	else
	{
		if(aip->ai_flags&AI_PASSIVE)
			printf("passive");
		if(aip->ai_flags&AI_CANONNAME)
			printf("canon");
		if(aip->ai_flags&AI_NUMERICHOST)
			printf("numhost");
		if(aip->ai_flags&AI_NUMERICSERV)
			printf("numserv");
		if(aip->ai_flags&AI_V4MAPPED)
			printf("v4mapped");
		if(aip->ai_flags&AI_ALL)
			printf("all");
	}
	printf("\n");
}


int main ( int argc, char *argv[] )
{
	struct addrinfo *ailist=NULL,*aip=NULL;
	struct addrinfo hint;
	struct sockaddr_in *sinp;
	const char *addr;
	int err;
	char abuf[INET_ADDRSTRLEN];

	if(argc!=3)
		err_quit("usage:%s nodename service",argv[0]);
	hint.ai_flags=AI_CANONNAME;
	hint.ai_family=0;
	hint.ai_socktype=0;
	hint.ai_protocol=0;
	hint.ai_addrlen=0;
	hint.ai_addr=NULL;
	hint.ai_canonname=NULL;
	hint.ai_next=NULL;

	if((err=getaddrinfo(argv[1],argv[2],&hint,&ailist))!=0)
		err_quit("getaddrinfo error:%s",gai_strerror(err));
	for(aip=ailist;aip!=NULL;aip->ai_next)
	{
		print_flags(aip);
		print_family(aip);
		print_type(aip);
		print_protocol(aip);
		printf("\nhost: %s\n",aip->ai_canonname?aip->ai_canonname:"-");
		if(aip->ai_family==AF_INET)
		{
			sinp=(struct sockaddr_in*)aip->ai_addr;
			addr=inet_ntop(AF_INET,&sinp->sin_addr,abuf,INET_ADDRSTRLEN);
			printf("address: %s\n",addr?addr:"unknown");
			printf("port: %d\n",ntohs(sinp->sin_port));
		}
		printf("\n");
	}
	exit(0);	
}				

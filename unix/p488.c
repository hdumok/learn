/*
 * =====================================================================================
 *
 *       Filename:  p488.c
 *    Description:  
 *        Created:  2015年05月27日 19时30分12秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int domin,int type,int protocol,const struct sockaddr* addr,socklen_t alen)
{
	int numsec,fd;
	for(numsec=1;numsec<=MAXSLEEP;numsec<<1)
	{
		if((fd=socket(domin,type,protocol))<0)
			return(-1);
		if(connect(fd,addr,alen)==0)
			return(fd);//如果连接成功就返回描述符
		close(fd);
		if(numsec<=MAXSLEEP/2)
			sleep(numsec);
	}

}

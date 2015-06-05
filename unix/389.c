/*
 * =====================================================================================
 *
 *       Filename:  389.c
 *    Description:  
 *        Created:  2015年05月13日 13时13分33秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <errno.h>
#include <fcntl.h>

char buf[500000];
int main()
{
	int ntowrite,nwrite;
	char* ptr;
	ntowrite=read(STDIN_FILENO,buf,sizeof(buf));
	fprintf(stderr,"read %d bytes\n",ntowrite);
	set_fl(STDOUT_FILENO,O_NOBLOCK);
	ptr=buf;
	while(ntowrite>0)
	{
		errno=0;
		nwrite=write(STDOUT_FILENO,ptr,ntowrite);
		fprintf(stderr,"nwrite=%d,errno=%d\b",nwrite,errno);
		if(nwrite>0)
		{
			ptr+=nwrite;
			ntowrite-=nwrite;
		}
	}
	clr_fl(STDOUT_FILENO,O_NOBLOCK);
	exit(0);
}


/*
 * =====================================================================================
 *
 *       Filename:  p58.c
 *    Description:  
 *        Created:  2015年05月02日 15时06分35秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h"

int main ( int argc, char *argv[] )
{
	int  n;
	char buf[4096];
	while((n=read(STDIN_FILENO,buf,4096))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	if(n<0)
		err_sys("read error");
	exit(0);	
}				


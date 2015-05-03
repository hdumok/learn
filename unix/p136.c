/*
 * =====================================================================================
 *
 *       Filename:  p136.c
 *    Description:  
 *        Created:  2015年05月03日 15时33分19秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <errno.h>
void make_temp(char* template);
int main ( int argc, char *argv[] )
{
	char good[]="/tmp/dirXXXXXX";
	char *bad="/tmp/dirXXXXXX";
	printf("good:\n");
	make_temp(good);

	printf("bad:\n");
	make_temp(bad);
	exit(0);	
}				
void make_temp(char* template)
{
	int fd;
	struct stat statbuf;
	if((fd=mkstemp(template))<0)
		err_sys("mkstemp error");
	printf("template=%s\n",template);
	close(fd);
	
	if(stat(template,&statbuf)<0)
	{	
		if(errno==ENOENT)
			err_sys("file not exit");
		else
			err_sys("stat error");
	}
	else
	{
		printf("file exit\n");
		unlink(template);
	}
}

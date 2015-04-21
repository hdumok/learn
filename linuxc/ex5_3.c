/*
 * =====================================================================================
 *
 *       Filename:  ex5_3.c
 *
 *    Description:  :x:
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 17时53分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int rfd,wfd;
char c;
int i=0;
int pid;
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("input error\n");
		return 1;
	}	
	if((rfd=open(argv[1],O_RDONLY))==-1)
	{
		printf("open error\n");
		return 2;
	}
	if((wfd=creat(argv[2],0666))==-1)
	{
		printf("creat error\n");
		return 3;
	}
	pid=fork();
	while(1)
	{
		printf("%d\n",++i+pid);
		if(read(rfd,&c,1)!=1)
			return 4;
		write(wfd,&c,1);
	}
	return 0;
}

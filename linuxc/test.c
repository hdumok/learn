/*
 * =====================================================================================
 *
 *       Filename:  test.c

 *
 *        Version:  1.0
 *        Created:  2015年04月20日 21时51分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
	int i;fd;
	char buf[1000];
	for(i=0;i<100;i++)
		buf[i]='\0';
	fd=open("./ex5_6.c",0);
	read(fd,buf,1000);
	printf("test output:\n\s\n",buf);
}

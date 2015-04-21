/*
 * =====================================================================================
 *
 *       Filename:  ex5_6.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 21时42分13秒
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
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
int main()
{
	int fd;
	char buf[10];
	fd=open("./test.c",0);
	read(fd,buf,10);
	printf(" main output: \n%s\n",buf);
	execl("./test","./test",0);
	printf("exec error\n");
}

/*
 * =====================================================================================
 *
 *       Filename:  p67.c
 *    Description:  
 *        Created:  2015年05月02日 16时05分46秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <fcntl.h>

int main ( int argc, char *argv[] )
{
	int val;
	if(argc!=2)
		err_quit("uasge:a.out <descriptor#>");
	
	if((val=fcntl(atoi(argv[1]),F_GETFL,0))<0)
		err_sys("fcntl error");

	printf("O_ACCMODE=%ld",O_ACCMODE);
	switch(val&O_ACCMODE)
	{
		case O_RDONLY:
			printf("O_RDONLY");
			break;
		case O_WRONLY:
			printf("O_WRONLY");
			break;
		case O_RDWR:
			printf("O_RDWR");
			break;
		default:
			err_dump("unknown mode");
	}
	if(val&O_APPEND)
		printf("O_APPEND\n");
	if(val&O_SYNC)
		printf("O_SYNC\n");
	if(val&O_NONBLOCK)
		printf("O_NONBLOCK\n");
	putchar('\n');

	exit(0);	
}				


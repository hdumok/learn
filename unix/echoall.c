/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 15时03分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int main ( int argc, char *argv[] )
{
	int i;
	char **ptr;
	extern char **environ;
	for(i=0;i<argc;i++)
		printf("argv[%d]=%s\n",i,argv[i]);
	for(ptr=environ;*ptr!=0;ptr++)
		printf("environ=%s\n",*ptr);
	exit(0);
	exit(0);	
}				

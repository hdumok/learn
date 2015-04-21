/*
 * =====================================================================================
 *
 *       Filename:  ex5_4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 20时49分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int global=4;
int main()
{
	pid_t pid;
	int i=5;
	if((pid=vfork())<0)
		return 1;
	else if(pid==0)
	{
		global++;
		i--;
		printf("child time pid=%d \n",pid);
		_exit(0);
	}
	else
		printf("parent time pid=%d \n",pid);
	printf("\n\nglobal=%d\ni=%d\n ",global,i);
	return 0;
}


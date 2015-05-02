/*
 * =====================================================================================
 *
 *       Filename:  p9.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 14时30分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <sys/wait.h>
int main(void)
{
	char buf[4096];
	pid_t pid;
	int status;
	printf("%%");
	while(fgets(buf,4096,stdin)!=NULL)
	{
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;//gets函数的结尾时\n 

		if((pid=fork())<0)
			err_sys("fork error");
		else if(pid==0)
		{
			execlp(buf,buf,(char*)0);//接受的buf必须以NULL结尾
			err_ret("conld not execute: %s",buf);
			exit(126);
		}
		if((pid=waitpid(pid,&status,0))<0 )
			err_sys("wait error");
		printf("%%");
	}
	exit(0);
}


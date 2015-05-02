/*
 * =====================================================================================
 *
 *       Filename:  p15.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 15时26分37秒
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
static void sig_int(int);
int main(void)
{
	char buf[4096];
	pid_t pid;
	int status;
	
	if(signal(SIGINT,sig_int)==SIG_ERR)//如果发送消息操作自身都失败了
		err_sys("signal error");
	
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
void sig_int(int signo)
{
	printf("it's sig_int\n");
}

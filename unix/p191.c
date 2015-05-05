/*
 * =====================================================================================
 *
 *       Filename:  p191.c
 *    Description:  
 *        Created:  2015年05月04日 12时31分18秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <sys/wait.h>

void pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal exit status=%d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal exit status=%d\n",WTERMSIG(status));
	else if(WIFSTOPPED(status))
		printf("stoped signed number=%d\n",WSTOPSIG(status));
}
int main()
{
	pid_t pid;
	int status;

	if((pid=fork())<0)
		err_sys("pid error");
	else if(pid==0)
		exit(7);
	if(wait(&status)!=pid)
		err_sys("wait error");
	pr_exit(status);

	if((pid=fork())<0)
		err_sys("pid error");
	else if(pid==0)
		abort();//异常退出  SIGABRT信号
	if(wait(&status)!=pid)
		err_sys("wait error");
	pr_exit(status);

	if((pid=fork())<0)
		err_sys("pid error");
	else if(pid==0)
		status/=0;//除0 硬件错误信号
	if(wait(&status)!=pid)
		err_sys("wait error");
	pr_exit(status);
}

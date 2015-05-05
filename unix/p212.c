/*
 * =====================================================================================
 *
 *       Filename:  p212.c
 *    Description:  
 *        Created:  2015年05月04日 20时06分59秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
int system(const char* cmdstring)
{
	pid_t pid;
	int status;

	if(cmdstring==NULL)
		return(1);

	if((pid=fork())<0)
		status=-1;//system对fork函数失败返回-1
	else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmdstring,(char*)0);
		_exit(127);//只有execl载入程序失败，才会运行到这一行，否则后免得一切代码都无效
	}
	else
	{
		while(waitpid(pid,&status,0)<0)
		if(errno!=EINTR)//waitpid返回除EINTR以外的错误，status都设置为-1
		{
			status=-1;
			break;
		}
	}
	return(status);

}
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
	int status;
	
	if((status=system("date"))<0)
		err_sys("system error1");

	pr_exit(status);

	if((status=system("nosuchcommand"))<0)
		err_sys("system error2");
	pr_exit(status);

	if((status=system("who;exit 44"))<0)
		err_sys("system error3");
	pr_exit(status);
	exit(0);
}



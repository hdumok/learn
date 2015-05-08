/*
 * =====================================================================================
 *
 *       Filename:  p295.c
 *    Description:  
 *        Created:  2015年05月07日 21时04分22秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
int system(const char* cmdstring)
{
	pid_t pid;
	iny status;
	struct sigaction ignore,saveintr,savequit;
	sigset_t chldmask,savemask;

	if(cmdstring==NULL)
		return(1);
	ignore.sa_handler=SIG_IGN;
	sigemptyset(&ignore.sa_mask);//sa_masks是一个信号急，在调用响应函数之前，该屏蔽信号集被响应函数屏蔽
	ignore.sa_flags=0;
	if(sigaction(SIGINT,&ignore,&saveintr)<0)
		return(-1);
	if(sigaction(SIGQUIT,&ignore,&savequit)<0)//把SIGINT SIGQUIT 信号的动作都改为忽视，并且不屏蔽任何信号
		return(-1); //因为实际上父子进程都会收到信号

	sigemptyset(&chldmask);
	sigaddset(&chldmask,SIGCHLD);
	if(sigprocmask(SIG_BLOCK,&chldmask,&savemask)<0)//设置进程屏蔽SIGCHLD信号
		return(-1);
	if((pid=fork())<0)
		status=-1;
	else if(pid==0)
	{
		sigaction(SIGINT,&saveintr,NULL);//让子进程捕捉信号，调用信号响应函数
		sigaction(SIGQUIT,&savequit,NULL);
		sigprocmask(SIG_SETMASK,&savemask,NULL);
		
		execl("/bin/sh","sh","-c",cmdstring,(char*)0);
		_exit(127);//如果程序装载成功是不会执行到这的
	}
	else
	{
		while(waitpid(pid,&status,0)<0)
			if(errno!=EINTR)
			{
				status=-1;
				break;
			}
		
	}
	/* 最后恢复父进程的消息响应和信号屏蔽 */
	if(sigaction(SIGINT,&saveintr,NULL)<0)
		return(-1);
	if(sigaction(SIGQUIT,&savequit,NULL)<0)
		return(-1);
	if(sigprocmask(SIG_SETMASK,&savemask,NULL)<0)
		return(-1);
	return(status);
}

/*
 * =====================================================================================
 *
 *       Filename:  p292.c
 *    Description:  
 *        Created:  2015年05月07日 20时25分32秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void abort()
{
	sigset_t mask; //信号屏蔽子类型
	struct sigaction action;//sigaction函数使用的动作数据类型

	sigaction(SIGABRT,NULL,&action);//获取现在的动作数据
	if(action.sa_handler==SIG_IGN)
	{
		action.sa_handler=SIG_DFL;
		sigaction(SIGABRT,&action,NULL);//设置新动作，ABRT信号响应为默认
	}
	if(action.sa_handler==SIG_DFL)
		fflush(NULL); //ABRT信号如果使用默认响应，那就先刷出缓冲
	sigfillset(&mask);//屏蔽字屏蔽所有信号
	sigdelset(&mask,SIGABRT);//删除对ABRT信号的屏蔽
	sigprocmask(SIG_SETMASK,&mask,NULL);//设置信号屏蔽字

	kill(getpid(),SIGABRT);
	//进入了SIGABRT响应函数
		
	fflush(NULL);//如果响应函数返回了，可能在缓冲区产生了一些数据

	/*以上如果响应函数是默认则没关系，如果不是默认接下来改为默认再确定一遍 */
	action.sa_handler=SIG_DFL;//强制修改原来的信号动作为默认

	sigactio(SIGABRT,&action,NULL);
	sigprocmask(SIG_SETMASK,&mask,NULL);
	kill(getpid(),SIGABRT);//再次调用响应函数，这次肯定调用默认的响应函数
	exit(1);
	
	
}


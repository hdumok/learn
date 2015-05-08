/*
 * =====================================================================================
 *
 *       Filename:  p274.c
 *    Description:  
 *        Created:  2015年05月06日 15时13分59秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <signal.h>
#include <errno.h>

//#define SIGBAD(signo) ((signo)<=0||(signo)>=NSIG)  //信号不合范围

#define SIGBAD(signo) ((signo)<=0)  //信号不合范围
int sigaddset(sigset_t *set,int signo)
{
	if(SIGBAD(signo))
	{
		errno=EINVAL;
		return(-1);
	}
	*set |=1<<(signo-1);//该处运行错误，原因不明
	return(0);
}
int sigdelset(sigset_t *set,int signo)
{
	if(SIGBAD(signo))
	{
		errno=EINVAL;
		return(-1);
	}
	*set &=~(1<<(signo-1));
	return(0);
}
int sigismenber(sigset_t* set,int signo)
{
	if(SIGBAD(signo))
	{
		errno=EINVAL;
		return(-1);
	}
	return((*set&1<<(signo-1))!=0);
	return(0);
}



/*
 * =====================================================================================
 *
 *       Filename:  p269.c
 *    Description:  
 *        Created:  2015年05月05日 19时53分26秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env_alrm;
static void sig_alam(int signo)
{
	longjmp(env_alrm,1);
}

unsigned int sleep1(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alam)==SIG_IGN)//如果原来是忽略该信号的
		return(seconds);
	//如果原来不是忽略该信号的
	alarm(seconds);
	pause();
	return(alarm(0));
}
unsigned int sleep2(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alam)==SIG_IGN)
		return(seconds);
	if(setjmp(env_alrm)==0)
	{
		alarm(seconds);//
		pause();
	}
	return(alarm(0));
}

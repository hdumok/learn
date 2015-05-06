/*
 * =====================================================================================
 *
 *       Filename:  p272.c
 *    Description:  
 *        Created:  2015年05月05日 20时29分06秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <setjmp.h>

static void sig_alrm(int signo);
static jmp_buf env_alrm;
int main()
{
	int n=0;
	char line[100];
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		err_sys("signal error");
	if(setjmp(env_alrm)==0)
	{
		alarm(10);
		if((n=read(STDIN_FILENO,line,100))<0)
			err_sys("read error");
		alarm(0);
	}
	write(STDOUT_FILENO,line,n);
	exit(0);
}
static void sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}


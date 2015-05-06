/*
 * =====================================================================================
 *
 *       Filename:  p276.c
 *    Description:  
 *        Created:  2015年05月06日 16时27分28秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
static void sig_quit(int signo)
{
	printf("int SIGQUIT\n");
	if(signal(SIGQUIT,SIG_DFL)==SIG_ERR)
		err_sys("signal error");
}
int main()
{
	sigset_t netmask,oldmask,pendmask;

	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
		err_sys("signal error");

	sigemptyset(&netmask);
	sigaddset(&netmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&netmask,&oldmask)<0)
		err_sys("sigprocmask eror");

	sleep(5);

	if(sigpending(&pendmask)<0)
		err_sys("sigpending error");
	if(sigismember(&pendmask,SIGQUIT))
		printf("SIGQUIT in pending\n");

	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("sigprocmask error2");
	sleep(5);
	exit(0);
}


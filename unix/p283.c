/*
 * =====================================================================================
 *
 *       Filename:  p283.c
 *    Description:  
 *        Created:  2015年05月07日 16时30分29秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <setjmp.h>
#include <time.h>
#include "p275.c"
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjmp;

static void sig_usr1(int signo)
{
	time_t starttime;
	if(canjmp=0)
		return;
	pr_mask("starting sigusr1");//由于sigismember函数的错误，放弃包含该函数文件后
	alarm(3);					//可以编译成功，但是打印具体消息失败，只能答应换行
	starttime=time(NULL);
	while(1)
		if(time(NULL)>starttime+5)
			break;

	pr_mask("finishing sig_usr1:");
	canjmp=0;//标记jmpbuf要使用了
	siglongjmp(jmpbuf,1);
}
static void sig_alarm(int signo)
{
	pr_mask("in sig_alarm:");
			}
int main()
{
	if(signal(SIGUSR1,sig_usr1)==SIG_ERR)
		err_sys("signal error");
	if(signal(SIGALRM,sig_alarm)==SIG_ERR)
		err_sys("signal2 error");

	pr_mask("starting main:");
	if(sigsetjmp(jmpbuf,1))
	{
		pr_mask("ending main:");
		exit(0);
	}
	canjmp=1;
	while(1)
		pause();
}

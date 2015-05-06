/*
 * =====================================================================================
 *
 *       Filename:  p257.c
 *    Description:  
 *        Created:  2015年05月05日 16时57分19秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h"
static void  sig_usr(int signo)
{
	if(signo==SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo==SIGUSR2)
		printf("received SIGUSR2\n");
	else
		err_dump("received signal %d\n",signo);
}
int main()
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		err_sys("can not catch SIGUSR1");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		err_sys("can not catch SIGUSR2");
	while(1)
		pause();
}

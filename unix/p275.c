/*
 * =====================================================================================
 *
 *       Filename:  p275.c
 *    Description:  
 *        Created:  2015年05月06日 15时33分44秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <errno.h>
//#include "p274.c" 不使用sigismember函数
void pr_mask(const char* str)
{
	sigset_t sigset;
	int errno_save;
	errno_save=errno;

	if(sigprocmask(0,NULL,&sigset))//
		err_sys("sigprocmask error");
	else
	{
		printf("%s",str);
		if(sigismember(&sigset,SIGINT))
			printf("SIGINT");
		if(sigismember(&sigset,SIGQUIT))
			printf("SIGQUIT");
		if(sigismember(&sigset,SIGUSR1))
			printf("SIGUSR1");
		if(sigismember(&sigset,SIGALRM))
			printf("SIGALRM");

    	printf("\n");
	}
	errno=errno_save;
}

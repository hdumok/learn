/*
 * =====================================================================================
 *
 *       Filename:  p271.c
 *    Description:  
 *        Created:  2015年05月05日 20时10分16秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
static void sig_alrm(int signo)
{
	
}
int main()
{
	int n;
	char line[1024];
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		err_sys("signal error");
	alarm(10);//设置闹钟的目的是为了打断接下来的read的阻塞，但是如果遇到竞争情况在此处停留10s，进程可能会永远阻塞
	if((n=read(STDIN_FILENO,line,1024))<0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO,line,n);
	exit(0);
}

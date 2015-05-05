/*
 * =====================================================================================
 *
 *       Filename:  p193.c
 *    Description:  
 *        Created:  2015年05月04日 13时51分00秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();

	if(pid<0)
		err_sys("fork error");
	else if(pid==0)
	{
		pid=fork();
		if(pid<0)
			err_sys("fork2 error");
		else if(pid>0)
			exit(0);//第一个创建的进程退出了 由第一个进程创建的第二个进程没有归属 成为init进程的子进程
		sleep(2);
		printf("this pid's father is %ld",(long)getppid());//这是最后退出的进程，给init接管后，init会处理僵死问题
		exit(0);
	}
	if(waitpid(pid,NULL,0)!=pid)//防止形成僵死进程
		err_sys("waitpid error");
	printf("main\n");//这个printf只执行了一次，进程2不会经过这里
	exit(0);
}

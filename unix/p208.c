/*
 * =====================================================================================
 *
 *       Filename:  p208.c
 *    Description:  
 *        Created:  2015年05月04日 19时56分22秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
int main()
{
	pid_t pid;

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)
	{
		if(execl("/home/mok/bin/echoall","echoall","hello",(char*)0)<0)
			err_sys("execl error");
	}
	if(waitpid(pid,NULL,0)<0)
		err_sys("waitpid error");
	exit(0);

}

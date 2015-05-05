/*
 * =====================================================================================
 *
 *       Filename:  p202.c
 *    Description:  
 *        Created:  2015年05月04日 19时02分37秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
char *env_init[]={"USER=unknown","PATH=/tmp",NULL};
int main()
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)
	{
		if(execle("/home/mok/learn/unix/echoall","echoall","hello","world",(char*)0,env_init)<0)
			err_sys("enecle error");
	}
	if(waitpid(pid,NULL,0)<0)
		err_sys("waitpid error");
	
	if((pid=fork())<0)
		err_sys("fork2 error");
	else if(pid==0)
	{
		if(execlp("echoall","echoall","good","night",(char*)0)<0)
			err_sys("eneclp error");
	}
	exit(0);
}

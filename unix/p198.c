/*
 * =====================================================================================
 *
 *       Filename:  p197.c
 *    Description:  
 *        Created:  2015年05月04日 18时34分32秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
static void charatatime(char* str)
{
	char* ptr;
	int c;
	setbuf(stdout,NULL);//无缓冲
	for(ptr=str;*ptr!=0;ptr++)
		putc(*ptr,stdout);
}
int main()
{
	pid_t pid;
	
	TELL_WAIT();

	pid=fork();
	if(pid<0)
		err_sys("fork error");
	else if(pid==0)
	{
		WAIT_PARENT();
		charatatime("child\n");
	}
	else
	{
		charatatime("parents\n");
		TELL_CHILD(pid);
	}
	exit(0);
}



/*
 * =====================================================================================
 *
 *       Filename:  p183.c
 *    Description:  
 *        Created:  2015年05月04日 11时23分56秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
int globvar=2;
char buf[]="a write to stdout\n";

int main ()
{
    int var;
	pid_t pid;
	
	var=1;
	if(write(STDOUT_FILENO,buf,strlen(buf))!=strlen(buf))
		err_sys("write error");

	puts("before");
	pid=fork();
	if(pid<0)
		err_sys("fork error");
	else if(pid==0)
	{
		globvar*=10;
		var*=10;
	}
	else
		sleep(20);
	printf("globvar=%d,var=%d",globvar,var);
	exit(0);	
}				

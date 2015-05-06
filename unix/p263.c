/*
 * =====================================================================================
 *
 *       Filename:  p263.c
 *    Description:  
 *        Created:  2015年05月05日 19时15分33秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pwd.h>
static void my_alarm(signo)
{
	struct passwd *rootptr;

	printf("in signal handler\n");
	if((rootptr=getpwnam("root"))==NULL)
		err_sys("getpwnam error");
	alarm(1);
}
int main()
{
	struct passwd* ptr;
	signal(SIGALRM,my_alarm);
	alarm(1);
	while(1)
	{
		if((ptr=getpwnam("mok"))==NULL)
			err_sys("getpwnam2 error");
		if(strcmp(ptr->pw_name,"mok")!=0)
			printf("return value corrupted!,pw_name= %s\n",ptr->pw_name);
	}
}

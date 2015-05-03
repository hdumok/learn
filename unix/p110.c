/*
 * =====================================================================================
 *
 *       Filename:  p110.c
 *    Description:  
 *        Created:  2015年05月02日 20时49分46秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
int main()
{
	char ptr[100];
	size_t size;
	if(chdir("/home")<0)
		err_sys("chdir error");

	if(getcwd(ptr,size)<0)
		err_sys("getcwd error");
	printf("cwd=%s\n",ptr);
	exit(0);
}

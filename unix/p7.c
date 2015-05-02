/*
 * =====================================================================================
 *
 *       Filename:  p7.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 14时13分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int main(void)
{
	int n;
	char buf[1024];
	while((n=read(STDIN_FILENO,buf,1024))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write erroe");
	if(n<0)
		err_sys("read error");
	exit(0);
}

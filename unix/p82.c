/*
 * =====================================================================================
 *
 *       Filename:  p82.c
 *    Description:  
 *        Created:  2015年05月02日 18时42分29秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <fcntl.h>

int main ( int argc, char *argv[] )
{
	if(argc!=2)
		err_quit("usage:a.out<pathname>");
	if(access(argv[1],R_OK)<0)
		err_ret("access error");
	else 
		printf("read access");
	if(open(argv[1],O_RDONLY,0)<0)
		err_ret("read error");
	else
		printf("open for read ok");

	exit(0);	
}				


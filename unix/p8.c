/*
 * =====================================================================================
 *
 *       Filename:  p8.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 14时23分22秒
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
	int c;
	while((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");

	exit(0);
}


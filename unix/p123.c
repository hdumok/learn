/*
 * =====================================================================================
 *
 *       Filename:  p123.c
 *    Description:  
 *        Created:  2015年05月03日 13时34分30秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
int main()
{
/*	int c;

	while((c=getc(stdin))!=EOF)//EOF是大于256的int值
		if(putc(c,stdout)==EOF)
			err_sys("putc error");
*/
	char buf[100];

	while(fgets(buf,100,stdin)!=NULL)
		if(fputs(buf,stdout)==EOF)
			err_sys("fputs error");

	if(ferror(stdin))
		err_sys("input error");

	exit(0);
}

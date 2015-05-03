/*
 * =====================================================================================
 *
 *       Filename:  p54.c
 *
 *    Description:  测试能否设置偏移量  
 *
 *        Version:  1.0
 *        Created:  2015年05月02日 14时25分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int main()
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
		printf("cannot seek");
	else
		printf("seel ok");
	exit(0);

}


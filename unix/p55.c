/*
 * =====================================================================================
 *
 *       Filename:  p55.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月02日 14时31分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>
char buf1[]="abcdefghig";
char buf2[]="ABCDEFGHIG";

int main()
{
	int fd;

	if((fd=creat("file",FILE_MODE))<0)//文件权限位 FILE_MODE
		err_sys("creat error");
	if(write(fd,buf1,10)!=10)
		err_sys("write error");

	if(lseek(fd,50,SEEK_SET)==-1)
		err_sys("seek error");
	if(write(fd,buf2,10)!=10)
		err_sys("write2 error");
	exit(0);
}


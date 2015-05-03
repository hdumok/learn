/*
 * =====================================================================================
 *
 *       Filename:  p86.c
 *    Description:  
 *        Created:  2015年05月02日 19时15分56秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 

int main ()
{
	struct stat statbuf;
	
	stat("foo",&statbuf);
	if(chmod("foo",(statbuf.st_mode&~S_IXGRP|S_ISGID))<0)
		err_sys("chmod error");
	if(chmod("bar",S_IRUSR|S_IWUSR))
		err_sys("chmod error");

	exit(0);	
}				

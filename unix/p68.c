/*
 * =====================================================================================
 *
 *       Filename:  p68.c
 *    Description:  
 *        Created:  2015年05月02日 16时43分23秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <fcntl.h>
void set_fl(int fd,int flags)
{
	int val;
	if((val=fcntl(fd,F_GETFL,0))<0)
		err_sys("fcntl get error");
	val=val|flags;
	if(fcntl(fd,F_SETFL,val)<0)
		err_sys("fcntl set error");

}

void clr_fl(int fd,int flags)
{
	int val;
	if((val=fcntl(fd,F_GETFL,0))<0)
		err_sys("fcntl get error");
	val=val&~flags;
	if(fcntl(fd,F_SETFL,val)<0)
		err_sys("fcntl set error");

}

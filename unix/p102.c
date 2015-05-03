/*
 * =====================================================================================
 *
 *       Filename:  p102.c
 *    Description:  修改文件的内容 但是让记录的时间不变
 *        Created:  2015年05月02日 20时04分05秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <fcntl.h>

int main ( int argc, char *argv[] )
{
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];
	for(i=0;i<argc;i++)
	{
		if(stat(argv[1],&statbuf)<0)
		{
			err_sys("stat error");
			continue;
		}
		if((fd=open(argv[i],O_RDWR|O_TRUNC))<0)
			err_sys("open error");

		times[0]=statbuf.st_atime;//报错  类型不兼容！！！！
		times[1]=statbuf.st_ctime;

		if(futimens(fd,times)<0)
			err_sys("futimens error");
		close(fd);
	}
	exit(0);	
}				

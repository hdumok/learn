/*
 * =====================================================================================
 *
 *       Filename:  p76.c
 *    Description:  
 *        Created:  2015年05月02日 17时15分01秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 

int main ( int argc, char *argv[] )
{
	int i;
	struct stat buf;
	char *ptr;
	for(i=1;i<argc;i++)
	{
		printf("%s:",argv[i]);
		if(lstat(argv[i],&buf)<0)//强调链接文件自身的属性
			err_ret("lstat error");
		if(S_ISREG(buf.st_mode))
			ptr="regular";
		else if(S_ISDIR(buf.st_mode))
			ptr="directory";
		else if(S_ISCHR(buf.st_mode))
			ptr="character";
		else if(S_ISBLK(buf.st_mode))
			ptr="block";
		else if(S_ISFIFO(buf.st_mode))
			ptr="fifo";
		else
			ptr="unknown";
		printf("%s\n",ptr);
	}

	exit(0);	
}				

/*
 * =====================================================================================
 *
 *       Filename:  p94.c
 *    Description:  
 *        Created:  2015年05月02日 19时35分05秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <fcntl.h>

int main()
{
	if(open("tempfile",O_RDWR)<0)
		err_sys("open error");
	if(unlink("tempfile")<0)
		err_sys("unlink error");
	//在一个文件被打开时，是可以在目录的block中删除该目录项的
	exit(0);
}

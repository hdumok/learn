/*
 * =====================================================================================
 *
 *       Filename:  p83.c
 *    Description:  umask文件屏蔽字的使用
 *        Created:  2015年05月02日 19时02分12秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
	umask(0);
	creat("foo",RWRWRW);
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	creat("bar",RWRWRW);
	exit(0);
}

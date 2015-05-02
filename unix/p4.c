/*
 * =====================================================================================
 *
 *       Filename:  ls.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月01日 13时22分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <dirent.h>
int main ( int argc, char *argv[] )
{
	DIR *dp;
	struct dirent *dirp;
	if(argc!=2)
		err_quit("error");

	if((dp=opendir(argv[1]))==NULL)
		err_quit("open error");
	while((dirp=readdir(dp))!=NULL)
		printf("my ls show dir :%s\n",dirp->d_name);
	closedir(dp);
	exit(0);
}				/* ----------  end of function main  ---------- */

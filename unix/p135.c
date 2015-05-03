/*
 * =====================================================================================
 *
 *       Filename:  p135.c
 *    Description:  
 *        Created:  2015年05月03日 15时11分39秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
int main(void)
{
	char name[100],line[100];
	FILE* fp;
	printf("%s\n",tmpnam(NULL));// 返回存储路径名的静态区地址，再次调用会重写，所以不能只保存地址
	tmpnam(name);
	printf("%s\n",name);

	if((fp=tmpfile())==NULL)
		err_sys("tmpfile error");
	fputs("oneline",fp);
	rewind(fp);
	if(fgets(line,100,fp)==NULL)
		err_sys("fgets error" );
	printf("%s\n",line);

	exit(0);
}

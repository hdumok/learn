/*
 * =====================================================================================
 *
 *       Filename:  p131.c
 *    Description:  判断流缓冲区长度的函数 没写完
 *        Created:  2015年05月03日 14时45分04秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
void pr_stdio(const char *,FILE*);
int	 is_unbuffered(FILE*);
int  is_linebuffered(FILE*);
int  buffer_size(FILE*);

int main()
{
	FILE* fp;

	fputs("enter any char\n",stdout);
	if(getchar()==EOF)
		err_sys("getchar error");
	fputs("one line to stander error\n",stderr);

	pr_stdio("stdin",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderr",stderr);

	if((fp=fopen("/etc/passwd","r"))==NULL)
		err_sys("fopen error");
	if(getc(fp)==EOF)
		err_sys("getc error");
	pr_stdio("/etc/passwd",fp);
	exit(0);
}

void pr_stdio(const char *name,FILE *fp)
{
	printf("stream=%s",name);
	if(is_unbuffered(fp))
		printf("is_unbuffered");
	else if(is_linebuffered(fp))
		printf("is_linebuffered");
	else
		printf("is_fully_buffered");
	printf(",buffer size=%d\n",buffer_size(fp));

}
#if define(_IO_UNBUFFERED)
int	 is_unbuffered(FILE* fp)
{
	return(fp->_flags&_IO_UNBUFFERED);	
}
int  is_linebuffered(FILE* fp)
{
	return(fp->_flags&_IO_LINE_BUF);
}
int  buffer_size(FILE* fp)
{
	return(fp->_IO_LINE_END-fp->_IO_LINE_BASE);
}
#endif

/*
 * =====================================================================================
 *
 *       Filename:  p443.c
 *    Description:  
 *        Created:  2015年05月12日 19时16分55秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
static void sig_pipe(int);

int main()
{
	int n,fd1[2],fd2[2];
	pid_t pid;
	char line[100];

	if(signal(SIGPIPE,sig_pipe)==SIG_ERR)
		err_sys("signal error");

	if(pipe(fd1)<0||pipe(fd2)<0)
		err_sys("pipe error");

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0)
	{
		close(fd1[0]);//父线程关闭管道1的读入和管道2的写出
		close(fd2[1]);

		while(fgets(line,100,stdin)!=NULL)//读取标准输入
		{
			n=strlen(line);
			if(write(fd1[1],line,n)!=n)//写入管道1
				err_sys("write error");
			if((n=read(fd2[0],line,100))<0)//读取管道2
				err_sys("read error");
			if(n==0)
			{
				err_msg("child closed pipe");
				break;
			}
		}
		line[n]=0;
		if(fputs(line,stdout)==EOF)//输出到标准输出
			err_sys("fgets error");
		exit(0);
	}
	else
	{
		close(fd1[1]);
		close(fd2[0]);

		if(fd1[0]!=STDIN_FILENO)
		{
			if((fd1[0]=dup2(fd1[0],STDIN_FILENO))!=STDIN_FILENO)
				err_sys("dup2 error to stdin");
			close(fd1[0]);//它的作用被标准输入替换了
		}
		if(fd2[1]!=STDOUT_FILENO)
		{
			if((fd2[1]=dup2(fd2[1],STDOUT_FILENO))!=STDOUT_FILENO)
				err_sys("dup2 error to stdout");
			close(fd2[1]);
		}
		if(execl("./add2","add2",(char*)0)<0)
			err_sys("execl error");
	}
	exit(0);
}
static void sig_pipe(int signo)
{
	printf("SIGPIPE caughut\n");
	exit(1);
}

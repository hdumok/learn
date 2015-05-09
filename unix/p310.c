/*
 * =====================================================================================
 *
 *       Filename:  p310.c
 *    Description:  
 *        Created:  2015年05月08日 15时25分39秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>
pthread_t ntid;
void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n",s,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}
void* thr_fn(void *ary)
{
	printids("new thread:");
	return ((void*)0); 
}
int main()
{
	int err;
	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0)
	err_exit(err,"can not create thread");
	printids("main thread:");
	sleep(1);//让主线程睡眠
	exit(0);
}

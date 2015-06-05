/*
 * =====================================================================================
 *
 *       Filename:  p368.c
 *    Description:  
 *        Created:  2015年05月11日 20时06分20秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>

pthread_mutex_t lock1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2=PTHREAD_MUTEX_INITIALIZER;

void prepare()
{
	int err;
	printf("prepare locks\n");
	if((err=pthread_mutex_lock(&lock1))!=0)
		err_exit(err,"can not lock lock1 in prepare handler");
	if((err=pthread_mutex_lock(&lock2))!=0)
		err_exit(err,"can not lock lock2 in prepare handler");
}
void parent()
{
	int err;
	printf("parent unlocking locks\n");
	if((err=pthread_mutex_unlock(&lock1))!=0)
		err_exit(err,"can unlock lock1 in parent handler");
	if((err=pthread_mutex_unlock(&lock2))!=0)
		err_exit(err,"can unlock lock2 in parent handler");
}

void child()
{
	int err;
	printf("child unlocking locks\n");
	if((err=pthread_mutex_unlock(&lock1))!=0)
		err_exit(err,"can unlock lock1 in child handler");
	if((err=pthread_mutex_unlock(&lock2))!=0)
		err_exit(err,"can unlock lock2 in child handler");
}

void* thr_fn(void* arg)
{
	printf("thread started ..\n");
	pause();
	return(0);
}

int main()
{
	int err;
	pid_t pid;
	pthread_t tid;

	if((err=pthread_atfork(prepare,parent,child))!=0)
		err_exit(err,"can not install fork handler");
	if((err=pthread_create(&tid,NULL,thr_fn,0))!=0)
		err_exit(err,"can not create thread");

	sleep(2);
	printf("parent about to fork \n");
	if((pid=fork())<0)
		err_quit("fork error");
	else if(pid==0)
		printf("child return from fork\n");
	else
		printf("parent return from fork\n");
	exit(0);

}

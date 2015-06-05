/*
 * =====================================================================================
 *
 *       Filename:  p365.c
 *    Description:  
 *        Created:  2015年05月11日 13时41分15秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>

int quitflag;
sigset_t mask;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc=PTHREAD_COND_INITIALIZER;

void* thr_fn(void* arg)
{
	int err,signo;
	while(1)
	{
		err=sigwait(&mask,&signo);//成功返回0，等待屏蔽字里的消息
		if(err!=0)
			err_exit(err,"sig_wait error");
		switch(signo)
		{
			case SIGINT:
				printf("\ninterrupt\n");
				break;
			case SIGQUIT:
				pthread_mutex_lock(&lock);
				quitflag=1;
				pthread_mutex_unlock(&lock);
				pthread_cond_signal(&waitloc);//条件变量满足，即办事窗口被允许处理一个事物，激活一个线程
				return;
			default:
				printf("unexpected signed %d\n",signo);
				exit(1);
		}
	}
}

int main()
{
	int err;
	sigset_t oldmask;
	pthread_t tid;
	
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	sigaddset(&mask,SIGQUIT);
	if((err=pthread_sigmask(SIG_BLOCK,&mask,&oldmask))!=0)
		err_exit(err,"SIG_BLOCK error");
	err=pthread_create(&tid,NULL,thr_fn,0);//创建一个线程区改变条件变量
	if(err!=0)
		err_exit(err,"can not create thread");

	pthread_mutex_lock(&lock);
	while(quitflag==0)
		pthread_cond_wait(&waitloc,&lock);//在函数里等待条件变量为真
	pthread_mutex_unlock(&lock);

	quitflag=0;

	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("SIG_SETMASK error");
	exit(0);
}

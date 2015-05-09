/*
 * =====================================================================================
 *
 *       Filename:  p312.c
 *    Description:  
 *        Created:  2015年05月09日 13时55分09秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>
void* thr_fn1(void *arg)
{
	printf("thread 1 returning\n");
	return((void*)1);
}
void* thr_fn2(void *arg)
{
	printf("thread 2 exiting\n");
	return((void*)2);
}

int main()
{
	int err;
	pthread_t tid1,tid2;
	void *tret;

	err=pthread_create(&tid1,NULL,thr_fn1,NULL);
	if(err!=0)
		err_exit(err,"can not create thread 1");
	err=pthread_create(&tid2,NULL,thr_fn2,NULL);
	if(err!=0)
		err_exit(err,"can not create thread 2");
	err=pthread_join(tid1,&tret);//主线程等待线程1结束,并获取其退出状态
	if(err!=0)
		err_exit(err,"can not join thread 1");
	printf("thread 1 exit code %ld\n",(long)tret);
	
	err=pthread_join(tid2,&tret);//主线程等待线程1结束,并获取其退出状态
	if(err!=0)
		err_exit(err,"can not join thread 2");
	printf("thread 2 exit code %ld\n",(long)tret);
	exit(0);
}



/*
 * =====================================================================================
 *
 *       Filename:  p328.c
 *    Description:  
 *        Created:  2015年05月09日 16时45分52秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>
#include <time.h>
int main()
{
	int err;
	struct timespec tout;
	struct tm* tmp;
	char buf[64];
	pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	printf("mutex is locked\n");
	clock_gettime(CLOCK_REALTIME,&tout);//获取当前时间
	tmp=localtime(&tout.tv_sec);
	strftime(buf,64,"%r",tmp);
	printf("current time is %s\n",buf);
	tout.tv_sec+=10;
	
	err=pthread_mutex_timedlock(&lock,&tout);
	clock_gettime(CLOCK_REALTIME,&tout);//获取当前时间
	tmp=localtime(&tout.tv_sec);
	strftime(buf,64,"%r",tmp);
	printf("current time is %s\n",buf);
	if(err==0)
		printf("mutex locked again!\n");
	else
		printf("can not lock mutex again:%s\n",strerror(err));
	exit(0);


}

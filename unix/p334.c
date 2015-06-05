/*
 * =====================================================================================
 *
 *       Filename:  p334.c
 *    Description:  
 *        Created:  2015年05月10日 16时06分59秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <pthread.h>
struct msg{
	struct msg* m_next;
};
struct msg *workq;

pthread_cond_t qready=PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock=PTHREAD_MUTEX_INITIALIZER;

void precess_msg()
{
	while(1)
	{
		pthread_mutex_lock(&qlock);
		while(workq==NULL)
			pthread_cond_wait(&qready,&qlock);
		mp=workq;
		workq=workq->m_next;
		pthread_mutex_unlock(&qlock);
	}
}
void enqueue_msg(struct msg *mp)
{
	pthread_mutex_lock(&qlock);
	mp->m_next=workq;
	workq=mp;
	pthread_mutex_unlock(&qlock);
	pthread_cond_signal(&qready);

}


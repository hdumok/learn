/*
 * =====================================================================================
 *
 *       Filename:  p322.c
 *    Description:  
 *        Created:  2015年05月09日 14时57分34秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>

struct foo{//把锁和资源组织到一个结构体内
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
}
struct foo* foo_alloc(int id)
{
	struct foo *fp;
	if((fp=malloc(sizeof(struct foo)))!=NULL)
	{
		fp->f_count=1;
		fp->f_id=id;
		if(pthread_mutex_init(fp->f_lock)!=NULL)//如果与该资源的锁初始化失败，那这个锁与资源都分配无效
		{
			free(fp);
			return(NULL);
		}
	}
	return(fp);
}
void foo_hold(struct foo* fp)
{
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);
}
void foo_rele(struct foo* fp)
{
	pthread_mutex_lock(&fp->f_lock);
	if(--fp->f_count==0)
	{
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	}
	else
		pthread_mutex_unlock(&fp->f_lock);
}

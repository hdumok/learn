/*
 * =====================================================================================
 *
 *       Filename:  p323.c
 *    Description:  
 *        Created:  2015年05月09日 15时21分44秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <pthread.h>

#define NHASH 29
#define HASH(id) (((unsigned long)id)/NHASH)

struct foo* fh[NHASH];

pthread_mutex_t hashlock=PTHREAD_MUTEX_INITIALIZER;
struct foo{
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
	struct foo* f_next;
}
struct foo* foo_alloc(int id)//分配节点时都像栈一样从头加入，所有的头指针存放在数组中
{
	struct foo* fp;
	int idx;

	if((fp=malloc(sizeof(struct foo)))!=NULL)
	{
		fp->f_count=1;
		fp->f_id=id;
		if(pthread_mutex_init(&fd->f_lock,NULL)!=0)//成功返回0
		{
			free(fp);
			return(NULL);
		}
		idx=HASH(id);//计算数组下标
		pthread_mutex_lock(&hashlock);//锁住大数组
		fp->f_next=fh[idx];
		fh[idx]=fp;//以fh[idx]为top指针，入栈
		pthread_mutex_lock(&fp->f_lock);//锁住刚插入的结点
		pthread_mutex_unlock(&hashlock);

		pthread_mutex_unlock(&fp->f_lock);//释放刚锁住的结点
	}
	return(fp);
}
void foo_hold(struct foo* fp)
{
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);
}
void foo_rele(struct foo* fp)//减小指定节点的值，减完了就删除该节点
{
	struct foo* tfp;
	int idx;

	pthread_mutex_lock(&fp->f_lock);
	if(fp->f_count==1)
	{
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_lock(%hashlock);//先锁住大数组
		pthread_mutex_lock(&fp->f_lock);//再锁住某一项
		if(fp->f_count!=1)
		{
			fp->f_count--;
			pthread_mutex_unlock(&fp->f_lock);
			pthread_mutex_unlock(&hashlock);
			return;
		}
		idx=HASH(fp->f_id);//计算fp项存储在数组的下标
		tfp=fh[idx];//获取该数组该项的值，本质是指针
		if(tfp==fp)//如果该节点是top节点
			fh[idx]=fp->f_next;
		else
		{
			while(tfp->f_next!=fp)//找到该节点
			{
				tfp=tfp->next;
			}
			tfp->next=fp->next;//去掉该结点
		}
	}
	else
	{
		fp->f_count--;
		pthread_mutex_unlock(&fp->f_lock);
	}
}

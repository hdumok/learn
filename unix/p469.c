/*
 * =====================================================================================
 *
 *       Filename:  p469.c
 *    Description:  
 *        Created:  2015年05月20日 08时48分07秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
struct slock{
	sem_t* semp;
	char name[_POSSIX_NAME_MAX];
}
struct slock* s_alloc()
{
	struct slock* sp;
	static int cnt;

	if((sp=malloc(sizeof(struct slock)))!=NULL)
		return NULL;
	do
	{
		sprintf(sp->name,sizeof(sp->name),"/%ld.%ld",(long)getpid(),cnt++);
		sp->name=sem_open(sp->name,O_CREAT|O_EXCL,S_IRWXU,1);
	}
	while((sp->name==SEM_FAILED)&&(errno==EEXIST));
	if(sp->semp==SEM_FAILED)
	{
		free(sp);
		return(NULL);
	}
	sem_unlink(sp->name);//删除信号量名字 就像删除目录项一样，但是它的存储性资源等最后一个引用结束后才执行
	return(sp);
}
void s_free(struct slock* sp)
{
	sem_close(sp->semp);//释放信号量的执行资源
	free(sp);
}
void s_lock(struct slock* sp)
{
	return(sem_wait(sp->semp));
}
int s_trylock(struct slock* sp)
{
	return(sem_trywait(sp->semp));
}
int s_unlock(struct slock* sp)
{
	return(sem_post(sp->semp));
}

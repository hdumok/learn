/*
 * =====================================================================================
 *
 *       Filename:  p360.c
 *    Description:  
 *        Created:  2015年05月13日 12时33分55秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <limits.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

static pthread_key_t key;
static pthread_once_t init_done=PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex=PTHREAD_MUTEX_INITIALIZER;

extern char** environ;
static void thread_init()
{
	pthread_key_create(&key,free);
}
char* getenv(const char* name)
{
	int i,len;
	char* envbuf;

	pthread_once(&init_done,thread_init);//依托变量init_done,只有第一次运行时才会调用thread_init
	pthread_mutex_lock(&env_mutex);
	envbuf=(char*)pthread_getspecific(key);
	if(envbuf==NULL)//如果键并没有关联私有资源
	{
		envbuf=malloc(1024);
		if(envbuf==NULL)
		{
			pthread_mutex_unlock(&env_mutex);
			return(NULL);
		}
		pthread_setspecific(&key,envbuf);
	}
	len=strlen(name);
	for(int i=0;environ[i]!=NULL;i++)
	{
		if((strncmp(name,environ[i],len)==0)&&environ[i][len]=='=')
		{
			strncpy(envbuf,environ[i]+1,1023);
			pthread_mutex_unlock(&env_mutex);
			return(envbuf);
		}
	}
	pthread_mutex_unlock(&env_mutex);
	return(NULL);
}

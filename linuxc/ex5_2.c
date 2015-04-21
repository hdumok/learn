/*
 * =====================================================================================
 *
 *       Filename:  ex5_2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 17时26分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
#define KEY 99

int shmid;
int j=5;

int main()
{
	int i,*pint;
	pid_t pid;
	char* addr;

	i=10;
	shmid=shmget(SIZE,KEY,IPC_CREAT|0777);
	pint=shmat(shmid,0,0);
	*pint=100;
	printf("start fork\n");
	pid =fork();
	i++;
	j++;
	*pint+=1;
	printf("pid=%d\n",pid);
	printf("i=%d,j=%d\n",i,j);
	printf("*pint=%d\n",*pint);
	return 0;

}








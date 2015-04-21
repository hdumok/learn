#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	printf("start of fork\n");
	pid=fork();
	printf("child pid=%d\n",pid);
	return 0;
}

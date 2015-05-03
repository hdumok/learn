/*
 * =====================================================================================
 *
 *       Filename:  p161.c
 *    Description:  
 *        Created:  2015年05月03日 16时48分49秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
static void my_exit1(void);
static void my_exit2(void);

int main()
{
	if(atexit(my_exit2)!=0)
		err_sys("atexit my_exit2 error");
	if(atexit(my_exit1)!=0)
		err_sys("atexit my_exit1 error");
	
	printf("main runtime_errorn\n");
	
	return(0);

}
static void my_exit1(void)
{
	printf("my_exit1 run\n");
}
static void my_exit2(void)
{
	printf("my_exit2 run\n");
}

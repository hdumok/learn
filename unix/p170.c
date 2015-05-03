/*
 * =====================================================================================
 *
 *       Filename:  p170.c
 *    Description:  
 *        Created:  2015年05月03日 18时11分45秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 
#include <setjmp.h>
#define TOK_ADD 5

void do_line(char*);
void cmd_add(void);
int get_token(void);
char * tok_ptr;
jmp_buf jmpbuf;

int main(void)
{
	char line[100];
	if(setjmp(jmpbuf)!=0)
		printf("error");
	while(fgets(line,100,stdin)!=NULL)
		do_line(line);
	exit(0);
}

void do_line(char* ptr)
{
	int cmd;
	tok_ptr=ptr;
	while((cmd=get_token())>0)
	{
		switch(cmd)
		{
			case TOK_ADD:
				cmd_add();
				break;
		}
	}
}
void cmd_add(void)
{
	int token;
	token=get_token();
	if(token<0)
		longjmp(jmpbuf,1);
}
int get_token(void)
{
	int i;
	printf("input i\n ");
	scanf("%d",&i);
	return i;
}

/*
 * =====================================================================================
 *
 *       Filename:  code12.cpp
 *    Description:  打印1到最大的N位数
 *        Created:  2015年05月08日 21时15分31秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>
#include <memory.h>
using std::cout;

void Printf(unsigned int n);
bool Increment(char* num);
void PrintfNum(char* num);

int main(int argc,char* argv[])
{
	int n=atoi(argv[1]);
	Printf(n);
}
void Printf(unsigned int n)
{
	if(n<1)
		return;
	char* num=new char[n+1];
	memset(num,'0',n);
	num[n]='\0';

	while(!Increment(num))
	{
		PrintfNum(num);
		cout<<" ";
	}
	delete [] num;
}
bool Increment(char* num)
{
	bool numover=false;
	int digitover=0;
	int length=strlen(num);
	for(int i=length-1;i>=0;i--)
	{
		int n=num[i]-'0'+digitover;
		if(i==length-1)//如果是最低位
			n++;
		if(n>=10)
		{
			if(i==0)
				numover=true;//溢出了
			else
			{
				n=n-10;
				digitover=1;
				num[i]=n+'0';
			}
		}
		else
		{
			num[i]=n+'0';
			break;//如果该位数字不再进位，意味着前几位处理完毕，后几位也不必处理
		}
	}
	return numover;

}
void PrintfNum(char* num)
{
	bool flag=false;
	int length=strlen(num);
	for(int i=0;i<length;i++)
	{
		if(flag||num[i]!='0')
		{
			flag=true;//标记着数字有效部分已经开始了
			cout<<num[i];
		}
	}
}

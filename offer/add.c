#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define N 20
int main()
{
	char a[N],b[N],sum[N];
	int val=0,flag=0;
	int last_a,last_b,last_sum;//数组最后一位有效位的偏移量
	scanf("%s",a);
	scanf("%s",b);
	last_a=strlen(a)-1;
	last_b=strlen(b)-1;
	last_sum=N-1;
	sum[last_sum]=0;//和数组的最后一位手动设置结束符
	while(1)
	{
		if(last_a>=0&&last_b>=0)
			val=a[last_a--]-'0'+b[last_b--]-'0'+flag;
		else if(last_a>=0)
			val=a[last_a--]-'0'+flag;
		else if(last_b>=0)
			val=b[last_b--]-'0'+flag;
		else if(flag) //虽然个数组都没有可以用来计算的位了 但是前一次运算产生了进位
			val=flag;
		else
			break;//如果两个数据都没有有效位了 break退出循环
		flag=0;
		if(val>=10)
		{
			val=val-10;
			flag=1;
		}

		--last_sum;//瞄准SUM的可用的最后一位的偏移量
		if (last_sum<0)//如果现在想要填写的和的有效位偏移量竟然是-1  说明溢出了
			return -1;
		else
			sum[last_sum]=val+'0';
	}
	printf("%s\n",sum+last_sum);
	getchar();//显示用
	getchar();
	return 0;
}
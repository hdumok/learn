/*
 * =====================================================================================
 *
 *       Filename:  code8.cpp
 *    Description:  递归
 *        Created:  2015年05月08日 20时14分59秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
unsigned int Fibonacci(unsigned int n)
{
	if(n<2)
		return n;
	else
		return Fibonacci(n-1)+Fibonacci(N-2);
}

unsigned int Fibonacci2(unsigned int n)
{
	if(n<2)
		return n;
	else
	{
		int result;
		int one_before=1;//前一个
		int two_before=0;//前前一个
		for(int i=2;i<=n;i++)
		{
			result=one_before+two_before;
			two_before=one_before;
			one_before=result;
		}
		return result;
	}
}

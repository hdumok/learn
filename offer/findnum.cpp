/*
 * =====================================================================================
 *
 *       Filename:  findnum.cpp
 *    Description:  
 *        Created:  2015年05月27日 18时38分33秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
void findnum(int a[],int n,int num)
{
	if(a==NULL||n<1)
		return;
	vector<int> set;
	int index=0;
	int next=abs(num-a[index])+index;
	while(next<n)
	{
		if(a[next]==num)
		{
			index=next;
			set.push_back(next);
			next=next+2;
		}
		else
		{
			index=next;
			next=abs(num-a[index])+index;
		}
	}
	for(int i=0;i<set.size();i++)
		cout<<set[i]<<endl;
}
int main(int argc,char* agrv[])
{
	int a[13]={1,2,3,4,5,6,5,6,7,8,9,10,9};
	findnum(a,13,5);
	return 0;
}

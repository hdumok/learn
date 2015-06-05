/*
 * =====================================================================================
 *
 *       Filename:  m_to_n.cpp
 *    Description:  m进制数转n进制数
 *        Created:  2015年05月10日 10时34分47秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
* =====================================================================================
 */
#include <iostream>
#include <cstring>
#include <stdlib.h>
using std::strlen;
using std::cout;
char* mton(char* m_str,int m,int n)
{
	if(m_str==NULL||m<2||n<2)
		return NULL;
	/*此处省略了多输入数字串本身是否符合M进制格式的判断*/
	bool fushu=0;	
	if(m_str[0]=='-')
	{
		fushu=1;
		m_str++;
	}
	/* 将字母转换成对应数字便于计算*/
	int m_len=strlen(m_str);
	int num[m_len];
	for(int i=0;i<m_len;i++)
	{
		if(m_str[i]>='0'&&m_str[i]<='9')
			num[i]=m_str[i]-'0';
		else if(m_str[i]>='A'&&m_str[i]<='Z')
			num[i]=m_str[i]-'A'+10;
	}
	/*将数字转换进制后存入临时数组temp  但是是逆序的*/
	char temp[1024];
	int t_len=0;
	int offset=0;//有效位开始位
	int val=0;
	while(1)
	{
		int	digit=0;
		for(int j=offset;j<m_len;j++)
		{
			val=num[j]+digit*m;
			num[j]=val/n;
			digit=val%n;
		}
		temp[t_len++]=digit;//退出时，t_len指向超尾元素
		if(num[offset]==0)
		{
			if(offset==m_len-1)//如果K已经是最后一位了
				break;
			else
				offset++;
		}
	}

	int n_len=0;//n_str里的有效内容长度为0
	char* n_str=new char[t_len+fushu];
	if(fushu)
	{
		n_str[n_len]='-';
		n_len++;
	}
	for(int i=t_len-1;i>=0;i--)
	{
		if(temp[i]<=9||temp[i]>=0)
			n_str[n_len++]='0'+temp[i];
		else if(temp[i]<=35||temp[i]>=10)
			n_str[n_len++]='A'+temp[i];
	}
	n_str[n_len]='\0';
	return n_str;
}
int main(int argc,char* argv[])
{
	if(argc!=4)
		cout<<"input error\n";
	else
		cout<<mton(argv[1],atoi(argv[2]),atoi(argv[3]))<<'\n';
}

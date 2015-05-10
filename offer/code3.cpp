/*
 * =====================================================================================
 *
 *       Filename:  code3.cpp
 *    Description:  
 *        Created:  2015年05月06日 20时43分19秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include "apue.h" 

/*在二维数组中查找数字*/
bool Find(int* array,int rows,int columns,int number)
{
	bool found=false;
	if(array!=NULL&&rows>0&&columns>0)
	{
		int r=0;
		int c=columns-1;
		while(r<rows&&c>=0)
		{
			if(array[r*columns+c]==number)
			{
				found=true;
				break;
			}
			else if(array[r*columns+r]>number)
				c--;
			else
				r++;
		}
	}
	return found;
}
/*把字符串里的空白格换成字符串str，建立新串的做法 */
char* RepalceBlank(char* array,char*str)
{
	if(array=NULL||str=NULL)
		return NULL;
	int oldlength=strlen(array);
	int strlength=strlen(str);
	int num=0;
	char* p=array;
	while(*p!='\0')
	{
		if(*p=' ')
			num++;
		p++;
	}
	int newlength=oldlength+(strlength-1)*num;
	char* newarray=new char[newlength+1];
	char* a=array;
	char* na=newarray;

	while(a!=NULL)
    {
		if(*a!=' ')
		{
			*na++=*a;
			a++;
		}
		else
		{
			for(int i=0;i<strlength;i++)
				*na++=str[i];
			a++;
		}
	}
	return newarray;
}
/*把字符串里的每个空格换成字符串str,假设原字符串后有足够存储空间的做法 */
void RepalceBlank2(char array[],char* str)
{
	if(array==NULL||str==NULL)
		return；
	int oldlengthlength=strlen(array);
	int strlength=strlen(str);
	int num=0;
	int i=0;
	while(array[i]!='\0')
	{
		if(array[i]=' ')
			num++;
		i++;
	}
	int newlength=oldlength+num*(strlength-1);
	while(num>0&&oldlength>=0)
	{
		if(array[oldlength]==' ')
		{
			for(int i=strlength-1;i>=0;i--)
				array[newlength--]=str[i];
			oldlength--;//指向未处理的原串字符
		}
		else
			array[newlength--]=array[oldlength--];
	}
}
/*把字符串里的每个str1换成str2，关键在于先确定空间，从后往前移动 */
//返回替换后的字符串
char* Repalce(char* str,char* old_str,char* new_str)
{
	if(str==NULL||old_str==NULL||new_str==NULL)
		return;
	int len=strlen(str);
	int old_len=strlen(old_str);
	int new_len=strlen(new_str);

	/*获取每个旧子串的偏移位置 */
	vector<int> num;
	int  n=0;
	while(n<=len-old_len)
	{
		if(strncmp(str+n,old_str,old_len)==0)
		{
			num.push_back(n);
			n+=old_len;
		}
		else
			n++;
	}
	if(num.size()==0)
		return str;

	int LEN=len+num.size()*new_len-num.size()*old_len;
	char* STR=new char[LEN+1];
	
	int i=0,j=0,k=0;
	while(str[i]!=NULL)
	{
		if(num[k]!=NULL)
		{
			if(i!=num[k])
			{
				STR[j]=str[i];
				j++;
				i++;
			}
			else
			{
				strncmp(STR+j,new_str,new_len);
				j+=new_len;
				i+=old_len;
			}
		}
		else
			strcpy(STR+j,str+i);
	}
	STR[LEN]='\0';
}











/* /	if(old_len>new_len)//如果是原串比较长，不用分配内存
	{
	    int i=0,j=0,k=0;
		while(str[i]!=NULL)
		{
			if(num[k]!=NULL&&i==num[k])//i偏移处存在需呀被替换的字符
			{
				strncat(str+j,new_str,new_len);//覆盖替换字符串
				i+=old_len;//原串的偏移
				j+=new_len;//新串的偏移
				k++;//标记值数组下标增加
			}
			else
			{
				str[j]=str[i];
				i++;
				j++;
			}
		}
		str[j]='\0';
	}
	else(old_len<new_len)//如果是新串比较长，前提是原串后面有足够多的空间
	{
		int i=len;
		int j=len+old.size()*(new_len-old_len);
		int k=num.size();
		while(k>=0)
		{
			if(j!=num[k]+o
			str[j]
		}
	}
	
}*/

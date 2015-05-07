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
/*把字符串里的每个str1换成str2三个字符，关键在于先确定空间，从后往前移动 */
void Repalce(char* str,char str1,char str2)
{
	if(str=NULL||str1=NULL)
		return;
	int length=strlen(str);
	int length1=strlen(str1);
	int length2=strlen(str2);
	char* p=str;
	char* s=str1;
	int num=0;
	while(p!=NULL)
	{
	/*	while(*p==*s)
			p++,s++;
		if(s==NULL)
			num++,p+=length1;
		else
			s=str1;
	*/
		if(strncmp(p,str1,length1)==0)
			num++,p+=length1;
		else
			p++;
	}

	
	if(length1>length2)//如果是原串比较长，不用分配内存
	{
		
	}
	else(length1<length2)//如果是新串比较长，要分配内存
	{
		length=length+num*(length2-length1);

	}
	
}

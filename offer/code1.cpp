/*
 * =====================================================================================
 *
 *       Filename:  code1.cpp
 *    Description:  简易string类
 *        Created:  2015年05月03日 20时25分26秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
#include<cstring>
using std::strcpy;
using std::strlen;
using std::strcmp;
using std::strcat;
class MyString{
	
	private:
		char* m_data;

	public:
		MyString();
		MyString(const MyString& other);
		MyString(const char* buf=NULL);
		~MyString(delete []m_data);
		MyString& operator=(const MyString& other)
		
		friend ostream& operator<<(ostream& os,const MyString& my);
		friend istream& operator>>(istream& is,const MyString& my);
		friend bool operator<(const MyString& my,const MyString& other);
		friend bool operator>(const MyString& my,const MyString& other);
		friend bool operator==(const MyString& my,const MyString& other);
		friend MyString& operator+(const MyString& my,const MyString& other);
}
MyString::MyString()
{
	m_data=new char[1];
	m_data[0]='\0';
}
MyString::MyString(const MyString& other)
{
	m_data=new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data);
}
MyString::MyString(const char* buf)
{
	if(!buf)
	{
		m_data=new char[1];
		m_data[0]='\0';
	}
	else
	{
		m_data=new char[strlen(buf)+1];
		strcpy(m_data,buf);
}
MyString::MyString& operator=(const MyString& other)
{
	if(this!=&other)
	{
		delete [] m_data;
		m_data=new char[strlen(other.m_data)+1];
		strcpy(m_data,other.m_data);
	}
	return *this;
}
/*另一种重载写法，解决了内存分配可能出现的问题 */
MyString::MyString& operator=(const MyString& other)
{
	if(this!=&other)
	{
		MyString temp(other);
		char* p=temp.m_data;
		temp.m_data=m_data;
		m_data=p;
	}
	return *this;
}
ostream& operator<<(ostream& os,const MyString& my)
{
	os<<my.m_data;
}	

friend istream& operator>>(istream& is,const MyString& my)
{
	is>>my.m_data;
}
friend bool operator<(const MyString& my,const MyString& other)
{
	return(strcmp(my.m_data,other.m_data)<0);	
}
friend bool operator>(const MyString& my,const MyString& other)
{
	return(other<my);
}

friend bool operator==(const MyString& my,const MyString& other)
{
	return(strcmp(my.m_data,other.m_data)==0);
}
friend MyString& operator+(const MyString& my,const MyString& other)
{
	int length=strlen(my.m_data)+strlen(other.m_data);
    char temp[length+1];
	strcpy(temp,my.m_data);
	strcat(temp,other.m_data);
	MyString* p=new MyString(temp);
	return *p;
}



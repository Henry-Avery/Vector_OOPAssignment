// MyString.cpp
#include "MyString.h"
#include <cstring>
using namespace std;

String::String(const char *str) : VECTOR<char>(strlen(str), str)	// ���캯��
{
}

int String::length() const
{
	return num;			// �˴�����this->num����ΪString������ģ��
}

void String::Output(ostream &out) const
{
	for(int i=0; i<num; i++)
		out << p[i];
}

void String::Input(istream &in)	// �����Զ���չ���������Ĺ���
{
	const int N = 1;//1024;		// Nȡ��Сֵ1��Ϊ�˵��ԣ�ʵ��ʹ��ʱȡ1024
	char buffer[N], ch;			// ���뻺����
	int i, j, k, flag;
	String temp;
	
	while(true)					// ���˵���Ч�ַ�ǰ�Ŀհ��ַ�
	{
		ch = in.peek();			// ͵����һ���ַ������Ƿ�Ϊ�հ��ַ�
		if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			in.get(ch);			// ���ǿհ��ַ�������˵�������ȡ���ã�
		else
			break;				// ֱ�������ǿհ��ַ���������whileѭ��
	}
	for(k=0,flag=1; flag==1; k++)
	{
		for(i=0; i<N; i++)
		{
			ch = in.peek();
			if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\r')
			{
				flag = 0;
				break;
			}
			else
				in.get(buffer[i]);
		}
		temp.resize(k*N+i);			// ������resize������"����������ԭ������"�Ĺ���
		for(j=0; j<i; j++)
			temp[k*N+j] = buffer[j];// �����˷����������
	}
	*this = temp;					// �����˸�ֵ��������ֵ���㣩
}

istream & getline(istream &in, String &Str, int n, char delim)
{
	if(n<=0) return in;
	char *p = new char[n];
	in.getline(p, n, delim);
	Str = p;			// ������ת�����캯�����Ѿ���ֵ���������
	delete [] p;
	return in;
}

String operator+(const String &s1, const String &s2)
{
	String result(s1);
	int n1 = s1.length(), n2 = s2.length();
	result.resize(n1 + n2);
	for(int i=0; i<n2; i++)
		result[n1+i] = s2[i];
	return result;
}

String & String::operator+=(const String &s)
{
	resize(num + s.num);
	for(int i=0; i<s.num; i++)
		p[num+i] = s.p[i];
	return *this;
}

bool operator<(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 && i<n2)
		return s1[i]<s2[i];
	else if(i<n1 && i==n2)
		return false;
	else if(i==n1 && i<n2)
		return true;
	else
		return false;
}

bool operator<=(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 && i<n2)
		return s1[i]<s2[i];
	else if(i<n1 && i==n2)
		return false;
	else
		return true;
}

bool operator>(const String &s1, const String &s2)
{
	return !(s1<=s2);
}

bool operator>=(const String &s1, const String &s2)
{
	return !(s1<s2);
}

bool operator==(const String &s1, const String &s2)
{
	int i, n1=s1.length(), n2=s2.length();
	for(i=0; i<n1 && i<n2 && s1[i]==s2[i]; i++)
		;
	if(i<n1 || i<n2)
		return false;
	else
		return true;
}

bool operator!=(const String &s1, const String &s2)
{
	return !(s1==s2);
}


String String::mid(int pos,int n) const
{
	String t1;
	int i;
	t1.str = new char[n+1];
	for(i=0; i<n; i++)
		t1.str[i] = this->str[pos+i-1];
	t1.str[i] = '\0';
	return t1;
}

int String::stoi() throw(int)
{
	int i,n=0,k=0;
	for(i=0;i<strlen(this->str);i++)
		{
			k=this->str[i]-'0';
			if (k>9) throw 1;
			n=k+n*10;
		}
	return n;
}

int String::stoi(int pos,int n) 
{
	String t;
	t=this->mid(pos,n);
	return t.stoi();
}

String itos(int n) 
{
	int k;
	String t;
	char c[2];
	while(n>0)
	{
		k=n % 10;
		c[0]=k+'0';
		c[1] = '\0';
		t.insert(0,c);
		n=n/10;
	}
	return t;
}    
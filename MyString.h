//     MyString.h
#ifndef MYSTRING_H
#define MYSTRING_H

#include "Vec.h"

class String : public VECTOR<char>
{
public:
	String(const char *str="");
	int length() const;
	
	void Output(ostream &out) const;
	void Input(istream &in);
	friend istream & getline(istream &in, String &Str, int n, char delim='\n');

	friend String operator+(const String &s1, const String &s2);
	String & operator+=(const String &s);

	friend bool operator< (const String &s1, const String &s2);
	friend bool operator<=(const String &s1, const String &s2);
	friend bool operator> (const String &s1, const String &s2);
	friend bool operator>=(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend bool operator!=(const String &s1, const String &s2);

	int stoi() throw(int);                     //转换为整型
	int stoi(int pos,int n);
	friend String itos(int n);
	String mid(int pos,int n) const;
	String & insert(int p0, const char *s);			// 将 s 所指向的字符串插入在本串位置 p0 之前
	int find(const String &Str) const;				// 查找并返回 Str 在本串中第一次出现的位置
	
	const char * c_str();							// 转换为 C-字符串
	void swap(String &Str);							// 将本串与 Str 交换
	//char & operator[](int index) throw(int);					// 基类里有了
};

#endif

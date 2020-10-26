// MyString.h
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
};

#endif

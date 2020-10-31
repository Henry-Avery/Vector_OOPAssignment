
// *MyString.h
#ifndef MYSTRING_H
#define MYSTRING_H

#include "Vec.h"

class String : public VECTOR<char>
{
public:
	String(const char* str = "");
	int length() const;

	void Output(ostream& out) const;
	void Input(istream& in);
	//friend istream& getline(istream& in, String& Str, int n, char delim = '\n');
	friend istream& getline(istream& in, String& Str, int n, char delim);

	friend String operator+(const String& s1, const String& s2);
	String& operator+=(const String& s);

	friend bool operator< (const String& s1, const String& s2);
	friend bool operator<=(const String& s1, const String& s2);
	friend bool operator> (const String& s1, const String& s2);
	friend bool operator>=(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
	friend bool operator!=(const String& s1, const String& s2);

	int stoi() throw(int);                     //ת��Ϊ����
	int stoi(int pos, int n);
	friend String itos(int n);
	String mid(int pos, int n) const;
	String& insert(int p0, const char* s);			// �� s ��ָ����ַ��������ڱ���λ�� p0 ֮ǰ
	int find(const String& Str) const;				// ���Ҳ����� Str �ڱ����е�һ�γ��ֵ�λ��
	const char* c_str();							// ת��Ϊ C-�ַ���
	void swap(String& Str);							// �������� Str ����
	//char & operator[](int index) throw(int);					// ����������
};

#endif

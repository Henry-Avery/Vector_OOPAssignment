// Vec.h
#ifndef VEC_H
#define VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR			// ����������ģ�壨���������뽫��Ա������ʵ��ȫд��ͷ�ļ��У�
{
public:
	VECTOR(int size=0, const T *x=NULL);	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
	VECTOR(const VECTOR &v);				// �� �������캯����ʵ��������죩
	virtual ~VECTOR();						// �� �����������麯����
	VECTOR & operator=(const VECTOR &v);	// �� ��ֵ�����������ʵ���ֵ���㣩
	T & operator[](int index) const throw(int);
					// ��������������������÷��أ�������ֵ��;�±�Խ��ʱ�����쳣
	int getsize() const;					// ��ȡ������ά����������Ա������
	void resize(int size);					// ����������ά������������ԭ�е����ݣ�

	virtual void Output(ostream &out) const = 0;// ���麯�����������������Ա����صĲ�����������ܶ�̬��
	virtual void Input(istream &in) = 0;		// ���麯�����Ա����صĲ�����������ܶ�̬��

protected:								// �ܱ����ģ��Ա�������ķ������ԣ�
	int num;									// ������ά��
	T *p;										// ָ�루��sizeof(void*)�ֽڣ���4�ֽڣ�����Դ�ڶѿռ�
};

template <typename T>
VECTOR<T>::VECTOR(int size, const T *x)	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
{
	num = (size>0) ? size : 0;
	p = NULL;
	if(num>0)
	{
		p = new T[num];
		for(int i=0; i<num; i++)
			p[i] = (x==NULL)? 0 : x[i];
	}
}

template <typename T>
VECTOR<T>::VECTOR(const VECTOR<T> &v)	// �� �������캯����ʵ��������죩
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VECTOR<T>::~VECTOR()						// �� �����������麯����
{
	num = 0;
	if(p!=NULL) delete [] p;
}

template <typename T>
VECTOR<T> & VECTOR<T>::operator=(const VECTOR<T> &v)// �� ��ֵ�����������ʵ���ֵ���㣩
{
	if(num!=v.num)
	{
		if(p!=NULL) delete [] p;
		p = new T[num=v.num];
	}
	for(int i=0; i<num; i++)
		p[i] = v.p[i];
	return *this;
}

template <typename T>
T & VECTOR<T>::operator[](int index) const throw(int)// ��������������������÷��أ�������ֵ��
{
	if(p==NULL)
		throw 0;							// ����ӵ��쳣
	if(index<0 || index>=num)
		throw -1;
	return p[index];
}

template <typename T>
int VECTOR<T>::getsize() const				// ��ȡ������ά����������Ա������
{
	return num;
}

template <typename T>
void VECTOR<T>::resize(int size)			// ָ��������ά������������ԭ�е����ݣ�
{
	if(size<0 || size==num)
		return;
	else if(size==0)
	{
		if(p!=NULL) delete [] p;
		p = NULL;
		num = 0;
	}
	else
	{
		T *temp = p;
		p = new T[size];
		for(int i=0; i<size; i++)
			p[i] = (i<num) ? temp[i] : 0;	// ��������ԭ������
		num = size;
		delete [] temp;	
	}
}

template <typename T>
ostream & operator<<(ostream &out, const VECTOR<T> &v)	// ��������Ԫ����
{
	v.Output(out);
	return out;
}

template <typename T>
istream & operator>>(istream &in, VECTOR<T> &v)			// ��������Ԫ����
{
	v.Input(in);
	return in;
}

#endif

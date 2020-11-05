// Vec.h
#ifndef VEC_H
#define VEC_H
#include <iostream>
using namespace std;

template <typename T> class VECTOR			// 抽象向量类模板（描述）必须将成员函数的实现全写入头文件中！
{
public:
	virtual ~VECTOR();						// ③ 析构函数（虚函数）
	VECTOR & operator=(const VECTOR &v);	// ④ 赋值运算符函数（实现深赋值运算）
	T & operator[](int index) const throw(int);
					// 方括号运算符函数（引用返回，可作左值）;下表越界时抛掷异常
	virtual void resize(int size) = 0;					// 调整向量的维数（尽量保留原有的数据）

	virtual void Output(ostream &out) const = 0;// 纯虚函数（常量函数），以便重载的插入运算符享受多态性
	virtual void Input(istream &in) = 0;		// 纯虚函数，以便重载的插入运算符享受多态性

protected:								// 受保护的（以便派生类的访问属性）
	void baes_swap(VECTOR &Str);
	VECTOR(int size=0, const T *x=NULL);	// ① 构造函数（含默认的构造函数、转换构造函数）
	VECTOR(const VECTOR &Str, int pos, int n);
	VECTOR(const VECTOR &v);				// ② 拷贝构造函数（实现深拷贝构造）
//	template <typename T2> int find(T2 &Str) const;				// 查找并返回 Str 在本串中第一次出现的位置
//	template <typename T2> T2& substr(int pos, int n) const;
	int getsize() const;					// 获取向量的维数（常量成员函数）
	int num;									// 向量的维数
	T *p;										// 指针（仅sizeof(void*)字节，即4字节），资源在堆空间
};

template <typename T>
VECTOR<T>::VECTOR(int size, const T *x)	// ① 构造函数（含默认的构造函数、转换构造函数）
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
VECTOR<T>::VECTOR(const VECTOR &Str, int pos, int n)
{
	int i, m;
	m =Str.num;
	if(pos > m)
	{
		p = new T[1];
		p[0] = ' ';
		return;
	}
	if(m-pos < n) n = m-pos;
	if(n<0) n = 0;
	p = new T[n];
	for(i=0; i<n; i++)
		p[i] = Str.p[pos+i];
	num=n;
}
template <typename T>
VECTOR<T>::VECTOR(const VECTOR<T> &v)	// ② 拷贝构造函数（实现深拷贝构造）
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VECTOR<T>::~VECTOR()						// ③ 析构函数（虚函数）
{
	num = 0;
	if(p!=NULL) delete [] p;
}

template <typename T>
VECTOR<T> & VECTOR<T>::operator=(const VECTOR<T> &v)// ④ 赋值运算符函数（实现深赋值运算）
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
T & VECTOR<T>::operator[](int index) const throw(int)// 方括号运算符函数（引用返回，可作左值）
{
	if(p==NULL)
		throw 0;							// 新添加的异常
	if(index<0 || index>=num)
		throw -1;
	return p[index];
}

template <typename T>
int VECTOR<T>::getsize() const				// 获取向量的维数（常量成员函数）
{
	return num;
}

template <typename T>
void VECTOR<T>::resize(int size)			// 指定向量的维数（尽量保留原有的数据）
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
			p[i] = (i<num) ? temp[i] : 0;	// 尽量保留原有数据
		num = size;
		delete [] temp;	
	}
}

template <typename T>
ostream & operator<<(ostream &out, const VECTOR<T> &v)	// 不必是友元函数
{
	v.Output(out);
	return out;
}

template <typename T>
istream & operator>>(istream &in, VECTOR<T> &v)			// 不必是友元函数
{
	v.Input(in);
	return in;
}

/*template <typename T> 
template <typename T2>
int VECTOR<T>::find(T2 &Str) const
{
	int i, j, m, n, flag;
	m = getsize(Str.p);
	if (m > num) return -1;
	for (i = 0; i < num - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (p[i + j] != Str.p[j])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
			return i;
	}
	return -1;
}*/

template <typename T> 
void VECTOR<T>::baes_swap(VECTOR<T> &Str)
{
	T *temp = Str.p;
	Str.p = p;
	p = temp;

	int aaa=num;
	num=Str.num;
	Str.num=aaa;
}


#endif

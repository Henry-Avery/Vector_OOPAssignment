// test.cpp			无须修改
#include "Vector.h"
#include "MyString.h"
#include <fstream>
#include <conio.h>
using namespace std;

int testVector(), testString(), test();

int main()
{
	int choice=1;
	while(choice)
	{
		system("cls");
		cout << "\n1 --- testing Vector          [v]"
			 << "\n2 --- testing String          [s]"
			 << "\n3 --- testing Vector & String [m]"
			 << "\n0 --- exit                    [q]"
			 << endl;
		choice = getch();
		switch(choice)
		{
		case '1':
		case 'v':
		case 'V':	testVector();system("pause");break;
		case '2':
		case 's':
		case 'S':	testString();system("pause");break;
		case '3':
		case 'm':
		case 'M':	test();system("pause");break;
		case '0':
		case 'q':
		case 'Q':
		case 27:	choice = 0;break;
		}
	}
	return 0;
}

int test()
{
	Vector<int> v;
	String str;

	cout << "请输入一个整数向量。如 (1, 3, 5, 7)" << endl;
	cin >> v;
	cout << v << endl;
	cin.sync();			// 刷新输入流缓冲区（目的是读取并丢弃向量后的换行符）
	cout << "请输入一个字符串。如 abc 12345   xyz" << endl;//不要换行输入
	cin >> str;						// 并非读取整行
//	getline(cin, str, 80);			// 读取整行
	cout << str << endl;

	cout << "\n将数据写入文件 output.txt 中..." << endl;
	ofstream outfile("output.txt");
	outfile << v << endl
			<< str << endl;
	outfile.close();

	cout << "\n调整对象维数为10，实现多态性" << endl;
	v.resize(10);
	str.resize(10);
	cout << "向量：" << v << endl
		<< "字符串：\"" << str << "\"" << endl;

	cout << "\n清除对象的数据..." << endl;
	v.resize(0);
	str.resize(0);
	cout << "向量：" << v << endl
		 << "字符串：\"" << str << "\"" << endl;

	cout << "\n从文件 output.txt 中读取的数据：" << endl;
	ifstream infile("output.txt");
	infile >> v;
//	infile >> str;				// 并非读取整行
	getline(infile, str, 100);	// 将上一行(向量)后的换行符"吃掉"
	getline(infile, str, 100);	// 读取整行
	infile.close();
	cout << "向量：" << v << endl
		 << "字符串：\"" << str << "\"" << endl;
	return 0;
}

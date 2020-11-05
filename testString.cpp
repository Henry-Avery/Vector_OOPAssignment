// testString.cpp		
#include "MyString.h"
#include <fstream>
using namespace std;


void test1();
void test2();
void test3();
void test4();

int testString()
{   int n;
    cout << "\n=========================================================" << endl;
        cout<<  "输入1：基本功能测试"       <<endl;
		cout<<  "输入2：异常处理测试"       <<endl;
		cout<<  "输入3：string,int转换测试" <<endl;
		cout<<  "输入4：文件读写测试" <<endl;
		cout<<  "输入5：退出" <<endl;
        cout << "\n=========================================================" << endl;
	while(cin>>n)
	{
		system("cls");
        cout << "\n=========================================================" << endl;
        cout<<  "输入1：基本功能测试"       <<endl;
		cout<<  "输入2：异常处理测试"       <<endl;
		cout<<  "输入3：string,int转换测试" <<endl;
		cout<<  "输入4：文件读写测试" <<endl;
		cout<<  "输入5：退出" <<endl;
        cout << "\n=========================================================" << endl;
		if (n==5) break;
		switch(n){
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
		}
	}
	return 0;
}

void test2()        //异常处理测试
{
	String str1="world.", str2, str3;
	int n;
	char c;
	
	cout << "\"" << str1 << "\"" << endl;
	cout<<"请问替换第几个字符："<<endl;
	cin>>n;
	cout<<"请问用什么字符替代："<<endl;
	cin>>c;
	
	str2 = str1;
	try{
	str2[n-1] = c;
	cout << "\"" << str2 << "\"" << endl;
	}
	catch(int)
	{
			cout<<"超过长度"<<endl;
	}
}

void test1()          //基本功能测试
{
	String str1="world.", str2;
	cout<<"构造函数测试"<<endl;
	cout <<"字符串构造str1:"<<"\"" << str1 << "\"" << endl;
	cout <<"默认构造str2:"<< "\"" << str2 << "\"" << endl;
	cout<<endl;
    
	cout<<"拷贝函数"<<endl;
    String str5(str1);
	cout << "把str2拷贝给str5，str5："<<"\"" << str5 << "\"" << endl;
	cout<<endl;
	
	cout<<"swap函数处理"<< str2<<endl;
	str2.swap(str1);
	cout << "str1和str2交换："<<endl;
	cout<<"str2:\"" << str2 << "\"" << endl;
	cout<<"str1:\"" << str1 << "\"" << endl;
	cout<<endl;
	
	str1="world.";
	cout<<"str1改为："<<str1<<endl;
	cout<<"insert函数测试"<<endl;
	str1="world.";
	str1.insert(0,"hello ");
	cout << "把hello插入str1前：\"" << str1 << "\"" << endl;
	cout<<endl;

	cout<<"substr函数测试"<<endl;
	cout<<"str1变为第三位后取两位："<<str1.substr(2,2)<<endl;
	cout<<endl;
	
	cout<<"find函数测试:查找str1中o的位置"<<endl;
	String o="o";
	cout<<"o在第"<<str1.find(o)<<"个位置"<<endl;
	cout<<endl;
	
	cout<<"length函数测试"<<endl;
	cout<<"str1的长度为"<<str1.length()<<endl;
	cout<<endl;
	
	cout<<"c_str函数测试"<<endl;
	cout<<"str1转换为c字符串"<<str1.c_str()<<endl;
	cout<<endl;
	
	cout << "\"" << str1 << "\"" << endl;
	cout<<"getline函数测试："<<endl;
	cout << "Input a string: "<<endl;
	fflush(stdin);       //cin.sync();
	getline(cin,str1,80);
	//cout<<str1<<endl;
	cout << "\"" << str1 << "\"" << endl;
	
	//getline(cin,str1,4);
	//cout << "\"" << str1 << "\"" << endl;
	getchar();
}

void test3()    //提取数字
{
	int pos,n,k;
	String str1;
	cout<<"键入句子："<<endl;
	cin>>str1;
	cout<<"键入位置："<<endl;
	cin>>pos;
	cout<<"键入位数："<<endl;
	cin>>n;
	try{
		k=str1.stoi(pos,n);
		cout<<"String类转int型："<<k<<endl;
	}
	catch(int)
	{
		cout<<"没找到数字，再试试"<<endl;
	}
	cout<<endl;
	cout<< "整型123转String类:"<< itos(123)<<endl;
}

void test4()
{
	String str1 = "Hello", str2 = str1, str3;
			// 转换构造		拷贝构造 	默认构造
	cout << "原始数据（双引号是另外添加的）：" << endl;
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
	str3 = str2;				// 赋值运算
	str1 = "C++ program.";
	str2 = str3 + ", world!";	// 拼接运算
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n将数据写入文件 string.txt 中..." << endl;
	ofstream outfile("string.txt");
	outfile << str1 << '\n'
			<< str2 << '\n'
			<< str3 << endl;
	outfile.close();

	cout << "\n清除对象的数据（即调整长度到0）..." << endl;
	str1.resize(0);
	str2.resize(0);
	str3.resize(0);
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n从文件 string.txt 中读取的数据：" << endl;
	ifstream infile("string.txt");
//	infile >> str1 >> str2 >> str3;		// 以空白字符作为数据项的分隔符
	getline(infile, str1, 100);			// 读整行（可含空白字符）
	getline(infile, str2, 100);
	getline(infile, str3, 100);
	infile.close();
	cout << "str1 = \"" << str1
		 << "\"\nstr2 = \"" << str2
		 << "\"\nstr3 = \"" << str3 << "\"" << endl;
	
}
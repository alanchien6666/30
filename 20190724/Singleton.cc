 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 11:32:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//要求: 定义一个类，只能由该类创建唯一的一个对象
//1. 该对象不能是栈（全局）对象
//2. 只能将该对象放在堆上


//应用场景:
//1. 可以用单例模式替换掉全局变量(全局变量多了以后，管理比较困难)
//2. 配置文件中的存储都是程序的输入信息
//3. 词典库， 网页库

class Singleton
//class Dictionary
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance) {
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	//Point _pt;
	//Computer _pc;
	//vector<string> _dict;

	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

//Singleton s3;//error
 
int main(void)
{
	//Singleton s1;//error 不能让该语句编译通过
	//Singleton s2;//error
 
	//Singleton * p1 = new Singleton();
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;

	//delete p1;//error
	Singleton::destroy();

	return 0;
}

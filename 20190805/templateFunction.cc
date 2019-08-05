 ///
 /// @file    templateFunction.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-05 11:03:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//		  实例化
//函数模板 ==> 模板函数    
//		模板参数推导  ==> 代码生成器

template <class T>
T add(T x, T y);//函数模板的声明

//函数模板之间也是可以重载的
template <class T>
T add(T x, T y, T z)
{
	return x + y + z;
}


//模板函数
//
//
//普通函数与函数模板是可以进行重载的
//而且普通函数的执行要优先于函数模板
//
#if 1
int add(int x, int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}
#endif
 
int main(void)
{
	int d1 = 1, d2 = 2;
	double d3 = 1.1, d4 = 2.2;
	char d5 = 'a', d6 = 1;
	cout << "add(d1, d2) = " << add(d1, d2) << endl;//隐式实例化
	cout << "add(d3, d4) = " << add<double>(d3, d4) << endl;//显式实例化
	cout << "add(d5, d6) = " << add(d5, d6) << endl;

	int d7 = 3;
	cout << "add(d1, d2, d7) = " << add(d1, d2, d7) << endl;
 

	return 0;
}

template <class T>
T add(T x, T y) //函数模板的实现
{
	cout << "T add(T x, T y) " << endl;
	return x + y;
}

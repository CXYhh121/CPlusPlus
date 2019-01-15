//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using std::cout;
////1、C++的关键字
////2、命名空间namespace
////命名空间的作用就是为了对标识符进行隔离，避免相同的名字产生冲突
//namespace N1//N1是命名空间的名称
//{
//	//命名空间的内容既可定义变量也可定义函数
//	int a = 2;
//	int ADD(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//namespace N2
//{
//	int a = 3;
//	int b = 5;
//
//	int ADD(int x, int y)
//	{
//		return x + y;
//	}
//	namespace N3 //命名空间可嵌套使用
//	{
//		int a = 5;
//		int b = 7;
//
//		void Swap(int *pa, int *pb)
//		{
//			int tmp = *pa;
//			*pa = *pb;
//			*pb = tmp;
//		}
//	}
//}
//一个命名空间就定义了一个新的作用域，命名空间中所有内容都只局限于该命名空间
//
//
//命名空间使用
//1、加命名空间名称和作用域限定符::
//int main()
//{
//	int a = 3;
//	int b = 4;
//	printf("%d\n", N1::a);//输出2,输出的是命名空间N1中的a
//	printf("%d\n", N2::a);//输出3，输出的是命名空间N2中的a
//	printf("%d\n", N2::N3::a);//输出5，输出的是命名空间N3中的a
//
//	N1::ADD(2, 3);
//	N2::N3::Swap(&a, &b);
//  return 0;
//}
//2、使用using将命名空间中的成员引入
//using N1::ADD;
//int main()
//{
//	int c = ADD(3, 4);
//	printf("%d\n", c);
//  return 0;
//}
//3、使用using namespace 将命名空间引入
//using namespace N2;
//
//int main()
//{
//	printf("%d\n", a);//输出N2中a的值3
//  return 0;
//}
//
//
//3、C++的输入与输出
//#include<iostream>
////using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;//换行
//int main()
//{
//	int a;
//	double b;
//	cin >> a >> b;//从键盘中输入a = 2,b = 3.14
//	cout << a << endl;//输出到控制台a，b的值
//	cout << b << endl;
//  return 0;
//}
//
//4、缺省参数
//在声明或是定义函数时为函数的参数指定一个默认值，在调用函数时若是没有传参则采用该默认值，否则使用实参
//#include<iostream>
//using namespace std;
//
////全缺省参数
//void Test(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
////半缺省参数,调用该函数时必须给a传参
////1、半缺省参数必须从右往左依次缺省，不能间隔着给
////2、缺省参数不能在函数定义和声明中同时出现，若同时出现且缺省值不同，系统无法判断使用哪一个
//void Test1(int a, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	Test();//输出10,20,30
//	Test(1);//输出1,20,30
//	Test(1,2);//输出1,2,30
//	Test(1,2,3);//输出1,2,3
//
//	Test1(1);
//	Test1(1,2);
//	Test1(1,2,3);
//
//	return 0;
//}
//
//5、函数重载
//在同一个作用域中声明几个功能类似的同名函数，这些函数的形参列表(参数个数 或 类型 或 顺序)必须不同
//#include <iostream>
//using namespace std;
//
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//double ADD(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int c = ADD(3, 4);
//	double d = ADD(3.14, 2.34);
//
//	cout << c << endl << d << endl;
//	return 0;
//}
//
//程序运行需经历的过程
//1、预处理：展开头文件，宏替换，条件编译，去掉注释，Linux下将文件处理为main.i
//2、编译：检查语法错误，生成汇编代码 Linux下将文件处理为main.s
//3、汇编：把汇编代码转换为二进制机器码 Linux下将文件处理为main.o
//4、链接：将各个处理好的文件链接到一起，生成可执行程序 Windows下处理为xxx.exe,Linux下处理为a.out
//
//名字修饰(name Mangling),指在编译过程，将函数、变量的名称重新改编，生成全局中唯一的名称，便以区分各个函数和变量
//C语言中名字修饰的方法十分简单，只是在函数名字前添加下划线，eg：_ADD,因此C语言不允许函数重载
//C++中修饰函数名包含函数的名字和参数类型以及函数返回值类型，eg:int_cdecl ADD(int,int) (?ADD@@YAHHH@Z)
//因此即便函数名相同，只要参数列表不同，在通过编译器重新修饰之后，函数名在底层全局也是唯一的,这也是C++允许函数重载的原因
//
//
//为了支持C语言调用C++模块中用C语言规则写的函数，于是在函数前加extern "C"，
//告诉编译器将该函数按照C语言规则来编译
//extern "C" int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	ADD(3, 4);
//	return 0;
//}
//
//6、引用，不是重新定义一个变量，而是给已经定义了的变量取一个新的名字，即别名
//此时编译器不会为引用变量开辟新的内存空间，引用变量和其引用的变量共用同一个内存空间
//类型& 引用变量名(对象名) = 引用实体
//#include <iostream>
//using namespace std;
//
//void TestRef()
//{
//	int a = 10;
//	int& b = a;//定义引用类型,引用类型必须和引用实体是一个类型的
//
//	printf("%p\n", a);//0000000A
//	printf("%p\n", b);//0000000A
//}
//
//int main()
//{
//	TestRef();
//	return 0;
//}
//
//6.2引用特性
//1、引用在定义时必须初始化，否则无法得知是在引用哪个变量
//2、一个变量可以有多个引用，就如一个人可有多个名字
//3、引用一旦引用了一个实体就不能引用其他实体
//
//6.3常引用
//
//void TestConstRef()
//{
//	const int a = 10;
//	//int& b = a; 此声明引用类型是错误的
//	const int& b = a;
//
//	double c = 3.14;
//	double& d = c;
//
//	const int& e = c;//此类声明可行，因为在类型转换时中间会产生临时变量，
//	//该临时变量是不可改变的常量,此时引用必须加上const
//}
//
//6.4使用场景
//1、做参数
//void Swap(int& x, int& y)//此时参数x，y是分别实参a，b的别名，x和a表示的是同一个内存空间，y和b表示的是同一个内存空间交换x，y即交换a，b
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//
//	return 0;
//}
////2、做返回值
//int TestReturn(int a)
//{
//	a += 10;
//	return a;//此时不会用a返回，因为a是局部变量，出了TestReturn函数之后就会被销毁,
//	//其栈上的空间也会还给系统,因此不能用栈上的空间作为返回值
//	//返回a的值是在执行TestReturn函数时就在main函数的栈帧中为a创建一个临时空间存储a的值，
//	//TestReturn函数执行完后，再将临时空间中的值赋值给y
//}
////使用引用做参数，返回值得生命周期不受函数的限制
//int& TestReturn1(int& a)
//{
//	a += 20;
//	return a;
//}
//int main()
//{
//	int x = 10;
//	int y = TestReturn(x);
//	return 0;
//}
//
//6.5 传值、传引用、传指针的效率比较
//传值效率最低，因为需要开辟临时空间，才能接受所传递的值
//传引用、传指针效率几乎相同，都不需要重新开辟空间
//
//6.6 引用和指针的区别
//1、引用在定义时必须初始化，指针不需要
//2、引用在初始化时引用一个实体后，就不能引用其他实体，指针可以在任何时候指向任意一个同类型的实体
//3、没有NULL引用，有NULL指针
//4、在sizeof中的含义不一样：引用的结果是引用实体类型的大小，指针始终是地址空间所占字节个数，
//指针的大小与编译器配置的程序位数有关，32位下指针是4个字节，64位下指针是8个字节
//5、引用自加即引用实体自加，指针自加即指针向后偏移一个类型的大小
//6、有多级指针，没有多级引用
//7、访问实体的方式不同，指针需要显示解引用，引用编译器字节处理
//8、引用比指针使用起来更安全，指针会出现野指针的情况
//
//7、内联函数(inline),使用时编译器会把inline标注的函数在调用内联函数处展开，没有函数压栈开销，是以空间换时间的做法
//但是代码很长或者有循环/递归的函数不适合做内联函数
//inline对于编译器只是一个建议，编译器会自动优化，如果内联函数代码很长或者有循环/递归，编译器优化时会忽略内联函数
//inline不建议声明与定义分离，会导致链接错误，因为在展开inline函数时找不到函数体，没有函数地址，链接找不到
//
//宏函数
//ADD的宏函数
//#define int ADD(int a,int b) return a+b
//#define ADD(a,b) a+b
//#define ADD(a,b) ((a)+(b))
//
////Swap的宏函数
//#define Swap(x,y)\
//	(x) = (x)+(y); \
//	(y) = (x)-(y); \
//	(x) = (x)-(y)
//
//int main()
//{
//	int c = ADD(2, 3);//预处理时替换为 int c = ((2)+(3));
//	int d = ADD(2 + 3, 4) * 3;// 预处理时替换为 int d = ((2+3)+(4))*3;
//
//	Swap(c, d);
//	cout << c << endl;
//	cout << d << endl;
//
//	return 0;
//}
//
//8、关键字auto，auto声明变量必须由编译器在编译时期推导而得
//
//int TestAuto()
//{
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	//auto e;无法通过编译，使用auto定义变量时必须初始化
//	cout << typeid(b).name() << endl;//int
//	cout << typeid(c).name() << endl;//char
//	cout << typeid(d).name() << endl;//int
//	
//	return 0;
//
//}
//
//8.1auto的使用细则
//1、auto与指针和引用结合起来使用
//
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;//int*
//	cout << typeid(b).name() << endl;//int*
//	cout << typeid(c).name() << endl;//int
//
//	*a = 20;
//	*b = 30;
//	 c = 40;
//
//	 return 0;
//}
//2、在同一行定义多个变量，变量类型必须是相同的类型，否则编译器会报错，
//因为编译器只对第一个变量的类型进行推导,然后用推导出来的类型定义其他变量
//
//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0;//编译失败，因为c和d初始化的表达式类型不同
//}
//auto不能推导的场景
//1、不能作为函数的参数，因为函数只有在被调用时才会接收到
//void TestAuto(auto a)
//{}
//值，在此之前编译器无法对a的实际类型进行推导
//2、auto不能直接声明数组
//void TestAuto()
//{
//	int a[] = { 1, 2, 3 };
//	auto b[3] = a;
//}
//
//9、基于范围for循环
//9.1范围for的语法
//void TestFor1()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6 };
//
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		array[i] *= 2;
//	}
//	for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
//	{
//		printf("%d ", array[i]);
//	}
//}
//
//void TestFor2()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6 };
//
//	for (auto& e : array)
//		e *= 2;
//	for (auto& e : array)
//		cout << e << " ";
//}
//
//int main()
//{
//	TestFor1();
//	TestFor2();
//
//	return 0;
//}
//
//范围for的使用条件：for循环的迭代范围必须是确定的
//void TestFor(int array[])
//{
//	for (auto& e : array)//for循环范围不确定
//		cout << e << " ";
//}
//
//10、指针空值nullptr，表示指针指向空时相当于 *ptr = NULL
//nullptr的类型是nullptr_t
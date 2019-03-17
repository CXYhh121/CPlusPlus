#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include "Book.h"

#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;

void SetScreenGrid();//设置屏幕显示的行数和列数
void ClearScreen();//清除屏幕信息
void SetSysCaption(const char *pText);//设置窗体标题栏
void ShowWelcome();//显示欢迎信息
void ShowRootMenu();//显示开始菜单
void WaitView(int iCurPage);//浏览数据时等待用户操作
void WaitUser();//等待用户操作
void GuideInput();//使用向导添加图书信息
int GetSelect();//获得用户菜单选择
long GetFileLength(ifstream &ifs);//获取文件长度
//void SeekBookFromFile();//查找一本图书的信息
void ViewData(int iSelPage);//浏览所有图书记录
void DeleteBookFromFile();//在文件中产生图书信息
void mainloop();//主循环
void main()
{

	SetScreenGrid();
	SetSysCaption("图书管理系统");
	mainloop();
}

void SetScreenGrid() {
	char sysSetBuf[80];
	sprintf(sysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(sysSetBuf);
}
void SetSysCaption()
{
	system("title Sample");
}
void SetSysCaption(const char *pText)
{
	char sysSetBuf[80];
	sprintf(sysSetBuf, "title %s", pText);
	system(sysSetBuf);
}

void ClearScreen() {
	system("cls");
}

void ShowWelcome() {
	for (int i = 0; i < 7; i++) {
		cout << endl;
	}
	cout << setw(40);
	cout << "\t*********************************************" << endl;
	cout << setw(40);
	cout << "\t*****************图书管理系统****************" << endl;
	cout << setw(40);
	cout << "\t*********************************************" << endl;
}

void ShowRootMenu() {
	cout << setw(25);
	cout << "请选择功能" << endl;
	cout << endl;
	cout << setw(35);
	cout << "1、添加一本新书的信息" << endl;
	cout << endl;
	cout << setw(35);
	cout << "2、浏览全部图书的信息" << endl;
	cout << endl;
	cout << setw(35);
	cout << "3、查询一本图书的信息" << endl;
	cout << endl;
	cout << setw(35);
	cout << "4、删除一本图书的信息" << endl;
	cout << endl; 
}

void WaitUser() {
	int iInputPage = 0;
	cout << "enter 返回主菜单 q退出" << endl;
	char buf[256];
	gets_s(buf);
	if (buf[0] == 'q')
		system("exit");
}

void mainloop(){
	ShowWelcome();
	while (1) {
		ClearScreen();
		ShowWelcome();
		ShowRootMenu();
		switch (GetSelect()) {
		case 1:
			ClearScreen();
			GuideInput();
			break;
		case 2:
			ClearScreen();
			ViewData(1);
			break;
		case 3:
			ClearScreen();
			int id;
			cout << "please input bookId:" << endl;
			cin >> id;
			cout << "Do not find this book"<<endl;
			cin >> id;
			cout << "hello" << endl;
			break;
		case 4:
			ClearScreen();
			DeleteBookFromFile();
			int i;
			cin >> i;
			break;
		}
	}
}

int GetSelect() {
	char buf[256];
	gets_s(buf);
	return atoi(buf);
}

void GuideInput() {
	char inName[NUM1];
	char inIsbn[NUM1];
	char inPrice[NUM2];
	char inAuthor[NUM2];

	cout << "输入书名" << endl;
	cin >> inName;
	cout << "输入Isbn" << endl;
	cin >> inIsbn;
	cout << "输入价格" << endl;
	cin >> inPrice;
	cout << "输入作者" << endl;
	cin >> inAuthor;
	CBook book(inName, inIsbn, inPrice, inAuthor);
	book.WriteData();
	cout << "Write Finish" << endl;
	WaitUser();
}
void ViewData(int iSelPage = 1)//浏览图书
{
	int iPage = 0;//总页数
	int iCurPage = 0;//当前页数
	int iDataCount = 0;//总书数
	char inName[NUM1];
	char inIsbn[NUM1];
	char inPrice[NUM2];
	char inAuthor[NUM2];
	bool bIndex = false;
	int iFileLength;
	iCurPage = iSelPage;
	ifstream ifile;
	ifile.open("book.dat", ios::binary);
	iFileLength = GetFileLength(ifile);
	iDataCount = iFileLength / (NUM1 + NUM1 + NUM2 + NUM2);//根据文件长度，计算文件中总记录数
	if (iDataCount >= 1)
		bIndex = true;
	iPage = iDataCount / 20 + 1;
	ClearScreen();//清除屏幕信息
	cout << "共有记录" << iDataCount << " ";
	cout << "共有页数" << iPage << " ";
	cout << "当前页数" << iCurPage << " ";
	cout << "n 显示下一页 m 返回" << endl;
	cout << setw(3) << "Index";
	cout << setw(20) << "Name" << setw(24) << "Isbn";
	cout << setw(15) << "Price" << setw(13) << "Author";
	cout << endl;
	try {
		//根据图书记录编号查找在文件中的位置
		ifile.seekg((iCurPage - 1) * 20 * (NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//偏移量=页数*基本量，从文件头开始
		if (!ifile.fail()) {
			for (int i = 1; i < 21; i++) {
				memset(inName, 0, 128);//清零
				memset(inIsbn, 0, 128);
				memset(inPrice, 0, 50);
				memset(inAuthor, 0, 50);
				if (bIndex) {//找到了书
					cout << setw(3) << ((iCurPage - 1) * 20 + i);//多输出了一个索引
					ifile.read(inName, NUM1);
					cout << setw(24) << inName;
					ifile.read(inIsbn, NUM1);
					cout << setw(24) << inIsbn;
					ifile.read(inPrice, NUM2);
					cout << setw(12) << inPrice;//闪退原因是将这里的12误写成了24.。。。。。。
					ifile.read(inAuthor, NUM2);
					cout << setw(12) << inAuthor;
					cout << endl;
				}
				if (ifile.tellg() < 0)
					bIndex = false;
				else
					bIndex = true;
			}
		}
	}
	catch (...) {
		cout << "throw file exception" << endl;
		throw "file error occurred";//抛出异常
		ifile.close();
	}
	if (iCurPage < iPage) {
		iCurPage = iCurPage + 1;
		WaitView(iCurPage);//等待用户处理
	}
	else {
		WaitView(iCurPage);
	}
	ifile.close();
}
long GetFileLength(ifstream &ifs) {
	long temppos;
	long respos;
	temppos = ifs.tellg();
	ifs.seekg(0, ios::end);
	respos = ifs.tellg();
	ifs.seekg(temppos, ios::beg);
	return respos;
}

//void SeekBookFromFile()//查找一本图书的信息
//{
//	int bookId;
//	cout << "Input seekbook index" << endl;
//	cin >> bookId;
//
//	CBook tmpbook;
//	if (tmpbook.GetIsbn == (char*)bookId)
//		cout << "bookname:" << tmpbook.GetName() <<
//		"bookId:" << tmpbook.GetIsbn() <<
//		"bookPrice:" << tmpbook.GetPrice() <<
//		"bookAuthor:" << tmpbook.GetAuthor() << endl;
//	else
//		cout << "Do not find this book!" << endl;
//
//}
void DeleteBookFromFile() {//
	int iDelCount;
	cout << "Input delete index" << endl;
	cin >> iDelCount;
	CBook tmpbook;
	tmpbook.DeleteData(iDelCount);
	cout << "Delete Finish" << endl;
	WaitUser();
}
void WaitView(int iCurPage)
{
	char buf[256];
	gets_s(buf);
	if (buf[0] == 'q')
		system("exit");
	if (buf[0] == 'm')
		mainloop();
	if (buf[0] == 'n')
		ViewData(iCurPage);
}

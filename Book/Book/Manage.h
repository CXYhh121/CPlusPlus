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

class Manage:public CBook
{
public:
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
	void ViewData(int iSelPage);//浏览所有图书记录
	void DeleteBookFromFile();//在文件中产生图书信息
	void mainloop();//主循环
};



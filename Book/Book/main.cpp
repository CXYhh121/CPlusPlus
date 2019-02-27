#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include "Book.h"
#include "Manage.h"

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
void ViewData(int iSelPage);//浏览所有图书记录
void DeleteBookFromFile();//在文件中产生图书信息
void mainloop();//主循环

int main()
{
	SetScreenGrid();
	SetSysCaption("图书管理系统");
	mainloop();
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
			DeleteBookFromFile();
			break;
		}
	}
}

void SetScreenGrid() {
	char sysSetBuf[80];
	sprintf(sysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(sysSetBuf);
}
void SetSysCaption(const char *pText)
{
	char sysSetBuf[80];
	sprintf(sysSetBuf, "title %s", pText);
	system(sysSetBuf);
}
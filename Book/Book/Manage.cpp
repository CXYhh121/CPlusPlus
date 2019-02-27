#define _CRT_SECURE_NO_WARNINGS
#include "Manage.h"


void Manage::WaitUser() {
	int iInputPage = 0;
	cout << "enter 返回主菜单 q退出" << endl;
	char buf[256];
	gets_s(buf);
	if (buf[0] == 'q')
		system("exit");
}

void Manage::ClearScreen() {
	system("cls");
}
//
//void Manage::SetSysCaption(const char *pText)
//{
//	system("title Sample");
//}
void Manage::SetScreenGrid() {
	char sysSetBuf[80];
	sprintf(sysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(sysSetBuf);
}
void Manage::SetSysCaption(const char *pText)
{
	char sysSetBuf[80];
	sprintf(sysSetBuf, "title %s", pText);
	system(sysSetBuf);
}

//void Manage::ClearScreen() {
//	system("cls");
//}

void Manage::ShowWelcome() {
	for (int i = 0; i < 7; i++) {
		cout << endl;
	}
	cout << setw(40);
	cout << "******************" << endl;
	cout << setw(40);
	cout << "***图书管理系统***" << endl;
	cout << setw(40);
	cout << "******************" << endl;
}

void Manage::ShowRootMenu() {
	cout << setw(35);
	cout << "请选择功能" << endl;
	cout << endl;
	cout << setw(35);
	cout << "1 添加新书" << endl;
	cout << endl;
	cout << setw(35);
	cout << "2 浏览全部" << endl;
	cout << endl;
	cout << setw(35);
	cout << "3 删除图书" << endl;
	cout << endl;
}


int Manage::GetSelect() {
	char buf[256];
	gets_s(buf);
	return atoi(buf);
}

void Manage::mainloop(){
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


void Manage::GuideInput() {
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
void Manage::ViewData(int iSelPage = 1)//浏览图书
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
long Manage::GetFileLength(ifstream &ifs) {
	long temppos;
	long respos;
	temppos = ifs.tellg();
	ifs.seekg(0, ios::end);
	respos = ifs.tellg();
	ifs.seekg(temppos, ios::beg);
	return respos;
}
void Manage::DeleteBookFromFile() {//
	int iDelCount;
	cout << "Input delete index" << endl;
	cin >> iDelCount;
	CBook tmpbook;
	tmpbook.DeleteData(iDelCount);
	cout << "Delete Finish" << endl;
	WaitUser();
}
void Manage::WaitView(int iCurPage)
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
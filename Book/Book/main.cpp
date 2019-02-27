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

void SetScreenGrid();//������Ļ��ʾ������������
void ClearScreen();//�����Ļ��Ϣ
void SetSysCaption(const char *pText);//���ô��������
void ShowWelcome();//��ʾ��ӭ��Ϣ
void ShowRootMenu();//��ʾ��ʼ�˵�
void WaitView(int iCurPage);//�������ʱ�ȴ��û�����
void WaitUser();//�ȴ��û�����
void GuideInput();//ʹ�������ͼ����Ϣ
int GetSelect();//����û��˵�ѡ��
long GetFileLength(ifstream &ifs);//��ȡ�ļ�����
void ViewData(int iSelPage);//�������ͼ���¼
void DeleteBookFromFile();//���ļ��в���ͼ����Ϣ
void mainloop();//��ѭ��

int main()
{
	SetScreenGrid();
	SetSysCaption("ͼ�����ϵͳ");
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
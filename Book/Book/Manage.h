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
};



#define _CRT_SECURE_NO_WARNINGS
#include "Manage.h"


void Manage::WaitUser() {
	int iInputPage = 0;
	cout << "enter �������˵� q�˳�" << endl;
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
	cout << "***ͼ�����ϵͳ***" << endl;
	cout << setw(40);
	cout << "******************" << endl;
}

void Manage::ShowRootMenu() {
	cout << setw(35);
	cout << "��ѡ����" << endl;
	cout << endl;
	cout << setw(35);
	cout << "1 ��������" << endl;
	cout << endl;
	cout << setw(35);
	cout << "2 ���ȫ��" << endl;
	cout << endl;
	cout << setw(35);
	cout << "3 ɾ��ͼ��" << endl;
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

	cout << "��������" << endl;
	cin >> inName;
	cout << "����Isbn" << endl;
	cin >> inIsbn;
	cout << "����۸�" << endl;
	cin >> inPrice;
	cout << "��������" << endl;
	cin >> inAuthor;
	CBook book(inName, inIsbn, inPrice, inAuthor);
	book.WriteData();
	cout << "Write Finish" << endl;
	WaitUser();
}
void Manage::ViewData(int iSelPage = 1)//���ͼ��
{
	int iPage = 0;//��ҳ��
	int iCurPage = 0;//��ǰҳ��
	int iDataCount = 0;//������
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
	iDataCount = iFileLength / (NUM1 + NUM1 + NUM2 + NUM2);//�����ļ����ȣ������ļ����ܼ�¼��
	if (iDataCount >= 1)
		bIndex = true;
	iPage = iDataCount / 20 + 1;
	ClearScreen();//�����Ļ��Ϣ
	cout << "���м�¼" << iDataCount << " ";
	cout << "����ҳ��" << iPage << " ";
	cout << "��ǰҳ��" << iCurPage << " ";
	cout << "n ��ʾ��һҳ m ����" << endl;
	cout << setw(3) << "Index";
	cout << setw(20) << "Name" << setw(24) << "Isbn";
	cout << setw(15) << "Price" << setw(13) << "Author";
	cout << endl;
	try {
		//����ͼ���¼��Ų������ļ��е�λ��
		ifile.seekg((iCurPage - 1) * 20 * (NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//ƫ����=ҳ��*�����������ļ�ͷ��ʼ
		if (!ifile.fail()) {
			for (int i = 1; i < 21; i++) {
				memset(inName, 0, 128);//����
				memset(inIsbn, 0, 128);
				memset(inPrice, 0, 50);
				memset(inAuthor, 0, 50);
				if (bIndex) {//�ҵ�����
					cout << setw(3) << ((iCurPage - 1) * 20 + i);//�������һ������
					ifile.read(inName, NUM1);
					cout << setw(24) << inName;
					ifile.read(inIsbn, NUM1);
					cout << setw(24) << inIsbn;
					ifile.read(inPrice, NUM2);
					cout << setw(12) << inPrice;//����ԭ���ǽ������12��д����24.������������
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
		throw "file error occurred";//�׳��쳣
		ifile.close();
	}
	if (iCurPage < iPage) {
		iCurPage = iCurPage + 1;
		WaitView(iCurPage);//�ȴ��û�����
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
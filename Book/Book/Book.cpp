#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
CBook::CBook(char* cName, char* cIsbn, char* cPrice, char* cAuthor) {
	strncpy(m_cName, cName, NUM1);
	strncpy(m_cIsbn, cIsbn, NUM1);
	strncpy(m_cPrice, cPrice, NUM2);
	strncpy(m_cAuthor, cAuthor, NUM2);
}
char* CBook::GetName() {
	return m_cName;
}
void CBook::SetName(char* cName) {
	strncpy(m_cName, cName, NUM1);
}
char* CBook::GetIsbn() {
	return m_cIsbn;
}
void CBook::SetIsbn(char* cIsbn) {
	strncpy(m_cName, cIsbn, NUM1);
}
char* CBook::GetPrice() {
	return m_cPrice;
}
void CBook::SetPrice(char* cPrice) {
	strncpy(m_cPrice, cPrice, NUM2);
}
char* CBook::GetAuthor() {
	return m_cAuthor;
}
void CBook::SetAuthor(char* cAuthor) {
	strncpy(m_cAuthor, cAuthor, NUM2);
}
//����WriteDate,GetBookFromFile,DeleteData��������д�ļ��ĺ������൱�ڲ������ݿ�Ľӿ�
void CBook::WriteData() {
	ofstream ofile;
	ofile.open("book.dat", ios::binary | ios::app);//�Զ����Ƹ�ʽ(binary)��book.dat, app:ÿ��д����ǰ����λ���ļ�ĩβ
	try {
		ofile.write(m_cName, NUM1);//д��ͼ�����Ϣ
		ofile.write(m_cIsbn, NUM1);
		ofile.write(m_cPrice, NUM2);
		ofile.write(m_cAuthor, NUM2);
	}
	catch (...) {//catch(��)�ܹ���������������͵��쳣����
		throw "file error occurred";
		ofile.close();
	}
	ofile.close();
}
//��Ա����DeleteData����ͼ����Ϣ���ļ���ɾ��
void CBook::DeleteData(int iCount) {//ɾ����iCount����¼
	long respos;
	int iDataCount = 0;
	/*ͷ�ļ�fstarem������3��������֧���ļ�IO,ifstream��һ�������ļ���ȡ���ݣ�
	ofatream��һ�������ļ�д�����ݣ��Լ�fstream���Զ�д�����ļ�*/
	fstream file;
	fstream tmpfile;
	ofstream ofile;
	char cTempBuf[NUM1 + NUM1 + NUM2 + NUM2];
	file.open("book.dat", ios::binary | ios::in | ios::out);//������/��/д
	tmpfile.open("temp.dat", ios::binary | ios::out | ios::in | ios::trunc);
	/*seekg()�Ƕ������ļ���λ������������������һ��������ƫ�������ڶ��������ǻ���ַ��*/
	file.seekg(0, ios::end); //����ַΪ�ļ���������ƫ�Ƶ�ַΪ0������ָ�붨λ���ļ�������
	respos = file.tellg();//���ص�ǰ��λָ���λ�ã�Ҳ�������������Ĵ�С��
	iDataCount = respos / (NUM1 + NUM1 + NUM2 + NUM2);//�ܼ�¼��=�ļ���С/������
	if (iCount<0 || iCount>iDataCount) {
		throw "Input number error";
	}
	else {//�ӵ�iCount+1����¼��ʼ�����Ժ�ļ�¼�ȴ����м��ļ�����tmpfile����tmpfile�����ݸ��ǵ�iCount����¼֮������ݣ��൱��ɾ���˵�iCount����¼
		file.seekg((iCount)*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//����ַΪ�ļ�ͷ��ƫ����Ϊ������*iCount,����дָ��ָ���˵�iCount����¼����ʼλ��
		for (int j = 0; j < (iDataCount - iCount); j++) {//����iCount����¼��ļ�¼�ȴ���tmpfile
			memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);//��cTempBuf����
			file.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//��file�е�һ����¼����cTempBuf
			tmpfile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//��cTempBuf�е�һ����¼д��tmpfile
		}
		file.close();
		tmpfile.seekg(0, ios::beg);//��ָ�붨λ���ļ�ͷ
		ofile.open("book.dat");
		ofile.seekp((iCount - 1)*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//��ָ�붨λ����iCount-1����¼�Ľ���λ��
		for (int i = 0; i < (iDataCount - iCount); i++) {
			memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);
			tmpfile.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
			ofile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//��cTempBuf�е�һ����¼д��ofile
		}
	}
	tmpfile.close();
	ofile.close();
	remove("temp.dat");
}
//��Ա����GetBookFromFile���ļ��ж�ȡ��������������
void CBook::GetBookFromFile(int iCount) {
	char cName[NUM1];
	char cIsbn[NUM1];
	char cPrice[NUM2];
	char cAuthor[NUM2];
	ifstream ifile;
	ifile.open("book.dat", ios::binary);
	try {
		ifile.seekg(iCount*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
		ifile.read(cName, NUM1);
		if (ifile.tellg() > 0)
			strncpy(m_cName, cName, NUM1);
		ifile.read(cIsbn, NUM1);
		if (ifile.tellg() > 0)
			strncpy(m_cIsbn, cIsbn, NUM1);
		ifile.read(cPrice, NUM2);
		if (ifile.tellg() > 0)
			strncpy(m_cPrice, cPrice, NUM2);
		ifile.read(cAuthor, NUM2);
		if (ifile.tellg() > 0)
			strncpy(m_cAuthor, cAuthor, NUM2);
	}
	catch (...) {
		throw "file error occured";
		ifile.close();
	}
	ifile.close();
}
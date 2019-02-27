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
//函数WriteDate,GetBookFromFile,DeleteData是类对象对写文件的函数，相当于操作数据库的接口
void CBook::WriteData() {
	ofstream ofile;
	ofile.open("book.dat", ios::binary | ios::app);//以二进制格式(binary)打开book.dat, app:每次写操作前均定位到文件末尾
	try {
		ofile.write(m_cName, NUM1);//写入图书的信息
		ofile.write(m_cIsbn, NUM1);
		ofile.write(m_cPrice, NUM2);
		ofile.write(m_cAuthor, NUM2);
	}
	catch (...) {//catch(…)能够捕获多种数据类型的异常对象
		throw "file error occurred";
		ofile.close();
	}
	ofile.close();
}
//成员函数DeleteData负责将图书信息从文件中删除
void CBook::DeleteData(int iCount) {//删掉第iCount条记录
	long respos;
	int iDataCount = 0;
	/*头文件fstarem定义了3各类型来支持文件IO,ifstream从一个给定文件读取数据，
	ofatream向一个给定文件写入数据，以及fstream可以读写给定文件*/
	fstream file;
	fstream tmpfile;
	ofstream ofile;
	char cTempBuf[NUM1 + NUM1 + NUM2 + NUM2];
	file.open("book.dat", ios::binary | ios::in | ios::out);//二进制/读/写
	tmpfile.open("temp.dat", ios::binary | ios::out | ios::in | ios::trunc);
	/*seekg()是对输入文件定位，它有两个参数：第一个参数是偏移量，第二个参数是基地址。*/
	file.seekg(0, ios::end); //基地址为文件结束处，偏移地址为0，于是指针定位在文件结束处
	respos = file.tellg();//返回当前定位指针的位置，也代表着输入流的大小。
	iDataCount = respos / (NUM1 + NUM1 + NUM2 + NUM2);//总记录数=文件大小/基本量
	if (iCount<0 || iCount>iDataCount) {
		throw "Input number error";
	}
	else {//从第iCount+1条记录开始，将以后的记录先存至中间文件变量tmpfile，后将tmpfile的内容覆盖掉iCount条记录之后的内容，相当于删掉了第iCount条记录
		file.seekg((iCount)*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//基地址为文件头，偏移量为基本量*iCount,即读写指针指向了第iCount条记录的起始位置
		for (int j = 0; j < (iDataCount - iCount); j++) {//将第iCount条记录后的记录先存入tmpfile
			memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);//将cTempBuf清零
			file.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//将file中的一条记录读入cTempBuf
			tmpfile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//将cTempBuf中的一条记录写入tmpfile
		}
		file.close();
		tmpfile.seekg(0, ios::beg);//将指针定位在文件头
		ofile.open("book.dat");
		ofile.seekp((iCount - 1)*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);//将指针定位到第iCount-1条记录的结束位置
		for (int i = 0; i < (iDataCount - iCount); i++) {
			memset(cTempBuf, 0, NUM1 + NUM1 + NUM2 + NUM2);
			tmpfile.read(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);
			ofile.write(cTempBuf, NUM1 + NUM1 + NUM2 + NUM2);//将cTempBuf中的一条记录写入ofile
		}
	}
	tmpfile.close();
	ofile.close();
	remove("temp.dat");
}
//成员函数GetBookFromFile从文件中读取数据来构建对象
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
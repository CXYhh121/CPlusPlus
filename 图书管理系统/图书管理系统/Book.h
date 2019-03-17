#pragma once
#define NUM1 128           //ͼ�����ƺ�Isbn�����󳤶�
#define NUM2 50           //ͼ��۸�������󳤶�
class CBook {
public:
	CBook(){}             //�޲ι��췽��
	CBook(char* cName, char* cIsbn, char* cPrice, char* cAuthor);//�вι��췽��
	~CBook(){}            //��������
public:
	char* GetName();//��ȡͼ������
	void SetName(char* cName);//����ͼ������
	char* GetIsbn();//��ȡͼ��ISBN���
	void SetIsbn(char* cIsbn);//����ͼ��ISBN���
	char* GetPrice();//��ȡͼ��۸�
	void SetPrice(char* cPrice);//����ͼ��۸�
	char* GetAuthor();//��ȡͼ������
	void SetAuthor(char* cAuthor);//����ͼ������
	void WriteData();             //д������
	void DeleteData(int iCount);  //ɾ������
	void GetBookFromFile(int iCount);  //���ļ��ж�ȡͼ���¼
protected:
	char m_cName[NUM1];
	char m_cIsbn[NUM1];
	char m_cPrice[NUM2];
	char m_cAuthor[NUM2];
};
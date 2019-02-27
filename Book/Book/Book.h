#pragma once
#define NUM1 128           //图书名称和Isbn编号最大长度
#define NUM2 50           //图书价格及作者最大长度
class CBook {
public:
	CBook(){}             //无参构造方法
	CBook(char* cName, char* cIsbn, char* cPrice, char* cAuthor);//有参构造方法
	~CBook(){}            //析构函数
public:
	char* GetName();//获取图书名称
	void SetName(char* cName);//设置图书名称
	char* GetIsbn();//获取图书ISBN编号
	void SetIsbn(char* cIsbn);//设置图书ISBN编号
	char* GetPrice();//获取图书价格
	void SetPrice(char* cPrice);//设置图书价格
	char* GetAuthor();//获取图书作者
	void SetAuthor(char* cAuthor);//设置图书作者
	void WriteData();             //写入数据
	void DeleteData(int iCount);  //删除数据
	void GetBookFromFile(int iCount);  //从文件中读取图书记录
protected:
	char m_cName[NUM1];
	char m_cIsbn[NUM1];
	char m_cPrice[NUM2];
	char m_cAuthor[NUM2];
};
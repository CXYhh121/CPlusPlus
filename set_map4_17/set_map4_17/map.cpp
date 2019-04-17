#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>
using namespace std;



void Testmap()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(2, 3));
	m.insert(pair<int, int>(5, 1));
	m.insert(std::make_pair(1, 5));
	m.insert(std::make_pair(7, 5));
	m.insert(std::make_pair(9, 5));

	map<int, int> copy(m);

	map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout << mit->first << ":" << mit->second << " ";
		++mit;
	}
	cout << endl;

	for (auto e : copy)
	{
		cout << e.first << ":" << e.second << " ";
	}
	cout << endl;
}


void Testmap2()
{
	string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		//std::map<std::string, int>::iterator it = countmap.find(e);
		auto it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}

	//map<std::string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;
}
void Testmap3()
{
	string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		//pair<map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		auto ret = countmap.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

	//map<string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;
}

void Testmap4()
{
	string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		countmap[e]++;
	}

	for (const auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	//ģ��ʵ��һ��С�͵��ֵ�
	map<string, string> dict;
	dict.insert(std::make_pair("left", "���"));
	dict.insert(std::make_pair("left", "ʣ��"));
	dict["left"] = "ʣ��";
	dict["string"];
	dict["set"] = "����";
}
int main()
{
	//Testmap();
	Testmap2();
	return 0;
}
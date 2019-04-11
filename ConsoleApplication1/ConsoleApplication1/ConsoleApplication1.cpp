// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <vector>
#include <cctype> //tolower
#include <string>
#include  <iterator>
#include  <algorithm>
using namespace std;
void /*vector<string>*/ input(string str);
void updateStr(string& str);
void removeStr(string& str, int K);
void updateKey(string& str);
void print(const string& str);
int main()
{
	string str = "IDIOCY_OFTEN_LOOKS_LIKE_INTELLIGENCE";
	string key = "WHEATSTONE";
	print(key);
	//updateStr(str);
	updateKey(key);
	print(key);
	//input( str);
	return 0;
}
void /*vector<string>*/ input(string str)
{

	int size = str.size();
	std::vector<string> v;
	string tmp;
	for (int i = 0; i < size; i = i + 2)
	{

		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				tmp.push_back(str[i]);
			else
				tmp.push_back(str[i + 1]);

			cout << tmp[j];
		}
		cout << " ";

		v.push_back(tmp);
		tmp.erase();
		tmp.erase();
	}

}

void updateStr(string& str)
{
	int size = str.size();
	for (int i = 0; i < size; i = i + 2)
	{
		if (str[i] == str[i + 1])
			str.insert(i + 1, "X");
	}
	if (str.size() % 2 != 0)
		str.push_back('X');
}
void print(const string& str)
{
	cout << "-----------" << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	cout << "-----------" << endl;

}
void updateKey(string& str)
{
	int size = str.size();

	string tmp;
	
	
	//	Remove duplicate characters from string
	std::string::iterator iter = str.begin();
	std::copy_if(str.begin(), str.end(), back_inserter(tmp),
		[&](char c) { return !std::count(str.begin(), iter++, c); });
	//print(tmp);
	str = tmp;
}
void removeStr(string& str, int K)
{
	string Buff;
	for (int i = 0; i < str.size(); i++)
	{
		if (i != K)
			Buff.push_back(str[i]);
	}
	str = Buff;
}
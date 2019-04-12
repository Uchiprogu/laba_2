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
vector<string> input(string str);
void updateStr(string& str);
void removeStr(string& str, int K);
void updateKey(string& str);
void fillingKey(string& key, vector<string>& TablStr);
void print(const string& str);
string fillLetters(string key, string& tmp);


struct Index
{
	int Row;
	int Col;

	Index(int row, int col)
	{
		Row = row;
		Col = col;
	}

	Index NextRow()
	{
		int r = (Row + 1) % 5;
		return Index(r, Col);
	}

	Index NextCol()
	{
		int c = (Col + 1) % 5;
		return Index(Row, c);
	}
};

int main()
{
	string str = "IDIOCY_OFTEN_LOOKS_LIKE_INTELLIGENCE";
	string key = "WHEATSTONE";
	print(key);
	//updateStr(str);
	updateKey(key);
	//print(key);
	vector<string> Text;
	vector<string> KeyTable;
	//Text = input( str);
	fillingKey(key, KeyTable);
	return 0;
}
vector<string> input(string str)
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
	return v;
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
string fillLetters(string key, string& tmp)
{
	string tmp_2;
	bool duplicateCharacter = 0;
	int Symbol = 65;
	int sizeKey = key.size();
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < sizeKey; j++)
		{
			if (Symbol == 90)
				break;
			if (key[j] == Symbol)
			{
				duplicateCharacter = 1;
			}
		}
		if(duplicateCharacter == 0)
			tmp_2.push_back(Symbol);
		duplicateCharacter = 0;
		if (Symbol != 80)
			Symbol++;
		else
			Symbol = Symbol + 2;
	}
	tmp_2 = tmp + tmp_2;
	return tmp_2;
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
void fillingKey(string& key, vector<string>& TablStr)
{
	int SizeKey = key.size() -1;
	int remainderOfDivision = key.size() % 5;
	string tmp, tmp_2;
	int tmpSize = 0;
	bool stop = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++, SizeKey--)
		{
			if (SizeKey > -1)
			{
				if (stop == 0)
				{
					if(i == 0)
						tmp.push_back(key[j]);
					else
					{
						if(remainderOfDivision == 0)
							tmp.push_back(key[j + i*5]);
						else
						{
							tmp.push_back(key[j + i * 5]);
							//fill the rest of the letters
							tmp_2 = fillLetters(key, tmp);
							break;
							/*if (tmpSize > tmp_2.size() / 5)
								break;
							tmp.clear();
							for (int i = 0; i < 5; i++)
							{
								tmp.push_back(tmp_2[i + tmpSize * 5]);
							}*/
						}
					}
				}
					
			}
		}
		//print(tmp_2);
		TablStr.push_back(tmp);
		tmpSize++;
	}
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
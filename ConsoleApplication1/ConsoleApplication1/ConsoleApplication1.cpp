﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
//void removeStr(string& str, int K);
void updateKey(string& str);
void fillingKey(string& key, vector<string>& TablStr);
void print(const string& str);
void printInput(vector<string>& Text);
void printInputM(vector<string>& Text);
void encode(vector<string>& Text,const vector<string> key);
void dencode(vector<string>& Text, const vector<string> key);
string fillLetters(string key, string& tmp);




int main()
{
	string str = "IDIOCY OFTEN LOOKS LIKE INTELLIGENCE";

	string key;// = "WHEATSTONE";
	getline(cin, key);
	print(key);
	print(str);
	updateStr(str);
	updateKey(key);
	//print(str);
	vector<string> Text;
	vector<string> KeyTable;
	Text = input( str);
	fillingKey(key, KeyTable);

	printInputM(KeyTable);

	printInput(Text);
	cout << endl;
	encode(Text, KeyTable);
	cout << endl;
	printInput(Text);
	cout << endl;
	cout << "+++++++++++++++++++++++++";
	cout << endl;
	dencode(Text, KeyTable);
	cout << endl;
	printInput(Text);
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

			//cout << tmp[j];
		}
		//cout << " ";

		v.push_back(tmp);
		tmp.erase();
		tmp.erase();
	}
	return v;
}

void updateStr(string& str)
{
	int size = str.size();
	string tmp;
	std::string::iterator iter = str.begin();
	std::copy_if(str.begin(), str.end(), back_inserter(tmp),
		[&](char c)
	{
		return c != 32; 
	});

	str = tmp;
	size = str.size();
	//print(str);
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
void printInput(vector<string>& Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		for (int j = 0; j < Text.at(i).size(); j++)
			cout << Text.at(i)[j];
		cout << " ";
	}
}
void printInputM(vector<string>& Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		for (int j = 0; j < Text.at(i).size(); j++)
			cout << Text.at(i)[j];
		cout << endl;
	}
}
void encode(vector<string>& Text, const vector<string> key)
{
	//on one line
	//on one column
	//on different rows and columns
	int column = 0;
	int line = 0;
	int Case;
	bool stop = false;
	for (int i = 0; i < Text.size(); i++)
	{
		
		for (int j = 0; j <2; j++)
		{
			//cout << Text.at(i)[j];
			for (int k = 0; k < key.size(); k++)
			{
				for (int y = 0; y < key.size(); y++)
				{

					if (Text.at(i)[j] == key.at(k)[y])
					{
						if (j == 0)
						{
							column = y;
							line = k;
						}
						if (j == 1)
						{
							if (column == y && line != k)
								Case = 0;
							if (column != y && line == k)
								Case = 1;
							if (column != y && line != k)
								Case = 2;

							switch (Case)
							{
							//on one column
							case 0:
								if (k != 4 && line != 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k + 1)[y];
									Text.at(i)[0] = key.at(line +1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if  (line == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k + 1)[y];
									Text.at(i)[0] = key.at(0)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (k == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(0)[y];
									Text.at(i)[0] = key.at(line + 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
							//on one line
							case 1:
								if (y != 4 && column != 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[y +1];
									Text.at(i)[0] = key.at(line)[column + 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (column == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[y + 1];
									Text.at(i)[0] = key.at(line)[0];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (y == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[0];
									Text.at(i)[0] = key.at(line)[column + 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
							//on different rows and columns
							case 2:
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << "	";
								Text.at(i)[1] = key.at(line)[y];
								Text.at(i)[0] = key.at(k)[column];
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << endl;

								stop = true;
								break;
							default:
								stop = true;
								break;
							}
						}
					}
					if (stop == true)
						break;
				}
				if (stop == true)
				{
					stop = false;
					break;
				}
			}
		}
		//column = -1;
		//line = -1;
	}
}
void dencode(vector<string>& Text, const vector<string> key)
{
	//on one line
	//on one column
	//on different rows and columns
	int column = 0;
	int line = 0;
	int Case;
	bool stop = false;
	for (int i = 0; i < Text.size(); i++)
	{

		for (int j = 0; j < 2; j++)
		{
			//cout << Text.at(i)[j];
			for (int k = 0; k < key.size(); k++)
			{
				for (int y = 0; y < key.size(); y++)
				{

					if (Text.at(i)[j] == key.at(k)[y])
					{
						if (j == 0)
						{
							column = y;
							line = k;
						}
						if (j == 1)
						{
							if (column == y && line != k)
								Case = 0;
							if (column != y && line == k)
								Case = 1;
							if (column != y && line != k)
								Case = 2;

							switch (Case)
							{
								//on one column
							case 0:
								if (k != 0 && line != 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k - 1)[y];
									Text.at(i)[0] = key.at(line - 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (line == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k - 1)[y];
									Text.at(i)[0] = key.at(4)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (k == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(4)[y];
									Text.at(i)[0] = key.at(line - 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on one line
							case 1:
								if (y != 0 && column != 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[y - 1];
									Text.at(i)[0] = key.at(line)[column - 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (column == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[y - 1];
									Text.at(i)[0] = key.at(line)[4];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (y == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key.at(k)[4];
									Text.at(i)[0] = key.at(line)[column - 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on different rows and columns
							case 2:
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << " ---- ";
								Text.at(i)[1] = key.at(line)[y];
								Text.at(i)[0] = key.at(k)[column];
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << endl;

								stop = true;
								break;
							default:
								stop = true;
								break;
							}
						}
					}
					if (stop == true)
						break;
				}
				if (stop == true)
				{
					stop = false;
					break;
				}
			}
		}
		//column = -1;
		//line = -1;
	}
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
	string tmp_2;
	string tmp = key;
	//fill the rest of the letters
	tmp = fillLetters(key, tmp);
	int tmpSize = 0;
	bool stop = 0;
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 5; j++, SizeKey--)
		{
			tmp_2.push_back(tmp[j + i * 5]);
		}
		
		TablStr.push_back(tmp_2);
		//print(tmp_2);
		tmp_2.clear();
	}
	
}
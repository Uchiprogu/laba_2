
#include <iostream>
#include <vector>
#include <cctype> //tolower
#include <string>

using namespace std;
void /*vector<string>*/ input(string str);
void updateStr(string& str);
void updateKey(string& str);
void print( const string& str);
int main()
{
	string str = "IDIOCY_OFTEN_LOOKS_LIKE_INTELLIGENCE";
	string key = "WHEATSTONE";
	print(key);
	//updateStr(str);
	updateKey(key);
	//print(key);
	//input( str);
	return 0;
}
void /*vector<string>*/ input(string str)
{

	int size = str.size();
	std::vector<string> v;
	string tmp;
	for (int i = 0; i < size; i = i +2)
	{

		for (int j = 0; j < 2; j++)
		{	
			if( j == 0)
				tmp.push_back(str[i]);
			else
				tmp.push_back(str[i + 1]);

			cout<<tmp[j];
		}
		cout<<" ";
		
		v.push_back(tmp);
		tmp.erase();
		tmp.erase();
	}

}

void updateStr(string& str)
{
	int size = str.size();
	for(int i =0; i < size ; i = i + 2)
	{
		if(str[i] == str[i + 1])
			str.insert(i + 1, "X");
	}
	if(str.size()%2 != 0)
		str.push_back('X');
}
void print( const string& str)
{
	cout<< "-----------" <<endl;
	for(int i =0; i < str.size(); i++ )
	{
		cout<<str[i];
	}
	cout<<endl;
	cout<< "-----------" <<endl;

}
void updateKey(string& str)
{
	int size = str.size();
	string tmp = str;
	for(int i =0; i < size ; i = i + 2)
	{
		for(int j =0; j < size; j++)
		{
			//if(str[j] = str[i])
				
		}
	}
	tmp.erase(1,2); 
	print(tmp);
}